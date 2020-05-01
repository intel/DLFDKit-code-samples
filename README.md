# Intel oneAPI DL Framework Developer Toolkit (DLFD Kit)

The Intel oneAPI DL Framework Developer Toolkit is a suite of development libraries that make it fast and easy to build or optimize a deep learning framework that gets every last ounce of performance out of the newest Intel processors. This toolkit enables  Deep Learning Framework with flexible options including optimial peformance on CPU, GPU, FPGA or a Domain Optimized Accelerator. 

Included in this toolkit are:

·        Intel oneAPI Deep Neural Network Library (oneDNN)

·        Intel oneAPI Collective Communications Library (oneCCL)

## License  
The code samples are licensed under MIT license

## oneDNN
Deep Neural Networks Library for Deep Neural Networks (oneDNN) is an open-source performance library for deep learning applications. The library includes basic building blocks for neural networks optimized for Intel Architecture Processors and Intel Processor Graphics. oneDNN is intended for deep learning applications and framework developers interested in improving application performance on Intel CPUs and GPUs

Github : https://github.com/oneapi-src/oneDNN


## oneCCL
Collective Communication Library is a library providing an efficient implementation of communication patterns usedin deep learning.

Github : https://github.com/oneapi-src/oneCCL

# oneDNN and oneCCL samples
Please refer to the "link of the sample" column below for the content of the samples.

| Type      | Name                 | Link of the sample | Description                                                  |
| --------- | ----------------------- |------------------- |------------------------------------------------------------ |
| Component | oneDNN_Getting_Started    |[link](https://github.com/intel/BaseKit-code-samples/tree/master/oneDNN/oneDNN_Getting_Started) | This C++ API example demonstrates basic of oneDNN programming model by using a ReLU operation. |
| Component | oneDNN_SYCL_InterOps      |[link](https://github.com/intel/BaseKit-code-samples/tree/master/oneDNN/oneDNN_SYCL_InterOp) | This C++ API example demonstrates oneDNN SYCL extensions API programming model by using a custom SYCL kernel and a ReLU operation . |
| Component | oneDNN_CNN_FP32_Inference |[link](https://github.com/intel/BaseKit-code-samples/tree/master/oneDNN/oneDNN_CNN_INFERENCE_FP32)| This C++ API example demonstrates building/runing a simple CNN fp32 inference against different oneDNN pre-built binarie. |
| Component | oneCCL_Getting_Started     |[link](https://github.com/intel/BaseKit-code-samples/tree/master/oneCCL/oneCCL_Getting_Started) | Those C++ & C API example demonstrates basic of oneCCL programming model by invoking different collective operations such as allreduce. |
| Component | oneDNN_Getting_Started.ipynb|[link](https://github.com/intel/BaseKit-code-samples/tree/master/oneDNN/oneDNN_Getting_Started/oneDNN_Getting_Started.ipynb) |This Jupyter Notebook demonstrates how to compile a oneDNN sample with different releases via batch jobs on the Intel oneAPI DevCloud|
| Component | oneDNN_CPU2GPU_Porting.ipynb|[link](https://github.com/intel/BaseKit-code-samples/tree/master/oneDNN/oneDNN_CNN_INFERENCE_FP32/oneDNN_CPU2GPU_Porting.ipynb) |This Jupyter Notebook demonstrates how to port a oneDNN sample from CPU-only version to CPU&GPU version by using DPC++ on the Intel oneAPI DevCloud|
| Component | oneCCL_Getting_Started.ipynb |[link](https://github.com/intel/BaseKit-code-samples/tree/master/oneCCL/oneCCL_Getting_Started/oneCCL_Getting_Started.ipynb) |This Jupyter Notebook demonstrates how to compile a oneCCL sample with different releases and how to port a oneCCL sample from CPU-only version to CPU&GPU version by using DPC++ via batch jobs on the Intel oneAPI DevCloud|