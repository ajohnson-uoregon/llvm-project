#ifndef CLANG_REWRITE_UTILS_H
#define CLANG_REWRITE_UTILS_H

#include "clang/Basic/SourceManager.h"
#include "clang/ASTMatchers/Dynamic/Registry.h"

#include "LocalASTMatchers.h"
#include "CodeAction.h"

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

std::vector<const FileEntry*> source_file_entries;

std::vector<std::string> spec_files;

ClangTool* Tool;
ClangTool* ProcessSpec;
ClangTool* ProcessTemp;

std::string temp_file_name = "clang_rewrite_temp_source.cpp";
int num_bind_files = 0;

bool isInOneOfFileIDs(clang::SourceLocation loc, std::vector<const FileEntry*> files, SourceManager& SrcMgr) {
  return llvm::any_of(files, [&](const FileEntry* file) {
    return SrcMgr.isInFileID(loc, SrcMgr.translateFile(file));
  });
}

bool locIsInRangeHard(int begin_line, int begin_col,
                      int end_line, int end_col,
                      int my_line, int my_col) {
  if (begin_line == end_line) {
    if (my_line == begin_line) {
      if (begin_col <= my_col && my_col <= end_col) {
        return true;
      }
      else {
        return false;
      }
    }
    else {
      return false;
    }
  }
  else if (begin_line == my_line) {
    if (begin_col <= my_col) {
      return true;
    }
    else {
      return false;
    }
  }
  else if (end_line == my_line) {
    if (my_col <= end_col) {
      return true;
    }
    else {
      return false;
    }
  }
  else if (begin_line < my_line && my_line < end_line) {
    return true;
  }
  else {
    return false;
  }
}

// checks whether range is inside location
bool locIsInRangeHard(clang::rewrite_tool::Location l,
                      int my_begin_line, int my_begin_col,
                      int my_end_line, int my_end_col) {
  return locIsInRangeHard(l.begin_line, l.begin_col, l.end_line, l.end_col, my_begin_line, my_begin_col) &&
         locIsInRangeHard(l.begin_line, l.begin_col, l.end_line, l.end_col, my_end_line, my_end_col);
}

bool locIsInRangeHard(clang::rewrite_tool::Location l,
                      int my_begin_line, int my_begin_col) {
  return locIsInRangeHard(l.begin_line, l.begin_col, l.end_line, l.end_col, my_begin_line, my_begin_col);
}

void dump_binding(clang::rewrite_tool::Binding b) {
  printf("name: %s\n", b.name.c_str());
  printf("qual name: %s\n", b.qual_name.c_str());
  if (b.has_valid_range) {
    printf("valid over: %d:%d - %d:%d\n", b.valid_over.begin_line,
      b.valid_over.begin_col, b.valid_over.end_line, b.valid_over.end_col);
  }
  printf("\tvalue: %s\n", b.value.c_str());
  printf("\n");
}

namespace clang {
namespace ast_matchers {
namespace dynamic {

#define REGISTER_MATCHER(name)                                                 \
  map->registerMatcher(#name, internal::makeMatcherAutoMarshall(                    \
                             ::clang::ast_matchers::name, #name));

  void registerLocalASTMatchers(RegistryMaps* map) {
    printf("registering local matchers\n");
    REGISTER_MATCHER(cudaBlockDim);
    REGISTER_MATCHER(cudaGridDim);
    REGISTER_MATCHER(cudaSharedMemPerBlock);
    REGISTER_MATCHER(cudaStream);
    REGISTER_MATCHER(hasExpectedReturnType);
    REGISTER_MATCHER(hasNoClauses);
    // REGISTER_MATCHER(ignoringPointers);
    REGISTER_MATCHER(hasSingleArgumentExpr);
  }

}
}
}

#endif //CLANG_REWRITE_UTILS_H
