set(LLVM_LINK_COMPONENTS support)

add_clang_tool(clang-selective-instrument
  SelectiveInstrument.cpp
  )
target_link_libraries(clang-selective-instrument
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  clangDynamicASTMatchers
  clangLex
  )
