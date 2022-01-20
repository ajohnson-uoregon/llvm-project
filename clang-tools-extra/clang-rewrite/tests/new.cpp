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
  "__cudaPushCallConfiguration"
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
    cukernel<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2);
  }
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
    hipLaunchKernelGGL(cukernel, dim3(numblocks), dim3(numthreads), shmem, 0, arg1, arg2);
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

int main() {
  return42();
  return 0;
}
