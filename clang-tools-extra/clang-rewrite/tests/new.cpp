#include <stdio.h>

[[clang::matcher("returns")]]
auto returns_test() {
  int x;
  for (int i = 0; i < 3; i++) {
    x = i;
  }
  {
    return x;
  }

}

// [[clang::matcher("cuda_kernel")]]
// auto kern() {
//   {
//     kernel<<<numblocks, numthreads>>>(arg1, arg2, ...);
//   }
// }
//
// [[clang::replace("cuda_kernel")]]
// auto hip() {
//   {
//     hip_launch(kernkel, numblocks, numthreads, 0, 0, arg1, arg2, ...);
//   }
// }


[[clang::replace("returns")]]
auto return42() {
  return 42;
}

[[clang::insert_before("returns", "thencode")]]
auto foobar() {
  printf("returning\n");;
}

[[clang::insert_after("thencode")]]
auto helloworld() {
  printf("hello world\n");
}

int main() {
  return42();
  return 0;
}
