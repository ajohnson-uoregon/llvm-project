#ifndef CLANG_CODE_ACTION_H
#define CLANG_CODE_ACTION_H

#include <algorithm>
#include <string>
#include <vector>
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/FileSystem.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/LangOptions.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Basic/FileManager.h"
#include "clang/Basic/Diagnostic.h"
#include "clang/Basic/DiagnosticOptions.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/MemoryBufferRef.h"

#include "ConstructMatchers.h"
#include "ClangRewriteUtils.h"

using namespace clang;
using namespace clang::ast_matchers;
using namespace llvm;

namespace clang {
namespace rewrite_tool {

enum NewCodeKind {
  InsertPrematch,
  InsertPostmatch,
  Replace,
};

enum BindingKind {
  TypeBinding,
  VarNameBinding,
};

typedef struct Location {
  int begin_line = -1;
  int begin_col = -1;
  int end_line = -1;
  int end_col = -1;

  bool operator==(Location a) const {
    if (a.begin_line == begin_line &&
        a.begin_col == begin_col &&
        a.end_line == end_line &&
        a.end_col == end_col) {
      return true;
    }
    return false;
  }
} Location;



typedef struct Binding {
  std::vector<VariantMatcher> matchers;
  std::string name;
  std::string qual_name;
  std::string value;
  BindingKind kind;
  bool has_valid_range = false;
  Location valid_over;
} Binding;

struct bindings_compare {
  inline bool operator() (const Binding& b1, const Binding& b2) {
    if (b1.name == "clang_rewrite::loop_body" ||
        b1.qual_name == "clang_rewrite::loop_body") {
      return false;
    }
    else if (b2.name == "clang_rewrite::loop_body" ||
             b2.qual_name == "clang_rewrite::loop_body") {
      return true;
    }
    else {
      return b1.name < b2.name;
    }
  }
};

struct bindings_eq {
  inline bool operator() (const Binding& b1, const Binding& b2) {
    if (b1.name == b2.name &&
        b1.qual_name == b2.qual_name &&
        b1.value == b2.value &&
        b1.kind == b2.kind &&
        b1.valid_over == b2.valid_over) {
      return true;
    }
    return false;
  }
};

class CodeAction {
public:
  std::string base_code_snippet; // the code as it appears in the spec
  std::string setup_code_snippet; // any setup declarations
  std::string edited_code_snippet; // the code after bound snippets have been copy-pasted in
  NewCodeKind kind;
  std::vector<std::string> matcher_names;
  std::string action_name;
  // FileID spec_file; <- WE CAN'T TRUST THIS
  std::string spec_file_name;
  SourceRange snippet_range;

  CodeAction(std::string code, std::string setup_code, std::string action_name, NewCodeKind kind,
      std::vector<std::string> matcher_names, std::string file_name, SourceRange range)
      : base_code_snippet(code), setup_code_snippet(setup_code), kind(kind),
        matcher_names(matcher_names),
        action_name(action_name), spec_file_name(file_name), snippet_range(range) {}

  ~CodeAction() {}

  void add_matcher(std::string m) {
    matcher_names.push_back(m);
    // TODO: do we need to unique these???
    std::sort(matcher_names.begin(), matcher_names.end());
    auto new_end = std::unique(matcher_names.begin(), matcher_names.end());
    matcher_names.erase(new_end, matcher_names.end());
  }

  bool do_for_matcher(std::string matcher) {
    // if no matcher is specified, do it for everything
    if (matcher_names.empty()) {
      return true;
    }
    return std::find(matcher_names.begin(), matcher_names.end(), matcher) !=
           matcher_names.end();
  }

  void dump_bindings(std::vector<Binding>& bindings) {
    printf("All bindings:\n");
    for (Binding b : bindings) {
      printf("name: %s\n", b.name.c_str());
      printf("qual name: %s\n", b.qual_name.c_str());
      printf("\tvalue: %s\n", b.value.c_str());
      printf("\n");
    }
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
    printf("Code snippet:\n%s\n", base_code_snippet.c_str());
  }
};

}
} // namespaces

#endif //CLANG_CODE_ACTION_H
