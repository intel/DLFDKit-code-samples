#include <iostream>
#include <stdio.h>

#include <CL/sycl.hpp>
#include "ccl.h"

#define COUNT     (10 * 1024 * 1024)
#define COLL_ROOT (0)

using namespace std;
using namespace cl::sycl;
using namespace cl::sycl::access;

inline bool has_gpu()
{
    std::vector<cl::sycl::device> devices = cl::sycl::device::get_devices();
    for (const auto& device : devices) {
        if (device.is_gpu()) {
            return true;
        }
    }
    return false;
}
inline int create_sycl_queue(int argc, char **argv, cl::sycl::queue &queue)
{
    std::unique_ptr<cl::sycl::device_selector> selector;
    if (argc == 2) {
        if (strcmp(argv[1], "cpu") == 0) {
            selector.reset(new cl::sycl::cpu_selector());
        }
        else if (strcmp(argv[1], "gpu") == 0) {
            if (has_gpu()) {
                selector.reset(new cl::sycl::gpu_selector());
            }
            else {
                selector.reset(new cl::sycl::default_selector());
                std::cout << "GPU is unavailable, default_selector has been created instead of gpu_selector." << std::endl;
            }
        }
        else {
            std::cerr << "Please provide device type: cpu | gpu\n" << std::endl;
            return -1;
        }
        queue = cl::sycl::queue(*selector);
		std::cout << "Provided device type: " << argv[1] << "\nRunning on "
				  << queue.get_device().get_info<cl::sycl::info::device::name>()
				  << "\n";		
    }
    else {
        std::cerr << "Please provide device type: cpu | gpu\n" << std::endl;
        return -1;
    }
    return 0;
}

int main(int argc, char** argv)
{
    int i = 0;
    size_t size = 0;
    size_t rank = 0;

    cl::sycl::queue q;
    cl::sycl::buffer<int, 1> sendbuf(COUNT);
    cl::sycl::buffer<int, 1> recvbuf(COUNT);
    ccl_request_t request;
    ccl_stream_t stream;

    ccl_init();

    ccl_get_comm_rank(NULL, &rank);
    ccl_get_comm_size(NULL, &size);

    if (create_sycl_queue(argc, argv, q) != 0) {
        return -1;
    }

    // create CCL stream based on SyCL command queue
    ccl_stream_create(ccl_stream_sycl, &q, &stream);

    /* open sendbuf and initialize it on the CPU side */
    auto host_acc_sbuf = sendbuf.get_access<mode::write>();

    for (i = 0; i < COUNT; i++) {
        host_acc_sbuf[i] = rank;
    }

    /* open sendbuf and modify it on the target device side */
    q.submit([&](cl::sycl::handler& cgh) {
       auto dev_acc_sbuf = sendbuf.get_access<mode::write>(cgh);
       cgh.parallel_for<class allreduce_test_sbuf_modify>(range<1>{COUNT}, [=](item<1> id) {
           dev_acc_sbuf[id] += 1;
       });
    });

    /* invoke ccl_allreduce on the CPU side */
    ccl_allreduce(&sendbuf,
                  &recvbuf,
                  COUNT,
                  ccl_dtype_int,
                  ccl_reduction_sum,
                  NULL,
                  NULL,
                  stream,
                  &request);

    ccl_wait(request);

    /* open recvbuf and check its correctness on the target device side */
    q.submit([&](handler& cgh) {
       auto dev_acc_rbuf = recvbuf.get_access<mode::write>(cgh);
       cgh.parallel_for<class allreduce_test_rbuf_check>(range<1>{COUNT}, [=](item<1> id) {
           if (dev_acc_rbuf[id] != size * (size + 1) / 2) {
               dev_acc_rbuf[id] = -1;
           }
       });
    });

    /* print out the result of the test on the CPU side */
    if (rank == COLL_ROOT) {
        auto host_acc_rbuf_new = recvbuf.get_access<mode::read>();
        for (i = 0; i < COUNT; i++) {
            if (host_acc_rbuf_new[i] == -1) {
                cout << "Example fails" << std::endl;
                break;
            }
        }
        if (i == COUNT) {
            cout << "Example passes" << std::endl;
        }
    }

    ccl_stream_free(stream);

    ccl_finalize();

    return 0;
}
