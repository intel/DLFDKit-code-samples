# DNNL Getting Started sample
 This DNNL Getting Started sample code is implemented using C++ for CPU. 

| Optimized for                       | Description
|:---                               |:---
| OS                                | Linux Ubuntu 18.04; 
| Hardware                          | Intel CPU
| Software                          | Intel oneAPI Deep Neural Network Library (oneDNN)
| What you will learn               | basic DNNL programming model for Intel CPU
| Time to complete                  | 15 minutes



## What you will learn
* How to create DNNL memory objects.
* How to get data from user's buffer into a DNNL memory object.
* How tensor's logical dimensions and memory object formats relate.
* How to create DNNL primitives.
* How to execute the primitives.

## Pre-requirement

The sample below requires the following component which is part of the [Intel oneAPI DL Framework Developer Toolkit (DLFD Kit)](https://software.intel.com/en-us/oneapi/dldev-kit)
*  Intel oneAPI Deep Neural Network Library (oneDNN)

You can refer to this page [oneAPI](https://software.intel.com/en-us/oneapi) for toolkit installation.


## How to Build  

#### Using GNU C++ Compiler  

------

By using GNU C++ compiler, this sample demostrates basic DNNL operations on Intel CPU and it uses GNU OpenMP for CPU parallelization.

##### on Linux  

- Build Getting Started example with GCC  

 First, please use a clean console environment without exporting any none default environment variables.
```
source ${INTEL_ONEAPI_INSTALL_FOLDER}/setvars.sh --dnnl-configuration=cpu_gomp
```
  Make sure that both the enviroments of compiler and dnnl are properly set up before you process following steps.
  If setvars.sh complains "not found" for compiler or dnnl, please check your installation first.
  
```   
cd DLDevKit-code-samples/DNNL_Getting_Started
mkdir cpu_gomp
cd cpu_gomp
cmake .. -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ 
make getting-started-cpp
```

## How to Run  

### on Linux  
- Run the program  on CPU
  ```
  ./out/getting-started-cpp 
  ```

## Result Validation 

### on Linux  

- Enable DNNL Verbose log

  ```
  export DNNL_VERBOSE=1
  ```

- Run the program on CPU or GPU following [How to Run Session](#how-to-run)
- CPU Results

  ```
  dnnl_verbose,info,DNNL v1.0.0 (commit 560f60fe6272528955a56ae9bffec1a16c1b3204)
  dnnl_verbose,info,Detected ISA is Intel AVX2
  dnnl_verbose,exec,cpu,eltwise,jit:avx2,forward_inference,data_f32::blocked:acdb:f0 diff_undef::undef::f0,alg:eltwise_relu:0:0,1x3x13x13,968.354
  Example passes
  ```

## Implementation Details

  This example is from DNNL project, and you can refer to [ Line by Line Explanation ](https://intel.github.io/mkl-dnn/getting_started_cpp.html) for implementation details. 
  
