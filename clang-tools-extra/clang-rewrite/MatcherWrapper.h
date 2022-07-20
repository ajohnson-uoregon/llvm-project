//===--- MatcherWrapper.h - Store metadata about AST matchers and actions -===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_MATCHER_WRAPPER_H
#define LLVM_CLANG_MATCHER_WRAPPER_H

#include "CodeAction.h"

#include <string>
#include <vector>

using namespace clang;
using namespace clang::ast_matchers;
using namespace llvm;

namespace clang {
namespace rewrite_tool {

template <class T> class MatcherWrapper {
public:
  T matcher;
  // where matcher defined
  std::string name = "<unknown matcher>";
  std::string fname = "<unknown file>";
  std::vector<CodeAction *> actions;
  int line = -1;
  int col = -1;

  MatcherWrapper(T m) : matcher(m) {}

  MatcherWrapper(T m, std::string name, std::string fname, int line, int col)
      : matcher(m), name(name), fname(fname), line(line), col(col) {}

  void setMatcher(T m) { matcher = m; }

  T getMatcher() { return matcher; }

  void addAction(CodeAction *act) { actions.push_back(act); }

  std::vector<CodeAction *> getActions() { return actions; }

  void setName(std::string n) { name = n; }

  std::string getName() { return name; }

  void setFname(std::string name) { fname = name; }

  std::string getFname() { return fname; }

  void setLineAndCol(int l, int c) {
    line = l;
    col = c;
  }

  int getLine() { return line; }

  int getCol() { return col; }

  void dump() {
    printf("matcher named %s defined on %s %d:%d\n", name.c_str(),
           fname.c_str(), line, col);
    printf("has actions:\n");
    for (auto act : actions) {
      act->dump();
    }
  }
};

}
} //namespaces

#endif //LLVM_CLANG_MATCHER_WRAPPER_H
