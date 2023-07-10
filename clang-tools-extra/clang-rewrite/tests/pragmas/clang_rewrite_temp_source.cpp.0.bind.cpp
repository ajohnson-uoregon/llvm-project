#include "ClangRewriteMacros.h"

#include <cstdio>

int main (int argc, char** argv) {

  int N = 100000;
  int a[N];
  int b[N];
  int c[N];

  {[[clang::rewrite_setup]]
  int max;
[[clang::matcher_block]] {
    #pragma acc parallel loop
    for (int k = 0; k < max; k++) {
      clang_rewrite::loop_body();
    }
  }}

  #pragma omp parallel for
  for (int i = 0; i < N; i++) {
    c[i] = a[i] + b[i];
  }

  for (int i = 0; i < N; i++) {
    if (c[i] != 3) {
      printf("ERROR\n");
      return 1;
    }
  }
  printf("Success!\n");
  return 0;
}
