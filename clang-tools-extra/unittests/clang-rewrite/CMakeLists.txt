set(LLVM_LINK_COMPONENTS support)

get_filename_component(ClangRewriteLocation
  ${CMAKE_CURRENT_SOURCE_DIR}/../../clang-rewrite REALPATH
  )
include_directories(
  ${ClangRewriteLocation}
  )

add_extra_unittest(ClangRewriteTests
  RewriteTests.cpp
  CodeActionTests.cpp
  ConstructMatcherTests.cpp
  FindLiteralsTests.cpp
  MatcherGenCallbackTests.cpp
  MatcherWrapperTests.cpp
  NewCodeCallbackTests.cpp
  RewriteCallbackTests.cpp
  )

clang_target_link_libraries(ClangRewriteTests
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  clangDynamicASTMatchers
  clangLex
  )

target_link_libraries(ClangRewriteTests
  PRIVATE
  clangRewriteTool
  )
