// #include "clang_rewrite_hip.h"
#include <stdio.h>
#include <vector>
#include <string>



namespace clang_rewrite_literals {
  // float* arg1;
  // template <typename... Args, typename F>
  // void hipLaunchKernelGGL(F kernel, const dim3& numBlocks, const dim3& dimBlocks,
  //                         uint32_t sharedMemBytes, hipStream_t stream, Args... args) {}
}

using namespace clang_rewrite_literals;
// using clang_rewrite_literals::hipLaunchKernelGGL;

// std::vector<std::string> clang_rewrite_literal_names = {
//   "hipLaunchKernelGGL",
//   // "shmem",
//   "__cudaPushCallConfiguration",
//   "cudaChooseDevice",
//   "NULL"
// };

// template <class T>
// [[clang::matcher("null")]]
// auto null_match() {
//   [[clang::matcher_block]] {
//     T* var = 0;
//   }
// }
//
// template <class T>
// [[clang::replace("null")]]
// auto null_replace() {
//   [[clang::matcher_block]] {
//     T* var = nullptr;
//   }
// }
//
// template <class T>
// [[clang::matcher("null2")]]
// auto null2_match() {
//   T* var = nullptr;
//   [[clang::matcher_block]] {
//     var = 0;
//   }
// }
//
// template <class T>
// [[clang::replace("null2")]]
// auto null2_replace() {
//   T* var = nullptr;
//   [[clang::matcher_block]] {
//     var = nullptr;
//   }
// }
//
// template <class T>
// [[clang::matcher("null3")]]
// T* null3_match() {
//   [[clang::matcher_block]] {
//     return 0;
//   }
// }
//
// template <class T>
// [[clang::replace("null3")]]
// T* null3_replace() {
//   [[clang::matcher_block]] {
//     return nullptr;
//   }
// }

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

// __global__
// void cukernel1(float* a) {
//   int i = blockIdx.x*blockDim.x + threadIdx.x;
//   a[i] = a[i]*2;
// }
//
// __global__
// void cukernel2(float* a, float* b) {
//   int i = blockIdx.x*blockDim.x + threadIdx.x;
//   a[i] = a[i] + b[i];
// }
//
// extern __global__ void kernel(float* a, float* b);
//
// __global__
// void kernel(float* a, float* b) {
//   int i = hipBlockIdx_x*hipBlockDim_x + hipThreadIdx_x;
//   a[i] = a[i] + b[i];
// }
//
// void test(int a1 = 0, int a2 = 0) {}
//
//
// void calltest() {
//   test();
//   test(5);
//   test(3, 5);
// }
//
//
// [[clang::matcher("cuda_kernel")]]
// auto mycuda() {
//   int numblocks, numthreads, shmem;
//   void* stream;
//   float *arg2;
//   [[clang::matcher_block]]
//   {
//     cukernel1<<<numblocks, numthreads>>>(arg1);
//   }
// }
//
// auto othercuda() {
//   int numblocks, numthreads, shmem;
//   void* stream;
//   float *arg2;
//   cukernel2<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2);
// }

// [[clang::matcher("hip_kernel")]]
// auto otherhip() {
//   int numblocks, numthreads;
//   float *arg1, *arg2;
//   [[clang::matcher_block]]
//   {
//     hipLaunchKernelGGL(kernel, numblocks, numthreads, 0, 0, arg1, arg2);
//   }
// }

// [[clang::replace("cuda_kernel")]]
// auto myhip() {
//   int numblocks, numthreads, shmem;
//   float *arg1, *arg2;
//   [[clang::matcher_block]]
//   {
//     float a;
//     hipLaunchKernelGGL(cukernel2, dim3(numblocks), dim3(numthreads), 0, 0, arg1, arg2);
//   }
// }
//
//
// [[clang::replace("returns")]]
// auto return42() {
//   [[clang::matcher_block]]
//   {
//     return 42;
//   }
// }
//
// [[clang::insert_before("returns", "thencode")]]
// auto foobar() {
//   [[clang::matcher_block]]
//   {
//     printf("returning\n");
//   }
// }
//
// [[clang::insert_after("thencode")]]
// auto helloworld() {
//   [[clang::matcher_block]]
//   {
//     printf("hello world\n");
//   }
// }

// __global__ void kern(int arg0 = 0, int arg1 = 0, int arg2 = 0, int arg3 = 0, int arg4 = 0, int arg5 = 0, int arg6 = 0, int arg7 = 0, int arg8 = 0, int arg9 = 0, int arg10 = 0, int arg11 = 0, int arg12 = 0, int arg13 = 0, int arg14 = 0, int arg15 = 0, int arg16 = 0, int arg17 = 0, int arg18 = 0, int arg19 = 0, int arg20 = 0, int arg21 = 0, int arg22 = 0, int arg23 = 0, int arg24 = 0, int arg25 = 0, int arg26 = 0, int arg27 = 0, int arg28 = 0, int arg29 = 0, int arg30 = 0, int arg31 = 0, int arg32 = 0) {}
//
// template <int numblocks, int numthreads, int arg1>
// [[clang::matcher("kernel_launch 1 args 2 params")]]
// auto cuda_kernel_launch_1_2() {
//   [[clang::matcher_block]]
//   {
//     kern<<<numblocks, numthreads>>>(arg1);
//   }
// }
//
// template <int numblocks, int numthreads, int arg1>
// [[clang::replace("kernel_launch 1 args 2 params")]]
// auto cuda_kernel_launch_1_2_replace() {
//   [[clang::matcher_block]]
//   {
//     hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1);
//   }
// }
//
// template<int * arg1, const struct cudaDeviceProp * arg2>
// [[clang::matcher("cudaChooseDevice 2 func")]]
// auto cudaChooseDevice2_func() {
//   [[clang::matcher_block]]
//   {
//     cudaChooseDevice(arg1, arg2);
//   }
// }
//
// template<int *  arg1, const struct hipDeviceProp_t *  arg2>
// [[clang::replace("cudaChooseDevice 2 func")]]
// auto cudaChooseDevice2_replace() {
//   [[clang::matcher_block]]
//   {
//     hipChooseDevice(arg1, arg2);
//   }
// }

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

// [[clang::matcher("loops")]]
// auto loop1() {
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < M; j++) {
//       body();
//     }
//   }
// }
//
// [[clang::replace("loops")]]
// auto loop2() {
//   for (int j = M-1; j >= 0; j--) {
//     for (int i = 0; i < N; i += 5) {
//       body();
//       if (i < N) {
//         body(); x5
//       }
//       // body();
//     }
//   }
// }
//
// [[clang::insert_after("loops")]]
// auto loop3() {
//   int k = M+N/2;
//   printf("%d\n", k);
// }

// [[clang::matcher("funcdef")]]
// auto funcdef(...) {body();}
//
// [[clang::replace("funcdef")]]
// auto funcdef(..., std::vector<std::string> callstack) {body();}
//
// [[clang::matcher("funccall")]]
// auto funccall() {
//   func(...);
// }
//
// [[clang::replace("funccall")]]
// auto funccall() {
//   func(..., caller_name);
// }

// [[clang::matcher("code")]]
// auto code_match() {
//   code_stuff();
// }
//
//
// // generated by X:
// [[clang::insert("code")]]
// auto new_code() {
//   variant_code_stuff();
// }
//
// [[clang::insert("code")]]
// auto new_code2() {
//   other_variant_code_stuff();
// }
//
// [[clang::replace("code")]]
// auto code_replace() {
//   if (x) {
//     code_stuff();
//   }
//   else if (y) {
//     variant_code_stuff();
//   }
//   else {
//     other_variant_code_stuff();
//   }
// }

std::vector<std::string> clang_rewrite_literal_names = {
  "foo"
};

namespace optional {
  int c1 = 0; // replace with default value if not present???
  // int opt2;     // leave out if not present???
  //no, this is a separate thing entirely; need a varargs sort of thing
}

void foo(int a, int b);
void foo(int a, int b, int c);
void bar(int a, int b);
void bar(int a, int b, int c);

//    foo(a, b) -> bar(a, b, 0)
// foo(a, b, c) -> bar(a, b, c)
[[clang::matcher("func call")]]
auto match(int a, int b) {
  [[clang::matcher_block]]
  {
    foo(a, b, optional::c1);
  }
}

[[clang::replace("func call")]]
auto replace(int a, int b) {
  [[clang::matcher_block]]
  {
    bar(a, b, optional::c1);
  }
}

//    foo(a, b) -> bar(a, b)
// foo(a, b, c) -> bar(a, b, c)
// [[clang::matcher("func call 2")]]
// auto match2(int a, int b) {
//   [[clang::matcher_block]]
//   {
//     foo(a, b, optional::c2);
//   }
// }
//
// [[clang::replace("func call 2")]]
// auto replace2(int a, int b) {
//   [[clang::matcher_block]]
//   {
//     bar(a, b, optional::c2);
//   }
// }

int main() {
  // return42();
  return 0;
}
