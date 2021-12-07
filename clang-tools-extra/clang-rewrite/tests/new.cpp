#include <stdio.h>

[[clang::matcher("returns")]]
auto returns_test() {
  int x;
  for (int i = 0; i < 3; i++) {
    x = i;
  }
  [[likely]]
  {
    printf("not a matcher\n");
  }
  [[clang::matcher_block]]
  {
    return x;
  }
}

constexpr double pow(double x, long long n) noexcept {
    if (n > 0) [[likely]]
        return x * pow(x, n - 1);
    else [[unlikely]]
        return 1;
}

// [[clang::matcher("another test")]]
// auto test() {
//   [[clang::matcher_block]]
//   {
//     int x = 42;
//     printf("this should print the warning!\n");
//   }
// }

// [[clang::matcher("cuda_kernel")]]
// auto kern() {
//   [[clang::matcher_block]]
//   {
//     kernel<<<numblocks, numthreads>>>(arg1, arg2, ...);
//   }
// }
//
// [[clang::replace("cuda_kernel")]]
// auto hip() {
//   if (kernel == "gaussian") {
//     [[clang::matcher_block]]
//     {
//       hip_launch(kernel, numblocks, numthreads, 0, 0, arg1, arg2, ...);
//     }
//   }
// }


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
