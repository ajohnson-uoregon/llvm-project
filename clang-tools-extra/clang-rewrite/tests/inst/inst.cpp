#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

// types are currently fully polymorphic, using specific types so type inference
// on auto can succeed
void fn(int a);
auto LOG_FN(auto a, auto b) {}
auto LOG_LAMBDA(auto a, auto b) {}

[[clang::matcher("log_fn")]]
auto fn_call_matcher(int arg) {
  [[clang::matcher_block]] {
    fn(arg);
  }
}

[[clang::replace("log_fn")]]
auto fn_call_replacer(int arg) {
  [[clang::matcher_block]] {
    LOG_FN(fn, arg);
  }
}


[[clang::matcher("log_lambda")]]
auto lambda_call_matcher(int arg) {
  auto lambda = [&](int){};
  [[clang::matcher_block]] {
    lambda(arg);
  }
}

[[clang::replace("log_lambda")]]
auto lambda_call_replacer(int arg) {
  auto lambda = [&](int){};
  [[clang::matcher_block]] {
    LOG_LAMBDA(lambda, arg);
  }
}
