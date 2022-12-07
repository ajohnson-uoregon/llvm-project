#ifndef CLANG_REWRITE_MACROS_H
#define CLANG_REWRITE_MACROS_H

#include <vector>
#include <utility>

namespace clang_rewrite {

  enum class code_structure {
    loop,
  };

  void loop_body() {}

  template<typename T>
  void loop_body(T predicate) {}

  // template<typename T, typename U>
  void loop_body(std::vector<std::pair<int,int>> bindings) {}

  void not_contains(code_structure structure) {}

}

#endif // CLANG_REWRITE_MACROS_H
