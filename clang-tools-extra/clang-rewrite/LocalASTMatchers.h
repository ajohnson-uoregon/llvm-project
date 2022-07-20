//===--- LocalASTMatchers.h - AST matchers that don't warrant ASTMatchers.h ==//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef CLANG_REWRITE_LOCAL_AST_MATCHERS_H
#define CLANG_REWRITE_LOCAL_AST_MATCHERS_H

#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/Dynamic/Registry.h"

using namespace clang;
using namespace clang::ast_matchers;

namespace clang {
namespace ast_matchers {
/// Matches the type of a return statement as declared by the enclosing
/// function.
///
/// Example: returnStmt(hasExpectedReturnType(asString("int *"))) will match
/// return 0; in
/// \code
///   int* foo() {
///     return 0;
///   }
/// \endcode
/// despite the return value being an IntegerLiteral.

AST_MATCHER_P(ReturnStmt, hasExpectedReturnType, internal::Matcher<QualType>,
              InnerMatcher) {
  const auto &Parents = Finder->getASTContext().getParents(Node);

  llvm::SmallVector<DynTypedNode, 8> Stack(Parents.begin(), Parents.end());
  const FunctionDecl *FuncDeclNode;
  while (!Stack.empty()) {
    const auto &CurNode = Stack.back();
    Stack.pop_back();
    FuncDeclNode = CurNode.get<FunctionDecl>();
    if (FuncDeclNode != nullptr) {
      break;
    } else {
      for (const auto &Parent : Finder->getASTContext().getParents(CurNode))
        Stack.push_back(Parent);
    }
  }
  if (FuncDeclNode == nullptr) {
    return false;
  } else {
    return InnerMatcher.matches(FuncDeclNode->getReturnType(), Finder, Builder);
  }
}

/// Matches the first argument (grid dim) in <<<>>> on CUDA kernel calls.
///
/// Example: cudaKernelCallExpr(cudaGridDim()) will match i in
/// \code
///   kernel<<<i,j>>>();
/// \endcode
AST_MATCHER_P(CUDAKernelCallExpr, cudaGridDim, internal::Matcher<Expr>,
              InnerMatcher) {
  const CallExpr *Config = Node.getConfig();
  if (Config && Config->getNumArgs() > 0) {
    return InnerMatcher.matches(*(Config->getArg(0)), Finder, Builder);
  }
  return false;
}

/// Matches the second argument (block dim) in <<<>>> on CUDA kernel calls.
///
/// Example: cudaKernelCallExpr(cudaBlockDim()) will match j in
/// \code
///   kernel<<<i,j>>>();
/// \endcode
AST_MATCHER_P(CUDAKernelCallExpr, cudaBlockDim, internal::Matcher<Expr>,
              InnerMatcher) {
  const CallExpr *Config = Node.getConfig();
  if (Config && Config->getNumArgs() > 1) {
    return InnerMatcher.matches(*(Config->getArg(1)), Finder, Builder);
  }
  return false;
}

/// Matches the third argument (shared mem size) in <<<>>> on CUDA kernel calls.
///
/// Example: cudaKernelCallExpr(cudaSharedMemPerBlock()) will match mem in
/// \code
///   kernel<<<i, j, mem, 0>>>();
/// \endcode
AST_MATCHER_P(CUDAKernelCallExpr, cudaSharedMemPerBlock,
              internal::Matcher<Expr>, InnerMatcher) {
  const CallExpr *Config = Node.getConfig();
  if (Config && Config->getNumArgs() > 2) {
    return InnerMatcher.matches(*(Config->getArg(2)), Finder, Builder);
  }
  return false;
}

/// Matches the fourth argument (CUDA stream) in <<<>>> on CUDA kernel calls.
///
/// Example: cudaKernelCallExpr(cudaStream()) will match 0 in
/// \code
///   kernel<<<i, j, mem, 0>>>();
/// \endcode
AST_MATCHER_P(CUDAKernelCallExpr, cudaStream, internal::Matcher<Expr>,
              InnerMatcher) {
  const CallExpr *Config = Node.getConfig();
  if (Config && Config->getNumArgs() > 3) {
    return InnerMatcher.matches(*(Config->getArg(3)), Finder, Builder);
  }
  return false;
}

}
}

// namespace clang {
// namespace ast_matchers {
// namespace dynamic {
//
//   #define REGISTER_MATCHER(name)                                                 \
//     registerMatcher(#name, internal::makeMatcherAutoMarshall(                    \
//                                ::clang::ast_matchers::name, #name));
//
//   REGISTER_MATCHER(cudaBlockDim);
//   REGISTER_MATCHER(cudaGridDim);
//   REGISTER_MATCHER(cudaSharedMemPerBlock);
//   REGISTER_MATCHER(cudaStream);
//   REGISTER_MATCHER(hasExpectedReturnType);
// }
// }
// }


#endif // CLANG_REWRITE_LOCAL_AST_MATCHERS_H
