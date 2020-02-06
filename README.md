# Intel oneAPI DL Framework Developer Toolkit (DLFD Kit)

The Intel oneAPI DL Framework Developer Toolkit is a suite of development libraries that make it fast and easy to build or optimize a deep learning framework that gets every last ounce of performance out of the newest Intel processors. This toolkit enables  Deep Learning Framework with flexible options including optimial peformance on CPU, GPU, FPGA or a Domain Optimized Accelerator. 

Included in this toolkit are:

·        Intel oneAPI Deep Neural Network Library (oneDNN)

·        Intel oneAPI Collective Communications Library (oneCCL)

## License  
The code samples are licensed under MIT license

## oneDNN
Deep Neural Networks Library for Deep Neural Networks (oneDNN) is an open-source performance library for deep learning applications. The library includes basic building blocks for neural networks optimized for Intel Architecture Processors and Intel Processor Graphics. oneDNN is intended for deep learning applications and framework developers interested in improving application performance on Intel CPUs and GPUs

Github : https://github.com/intel/mkl-dnn


## oneCCL
Collective Communication Library is a library providing an efficient implementation of communication patterns usedin deep learning.

Github : https://github.com/intel/oneccl

# oneDNN and oneCCL samples

| Type      | Name                 | Description                                                  |
| --------- | ----------------------- | ------------------------------------------------------------ |
| Component | oneDNN_Getting_Started    | This C++ API example demonstrates basic of oneDNN programming model by using a ReLU operation. |
| Component | oneDNN_SYCL_InterOps      | This C++ API example demonstrates oneDNN SYCL extensions API programming model by using a custom SYCL kernel and a ReLU operation . |
| Component | oneDNN_CNN_FP32_Inference | This C++ API example demonstrates building/runing a simple CNN fp32 inference against different oneDNN pre-built binarie. |
| Component | oneCCL_Getting_Started     | Those C++ & C API example demonstrates basic of oneCCL programming model by invoking different collective operations such as allreduce. |