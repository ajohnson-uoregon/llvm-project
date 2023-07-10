#include "ClangRewriteMacros.h"

#include <cstdio>

int main (int argc, char** argv) {

  int N = 100000;
  int a[N];
  int b[N];
  int c[N];

  

    #pragma acc parallel loop
    for (int i = 0; i < N; i++) {
    a[i] = 1;
    b[i] = 2;
  }
  


  {[[clang::rewrite_setup]]
  int max;
[[clang::matcher_block]] {
    #pragma acc parallel loop
    for (int i = 0; i < N; i++) {
      clang_rewrite::loop_body();
    }
  }}

  for (int i = 0; i < N; i++) {
    if (c[i] != 3) {
      printf("ERROR\n");
      return 1;
    }
  }
  printf("Success!\n");
  return 0;
}
