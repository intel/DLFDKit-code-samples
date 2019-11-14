Below is a sample readme and all Samples for Intel(r) oneAPI are expected to follow this
# CCL Getting Started sample
This CCL sample code is implemented using C++ and DPC++ language for CPU and GPU. 

| Optimized for                       | Description
|:---                               |:---
| OS                                | Linux Ubuntu 18.04; 
| Hardware                          | Kaby Lake with GEN9 or newer
| Software                          | Intel oneAPI Collective Communications Library (oneCCL), Intel oneAPI DPC++ Compiler, Intel oneAPI DPC++ Library (oneDPL), GNU Compiler
| What you will learn               | basic CCL programming model for both Intel CPU and GPU
| Time to complete                  | 15 minutes




## License  
This code sample is licensed under MIT license

## Pre-requirement


### GPU and CPU

-----

The sample below require the following components, which are part of the [Intel oneAPI Base Tookit](https://software.intel.com/en-us/oneapi/oneapi-kit)
*  Intel oneAPI Collective Communications Library (oneCCL)
*  Intel oneAPI DPC++ Compiler
*  Intel oneAPI DPC++ Library (oneDPL)

The sample also requires OpenCL driver. Please refer [System Requirements](https://software.intel.com/en-us/articles/intel-oneapi-base-toolkit-system-requirements) for OpenCL driver installation.


You can refer to this page [oneAPI](https://software.intel.com/en-us/oneapi) for toolkit installation.




## How to Build  

### on Linux  

#### GPU and CPU:

- Build the sample  with SYCL for GPU and CPU \
  please replace ${ONEAPI_ROOT} for your installation path. \
  ex : /opt/intel/inteloneapi \
  ```
  source ${ONEAPI_ROOT}/setvars.sh
  ```
  Make sure that both the enviroments of compiler and ccl are properly set up before you process following steps.
  If setvars.sh complains "not found" for compiler or ccl, please check your installation first.
  
  ```
  cd DLDevKit-code-samples/CCL_Getting_Started  
  mkdir build  
  cd build 
  cmake .. -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=dpcpp
  make
  ```

## How to Run  

### on Linux  


#### GPU and CPU:
- Run the program \
  please replace the {NUMBBER_OF_PROCESS} with integer number accordingly

  ```
  mpirun -n ${NUMBER_OF_PROCESSES} ./out/sycl_allreduce_cpp_test gpu|cpu
  ```
  
  ex: run on GPU
  ```
  mpirun -n 2 ./out/sycl_allreduce_cpp_test gpu
  ``` 
  

## Result Validation 

### on Linux 
- Run the program on CPU or GPU following [How to Run Session](#how-to-run)
- CPU Results

  ```
  Provided device type: cpu
  Running on Intel(R) Core(TM) i7-7567U CPU @ 3.50GHz
  Example passes
  ```
  please note that name of running device may vary according to your environment
  

- GPU Results
  ```
  Provided device type: gpu
  Running on Intel(R) Gen9 HD Graphics NEO
  Example passes
  ```
  please note that name of running device may vary according to your environment
