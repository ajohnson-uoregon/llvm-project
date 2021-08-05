#ifndef CLANG_CODE_ACTION_H
#define CLANG_CODE_ACTION_H

#include <vector>
#include <string>
#include <algorithm>

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

enum NewCodeKind {
  InsertPrematch,
  InsertPostmatch,
  Replace,
};

class CodeAction {
public:
  std::string code_snippet;
  NewCodeKind kind;
  std::vector<std::string> matcher_names;
  std::string action_name;

  CodeAction(NewCodeKind kind, std::vector<std::string> matcher_names,
             std::string code, std::string action_name) :
    code_snippet(code), kind(kind), matcher_names(matcher_names),
    action_name(action_name) {}

  ~CodeAction() {}

  void add_matcher(std::string m) {
    matcher_names.push_back(m);
    //TODO: ???
    std::sort(matcher_names.begin(), matcher_names.end());
    auto new_end = std::unique(matcher_names.begin(), matcher_names.end());
    matcher_names.erase(new_end, matcher_names.end());
  }

  bool do_for_matcher(std::string matcher) {
    // printf("checking for %s in action\n", matcher.c_str());
    // this->dump();
    if (matcher_names.empty()) {
      // printf("matcher list empty return true\n");
      return true;
    }
    bool retval = std::find(matcher_names.begin(), matcher_names.end(), matcher) != matcher_names.end();
    // if (retval) {
    //   printf("found [%s] in ", matcher.c_str());
    //   dump_list();
    // }
    return retval;
  }

  void dump_list() {
    for (std::string s : matcher_names) {
      printf("%s,", s.c_str());
    }
    printf("\n");
  }

  void dump() {
    printf("Action type: %d\n", kind);
    printf("Applied to matchers:\n");
    for (std::string s : matcher_names) {
      printf("    %s\n", s.c_str());
    }
    printf("Code snippet:\n%s\n", code_snippet.c_str());
  }
};

#endif
