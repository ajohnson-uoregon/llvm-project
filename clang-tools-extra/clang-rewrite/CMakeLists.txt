set(LLVM_LINK_COMPONENTS support)
# set(CMAKE_CXX_FLAGS "-g -fsanitize=address -fsanitize=undefined")

add_clang_tool(clang-rewrite
  ClangRewrite.cpp
  ConstructMatchers.cpp
  )

add_clang_library(clangRewriteTool
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
