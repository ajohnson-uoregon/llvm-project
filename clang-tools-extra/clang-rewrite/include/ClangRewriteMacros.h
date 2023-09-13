#ifndef CLANG_REWRITE_MACROS_H
#define CLANG_REWRITE_MACROS_H

#include <vector>
#include <string>
#include <utility>

namespace clang_rewrite {

  enum class code_structure {
    loop = 0,
    conditional,
    math,
  };

  void loop_body() {}

  template<typename T>
  void loop_body(T predicate) {}

  // template<typename T, typename U>
  void loop_body(std::vector<std::pair<int,int>> bindings) {}

  void contains(code_structure structure) {}

  void not_contains(code_structure structure) {}

  template<typename T>
  std::string to_str(T t) {
    return "";
  }

  template<typename T>
  T code_literal(std::string str) {
    return T();
  }
}

#endif // CLANG_REWRITE_MACROS_H
