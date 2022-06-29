#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

// template <class T>
// [[clang::matcher("returns")]]
// auto return_match() {
//   T ret_val;
//   [[clang::matcher_block]] {
//     return ret_val;
//   }
// }
//
// template <class T>
// [[clang::insert_before("returns")]]
// auto return_replace() {
//   T ret_val;
//   [[clang::matcher_block]] {
//     std::cout << "returning " << ret_val << " from " << __FUNCTION__;
//     std::cout << " at " << __FILE__ << ":" << __LINE__ << "\n";
//   }
// }

// [[clang::matcher("returns")]]
// auto return_match() {
//   [[clang::matcher_block]] {
//     return;
//   }
// }
//
// [[clang::insert_before("returns")]]
// auto return_insert() {
//   [[clang::matcher_block]] {
//     std::cout << "returning from " << __FUNCTION__;
//     std::cout << " at " << __FILE__ << ":" << __LINE__ << "\n";
//   }
// }

// void func() {}
//
// [[clang::matcher("func call")]]
// auto func_match() {
//   [[clang::matcher_block]] {
//     func();
//   }
// }
//
// void func(int a1) {}
//
// template <int a1>
// [[clang::matcher("func1 call")]]
// auto func1_match() {
//   [[clang::matcher_block]] {
//     func(a1);
//   }
// }
//
// [[clang::insert_before("func call", "func1 call")]]
// auto func_before() {
//   [[clang::matcher_block]] {
//     printf("calling function from %s %s:%d\n", __FUNCTION__, __FILE__, __LINE__);
//   }
// }
//
// [[clang::insert_after("func call", "func1 call")]]
// auto func_after() {
//   [[clang::matcher_block]] {
//     printf("done calling function from %s %s:%d\n", __FUNCTION__, __FILE__, __LINE__);
//   }
// }

// void f(int a) {}
//
// // void preCall(void(*a)(int), char* b, int c);
// // void postCall(void(*a)(int), char* b, int c);
// void log(void(*a)(int));
//
// [[clang::matcher("call")]]
// auto call_matcher(int a) {
//   [[clang::matcher_block]] {
//     f(a);
//   }
// }
//
// [[clang::replace("call")]]
// auto call_replacer(int a) {
//   [[clang::matcher_block]] {
//     (log(&f), f(a));
//   }
// }

// [[clang::insert_before("call")]]
// auto call_insert_before() {
//   [[clang::matcher_block]] {
//     preCall(&f, __FILE__, __LINE__);
//   }
//
// }
//
// [[clang::insert_after("call")]]
// auto call_insert_after() {
//   [[clang::matcher_block]] {
//     postCall(&f, __FILE__, __LINE__);
//   }
//
// }
// void f(int a);
//
// auto LOG(auto a, auto b) {}
//
// [[clang::matcher("call")]]
// auto call_matcher(int arg) {
//   [[clang::matcher_block]] {
//     f(arg);
//   }
// }
//
// [[clang::replace("call")]]
// auto call_replacer(int arg) {
//   [[clang::matcher_block]] {
//     LOG(f, arg);
//   }
// }

// std::vector<std::string> clang_rewrite_literal_names = { "operator()" };

auto LAMBDA(auto a, auto b) {}

[[clang::matcher("call2")]]
auto call_matcher(int arg) {
  auto l = [&](int){};
  [[clang::matcher_block]] {
    l(arg);
  }
}

[[clang::replace("call2")]]
auto call_replacer(int arg) {
  auto l = [&](int){};
  [[clang::matcher_block]] {
    LAMBDA(l, arg);
  }
}
