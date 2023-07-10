#include "ClangRewriteMacros.h"

[[clang::matcher("omp")]]
auto omp_m() {
  [[clang::rewrite_setup]]
    int max;

  [[clang::matcher_block]] {
    #pragma omp parallel for simd
    for (int k = 0; k < max; k++) {
      clang_rewrite::loop_body();
    }
  }
}

[[clang::replace("omp")]]
auto omp_r() {
  [[clang::rewrite_setup]]
  int max;

  [[clang::matcher_block]] {
    #pragma acc parallel loop
    for (int k = 0; k < max; k++) {
      clang_rewrite::loop_body();
    }
  }
}

[[clang::matcher("omp2")]]
auto omp2_m() {
  [[clang::rewrite_setup]]
    int max;

  [[clang::matcher_block]] {
    #pragma omp parallel for
    for (int k = 0; k < max; k++) {
      clang_rewrite::loop_body();
    }
  }
}

[[clang::replace("omp2")]]
auto omp2_r() {
  [[clang::rewrite_setup]]
  int max;

  [[clang::matcher_block]] {
    #pragma acc parallel loop
    for (int k = 0; k < max; k++) {
      clang_rewrite::loop_body();
    }
  }
}
