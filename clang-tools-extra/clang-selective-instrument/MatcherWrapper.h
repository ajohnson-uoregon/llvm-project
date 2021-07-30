#ifndef LLVM_CLANG_MATCHER_WRAPPER_H
#define LLVM_CLANG_MATCHER_WRAPPER_H

#include "CodeAction.h"

#include <vector>
#include <string>

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

template <class T>
class MatcherWrapper {
public:
  T matcher;
  // where matcher defined
  std::string name = "<unknown matcher>";
  std::string fname = "<unknown file>";
  std::vector<CodeAction*> actions;
  int line = -1;
  int col = -1;


  // MatcherWrapper() = delete;

  MatcherWrapper(T m) : matcher(m) {}

  MatcherWrapper(T m, std::string name, std::string fname, int line, int col) :
    matcher(m), name(name), fname(fname), line(line), col(col) {}

  void setMatcher(T m) {
    matcher = m;
  }

  T getMatcher() {
    return matcher;
  }

  void addAction(CodeAction* act) {
    actions.push_back(act);
  }

  std::vector<CodeAction*> getActions() {
    return actions;
  }

  void setName(std::string n) {
    name = n;
  }

  std::string getName() {
    return name;
  }

  void setFname(std::string name) {
    fname = name;
  }

  std::string getFname() {
    return fname;
  }

  void setLineAndCol(int l, int c) {
    line = l;
    col = c;
  }

  int getLine() {
    return line;
  }

  int getCol() {
    return col;
  }

  void dump() {
    printf("matcher named %s defined on %s %d:%d\n", name.c_str(), fname.c_str(), line, col);
    printf("has actions:\n");
    for (auto act : actions) {
      act->dump();
    }
  }
};


#endif
