#include "clang_rewrite_hip.h"
#include <stdio.h>
#include <vector>
#include <string>



namespace clang_rewrite_literals {
  float* arg1;
  template <typename... Args, typename F>
  void hipLaunchKernelGGL(F kernel, const dim3& numBlocks, const dim3& dimBlocks,
                          uint32_t sharedMemBytes, hipStream_t stream, Args... args) {}
}

using namespace clang_rewrite_literals;
using clang_rewrite_literals::hipLaunchKernelGGL;

std::vector<std::string> clang_rewrite_literal_names = {
  "hipLaunchKernelGGL",
  // "shmem",
  "__cudaPushCallConfiguration",
  "cudaChooseDevice"
};


// [[clang::matcher("returns")]]
// auto returns_test() {
//   int x;
//   for (int i = 0; i < 3; i++) {
//     x = i;
//   }
//   [[likely]]
//   {
//     printf("not a matcher\n");
//   }
//   [[clang::matcher_block]]
//   {
//     return x;
//   }
// }

// constexpr double pow(double x, long long n) noexcept {
//     if (n > 0) [[likely]]
//         return x * pow(x, n - 1);
//     else [[unlikely]]
//         return 1;
// }

// [[clang::matcher("another test")]]
// auto test() {
//   [[clang::matcher_block]]
//   {
//     int x = 42;
//     printf("this should print the warning!\n");
//   }
// }

__global__
void cukernel(float* a, float* b) {
  int i = blockIdx.x*blockDim.x + threadIdx.x;
  a[i] = a[i] + b[i];
}

extern __global__ void kernel(float* a, float* b);

__global__
void kernel(float* a, float* b) {
  int i = hipBlockIdx_x*hipBlockDim_x + hipThreadIdx_x;
  a[i] = a[i] + b[i];
}



[[clang::matcher("cuda_kernel")]]
auto mycuda() {
  int numblocks, numthreads, shmem;
  void* stream;
  float *arg2;
  [[clang::matcher_block]]
  {
    cukernel<<<numblocks, numthreads>>>(arg1, arg2);
  }
}

auto othercuda() {
  int numblocks, numthreads, shmem;
  void* stream;
  float *arg2;
  cukernel<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2);
}

// [[clang::matcher("hip_kernel")]]
// auto otherhip() {
//   int numblocks, numthreads;
//   float *arg1, *arg2;
//   [[clang::matcher_block]]
//   {
//     hipLaunchKernelGGL(kernel, numblocks, numthreads, 0, 0, arg1, arg2);
//   }
// }

[[clang::replace("cuda_kernel")]]
auto myhip() {
  int numblocks, numthreads, shmem;
  float *arg1, *arg2;
  [[clang::matcher_block]]
  {
    float a;
    hipLaunchKernelGGL(cukernel, dim3(numblocks), dim3(numthreads), 0, 0, arg1, arg2);
  }
}


[[clang::replace("returns")]]
auto return42() {
  [[clang::matcher_block]]
  {
    return 42;
  }
}

[[clang::insert_before("returns", "thencode")]]
auto foobar() {
  [[clang::matcher_block]]
  {
    printf("returning\n");
  }
}

[[clang::insert_after("thencode")]]
auto helloworld() {
  [[clang::matcher_block]]
  {
    printf("hello world\n");
  }
}

__global__ void kern(int arg0 = 0, int arg1 = 0, int arg2 = 0, int arg3 = 0, int arg4 = 0, int arg5 = 0, int arg6 = 0, int arg7 = 0, int arg8 = 0, int arg9 = 0, int arg10 = 0, int arg11 = 0, int arg12 = 0, int arg13 = 0, int arg14 = 0, int arg15 = 0, int arg16 = 0, int arg17 = 0, int arg18 = 0, int arg19 = 0, int arg20 = 0, int arg21 = 0, int arg22 = 0, int arg23 = 0, int arg24 = 0, int arg25 = 0, int arg26 = 0, int arg27 = 0, int arg28 = 0, int arg29 = 0, int arg30 = 0, int arg31 = 0, int arg32 = 0) {}

template <int numblocks, int numthreads, int arg1>
[[clang::matcher("kernel_launch 1 args 2 params")]]
auto cuda_kernel_launch_1_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1);
  }
}

template <int numblocks, int numthreads, int arg1>
[[clang::replace("kernel_launch 1 args 2 params")]]
auto cuda_kernel_launch_1_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1);
  }
}

template<int * arg1, const struct cudaDeviceProp * arg2>
[[clang::matcher("cudaChooseDevice 2 func")]]
auto cudaChooseDevice2_func() {
  [[clang::matcher_block]]
  {
    cudaChooseDevice(arg1, arg2);
  }
}

template<int *  arg1, const struct hipDeviceProp_t *  arg2>
[[clang::replace("cudaChooseDevice 2 func")]]
auto cudaChooseDevice2_replace() {
  [[clang::matcher_block]]
  {
    hipChooseDevice(arg1, arg2);
  }
}

// [[clang::matcher("cudaDeviceProp type")]]
// template<typename Ty>
// auto cudaDeviceProp_type() {
//   [[clang::matcher_block]]
//   {
//     Ty varname;
//   }
// }
//
// [[clang::replace("cudaDeviceProp type")]]
// template<typename Ty>
// auto cudaDeviceProp_replace() {
//   [[clang::matcher_block]]
//   {
//     Ty varname;
//   }
// }
//
// template<>
// auto cudaDeviceProp_type<cudaDeviceProp>();
//
// template<>
// auto cudaDeviceProp_replace<hipDeviceProp_t>();

int main() {
  return42();
  return 0;
}
