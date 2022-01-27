#include "clang_rewrite_hip.h"

#include <vector>
#include <string>

using namespace clang_rewrite_literals;

std::vector<std::string> clang_rewrite_literal_names = {
  "cudaMalloc",
  "cudaMemcpy",
  "cudaMemcpyHostToDevice",
  "cudaGetDeviceProperties",
};

// ****************** device management ************************

[[clang::matcher("getdevproperties")]]
auto cugetdevproperties() {
  cudaDeviceProp* prop;
  int dev;
  [[clang::matcher_block]]
  {
    cudaGetDeviceProperties(prop, dev);
  }
}

[[clang::replace("getdevproperties")]]
auto hipgetdevprop() {
  hipDeviceProp_t* prop;
  int dev;
  [[clang::matcher_block]]
  {

    hipGetDeviceProperties(prop, dev);
  }
}

// ********************** memory management **************************

[[clang::matcher("cudaMalloc")]]
auto cumalloc() {
  void** dev_ptr;
  size_t size;
  [[clang::matcher_block]]
  {
    cudaMalloc(dev_ptr, size);
  }
}

[[clang::replace("cudaMalloc")]]
auto hipmalloc() {
  void** dev_ptr;
  size_t size;
  [[clang::matcher_block]]
  {
    hipMalloc(dev_ptr, size);
  }
}


[[clang::matcher("cudaMemcpyH2D")]]
auto memcpyH2D() {
  void* dest;
  const void* src;
  size_t size;
  [[clang::matcher_block]]
  {
    cudaMemcpy(dest, src, size, cudaMemcpyHostToDevice);
  }
}

[[clang::replace("cudaMemcpyH2D")]]
auto hipmemcpyH2D() {
  void* dest;
  const void* src;
  size_t size;
  [[clang::matcher_block]]
  {
    hipMemcpy(dest, src, size, hipMemcpyHostToDevice);
  }
}

__global__ void kern(float *C, float *A, float *B, int wA, int wB);

[[clang::matcher("kernel_5args")]]
auto cudakern5() {
  dim3 grid, threads;
  float *a, *b, *c;
  int width_a, width_b;
  int block_size;
  [[clang::matcher_block]] {
    kern<<<grid, threads>>>(c, b, a, width_a, width_b);
  }
}

[[clang::replace("kernel_5args")]]
auto hipkern5() {
  dim3 grid, threads;
  float *a, *b, *c;
  int width_a, width_b;
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, grid, threads, 0, 0, c, b, a, width_a, width_b);
  }
}
