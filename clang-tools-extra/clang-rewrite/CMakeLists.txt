set(LLVM_LINK_COMPONENTS support)

add_clang_tool(clang-rewrite
  ClangRewrite.cpp
  ConstructMatchers.cpp
  )
target_link_libraries(clang-rewrite
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  clangDynamicASTMatchers
  clangLex
  )
