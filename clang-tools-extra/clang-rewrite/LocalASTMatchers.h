#ifndef CLANG_REWRITE_LOCAL_AST_MATCHERS_H
#define CLANG_REWRITE_LOCAL_AST_MATCHERS_H

#include "clang/ASTMatchers/ASTMatchFinder.h"


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

/// TODO
/// ignoringPointersAndReferences -- matches base type, ignoring any
/// enclosing pointers or references on the type -- look at refs more
AST_MATCHER_P(Type, ignoringPointers, internal::Matcher<Type>,
              InnerMatcher) {
  const Type* type = &Node;
  while (type->isPointerType()) {
      type = type->getPointeeType().getTypePtr();
  }
  return InnerMatcher.matches(*type, Finder, Builder);
    // else if (t.isReferenceType()) {
    //
    // }
}

}
}



#endif // CLANG_REWRITE_LOCAL_AST_MATCHERS_H
