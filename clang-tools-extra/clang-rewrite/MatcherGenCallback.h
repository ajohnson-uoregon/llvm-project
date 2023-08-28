#ifndef CLANG_MATCHER_GEN_CALLBACK_H
#define CLANG_MATCHER_GEN_CALLBACK_H

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchersInternal.h"

#include "clang/Lex/Lexer.h"
#include "clang/Lex/Token.h"

#include "clang/AST/ASTConsumer.h"
// #include "clang/AST/OpenMPClause.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/AST/Type.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"

#include "CodeAction.h"
#include "ConstructMatchers.h"
#include "FindLiteralsCallback.h"

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::ast_matchers::dynamic;
using namespace clang::tooling;

using ast_matchers::internal::Matcher;

namespace clang {
namespace rewrite_tool {

using MT = MatcherType;

class BuildMatcherVisitor : public RecursiveASTVisitor<BuildMatcherVisitor> {
public:
  explicit BuildMatcherVisitor(ASTContext* context, std::vector<std::string> literals,
      bool is_internal_matcher, std::vector<Binding> internal_literals)
    : context(context), literals(literals), is_internal_matcher(is_internal_matcher),
      internal_literals(internal_literals) {}


    Node* get_matcher() {
      return root;
    }

    bool is_literal(const NamedDecl* decl) {
      // printf("BUT IS IT LITERAL\n");
      const DeclContext* con = decl->getDeclContext();
      if (auto ns = dyn_cast<NamespaceDecl>(con)) {
        // printf("NAMESPACE\n");
        // ns->dump();
        if (ns->getNameAsString() == "clang_rewrite_literals") {
          // printf("%s is in literal ns\n", ns->getNameAsString().c_str());
          return true;
        }
      }
      if (std::find(literals.begin(), literals.end(), decl->getNameAsString()) != literals.end() ||
          std::find(literals.begin(), literals.end(), decl->getQualifiedNameAsString()) != literals.end()) {
        // printf("%s is in list of literals\n", decl->getNameAsString().c_str());
        return true;
      }
      return false;
    }

    // TODO: placeholder until we actually figure out literals
    bool is_literal(DeclRefExpr* ref) {
      return is_literal(ref->getDecl());
    }

    bool is_internal_literal(const NamedDecl* decl) {
      printf("internal literals\n");
      for (Binding b : internal_literals) {
        printf("%s\n", b.value.c_str());
        if (decl->getNameAsString() == b.value ||
            decl->getQualifiedNameAsString() == b.value) {
          return true;
        }
      }
      return false;
    }

    bool is_internal_literal(DeclRefExpr* ref) {
      return is_internal_literal(ref->getDecl());
    }

    int getNumChildren(Stmt* stmt) {
      int num_children = 0;
      for (auto iter = stmt->child_begin(); iter != stmt->child_end(); iter++) {
        num_children++;
      }
      return num_children;
    }

    int getNumChildren(OMPReductionClause* clause) {
      int num_children = 0;
      for (auto lhs : clause->lhs_exprs()) {
        num_children++;
      }
      for (auto rhs : clause->rhs_exprs()) {
        num_children++;
      }
      for (auto op : clause->reduction_ops()) {
        num_children++;
      }
      return num_children;
    }

    int getNumChildren(OMPClause* clause) {
      int num_children = 0;
      for (auto iter : clause->children()) {
        num_children++;
      }
      return num_children;
    }

    const FunctionDecl* getEnclosingFunction(const DynTypedNode node) {
      DynTypedNodeList parents = context->getParents(node);
      const FunctionDecl* func;
      for (const DynTypedNode node : parents) {
        func = node.get<FunctionDecl>();
        if (!func) {
          return getEnclosingFunction(node);
        }
        else {
          return func;
        }
      }
      return nullptr;
    }

    const FunctionDecl* getEnclosingFunction(Stmt* stmt) {
      DynTypedNodeList parents = context->getParents(*stmt);
      const FunctionDecl* func;
      for (const DynTypedNode node : parents) {
        func = node.get<FunctionDecl>();
        if (!func) {
          return getEnclosingFunction(node);
        }
        else {
          return func;
        }
      }
      return nullptr;
    }

    bool VisitArraySubscriptExpr(ArraySubscriptExpr* sub) {
      add_node(MT::arraySubscriptExpr, "arraySubscriptExpr()", getNumChildren(sub));

      return true;
    }

    bool VisitBinaryOperator(BinaryOperator* binop) {
      // plus one for opname
      add_node(MT::binaryOperator, "binaryOperator()", getNumChildren(binop) +1);
      Node* opname = add_node(MT::hasOperatorName, "hasOperatorName()", 0);
      opname->add_arg(binop->getOpcodeStr());

      return true;
    }

    bool VisitCallExpr(CallExpr* call) {
      // short circuit to not double up, yay class inheritance
      if (isa<CUDAKernelCallExpr>(call) ||
          isa<CXXOperatorCallExpr>(call)) {
        return true;
      }
      FunctionDecl* callee = call->getDirectCallee();
      Expr* broken_callee = call->getCallee();
      if (callee != nullptr) {
        if (callee->getQualifiedNameAsString() == "clang_rewrite::loop_body") {
          printf("FOUND LOOP BODY CALL\n");
          Node* body = add_node(MT::loopBody, "loopBody", 0);
          // using set_name as well as binding so in future we can have
          // short_name be the name of the loop instead of a generic loop_body
          body->set_name("loop_body", "clang_rewrite::loop_body");
          body->bind_to("clang_rewrite::loop_body");
          return false; //don't traverse the rest of the tree, we handle that
        }
        // plus 1 for callee
        add_node(MT::callExpr, "callExpr()", getNumChildren(call) +1);
        add_node(MT::callee, "callee()", 1);
        Node* fxn = add_node(MT::functionDecl, "functionDecl()", 0);
        if (is_literal(callee)) {
          fxn->set_is_literal(true);
          fxn->set_name(callee->getNameAsString(), callee->getQualifiedNameAsString());
        }
        else if (is_internal_matcher && is_internal_literal(callee)) {
          fxn->set_is_literal(true);
          fxn->set_name(callee->getNameAsString(), callee->getQualifiedNameAsString());
        }
        else {
          fxn->bind_to(callee->getNameAsString());
        }
      }
      else if (broken_callee != nullptr) {
        if (const UnresolvedLookupExpr* lookup = dyn_cast<UnresolvedLookupExpr>(broken_callee)) {
          add_node(MT::callExpr, "callExpr()", getNumChildren(call) + 1);
          add_node(MT::callee, "callee()", 1);
          add_node(MT::unresolvedLookupExpr, "unresolvedLookupExpr()", 1);
          add_node(MT::hasAnyDeclaration, "hasAnyDeclaration()", 1);
          Node* named = add_node(MT::namedDecl, "namedDecl()", 0);

          const Decl* d = *(lookup->decls().begin());
          if (const NamedDecl* decl = dyn_cast<NamedDecl>(d)) {
            if (is_literal(decl)) {
              named->set_is_literal(true);
              named->set_name(decl->getNameAsString(), decl->getQualifiedNameAsString());
            }
            else if (is_internal_matcher && is_internal_literal(decl)) {
              named->set_is_literal(true);
              named->set_name(decl->getNameAsString(), decl->getQualifiedNameAsString());
            }
            else {
              named->bind_to(decl->getNameAsString());
            }
          }
        }
      }
      else {
        add_node(MT::callExpr, "callExpr()", getNumChildren(call));
      }
      return true;
    }

    bool VisitCapturedStmt(CapturedStmt* stmt) {
      add_node(MT::capturedStmt, "capturedStmt()", 1);
      add_node(MT::hasCapturedStmt, "hasCapturedStmt()", getNumChildren(stmt));
      return true;
    }

    bool VisitCompoundStmt(CompoundStmt* comp) {
      add_node(MT::compoundStmt, "compoundStmt()", getNumChildren(comp));
      return true;
    }

    bool VisitCUDAKernelCallExpr(CUDAKernelCallExpr* call) {
      CallExpr* conf = call->getConfig();
      printf("KERNEL CONF\n");
      conf->dump();

      FunctionDecl* kern = call->getDirectCallee();
      if (kern != nullptr) {
        // plus 1 for callee
        add_node(MT::cudaKernelCallExpr, "cudaKernelCallExpr()", getNumChildren(call) +1);
        add_node(MT::callee, "callee()", 1);
        Node* fxn = add_node(MT::functionDecl, "functionDecl()", 0);
        if (is_literal(kern)) {
          fxn->set_is_literal(true);
          fxn->set_name(kern->getNameAsString(), kern->getQualifiedNameAsString());
        }
        else if (is_internal_matcher && is_internal_literal(kern)) {
          fxn->set_is_literal(true);
          fxn->set_name(kern->getNameAsString(), kern->getQualifiedNameAsString());
        }
        else {
          fxn->bind_to(kern->getNameAsString());
        }
      }
      else {
        add_node(MT::cudaKernelCallExpr, "cudaKernelCallExpr()", getNumChildren(call));
      }

      return true;
    }

    bool VisitCXXConstructExpr(CXXConstructExpr* expr) {
      // if (expr->isElidable()) {
      //   printf("is elidable\n");
      // }
      std::string ty = expr->getType().getAsString();
      //this needs to be put on the *child* of the cast, not the cast itself
      set_type_on_child(ty);
      add_node(MT::fakeNode, "cxxConstructExpr", getNumChildren(expr));
      return true;
    }

    bool VisitCXXDefaultArgExpr(CXXDefaultArgExpr* expr) {
      add_node(MT::fakeNode, "cxxDefaultArgExpr", getNumChildren(expr));
      return true;
    }

    bool VisitCXXDeleteExpr(CXXDeleteExpr* expr) {
      add_node(MT::cxxDeleteExpr, "cxxDeleteExpr()", 2);
      if (expr->isArrayForm()) {
        add_node(MT::isArrayForm, "isArrayForm()", 0);
      }
      else {
        add_node(MT::isNotArrayForm, "isNotArrayForm()", 0);
      }

      add_node(MT::hasDeleteArg, "hasDeleteArg()", getNumChildren(expr));
      return true;
    }

    bool VisitCXXFunctionalCastExpr(CXXFunctionalCastExpr* cast) {
      std::string ty = cast->getTypeAsWritten().getAsString();
      //this needs to be put on the *child* of the cast, not the cast itself
      set_type_on_child(ty);
      add_node(MT::fakeNode, "cxxFunctionalCastExpr", getNumChildren(cast));
      return true;
    }

    bool VisitCXXMethodDecl(CXXMethodDecl* decl) {
      Node* method = add_node(MT::cxxMethodDecl, "cxxMethodDecl()", decl->getNumParams() + 1);

      std::string name = decl->getNameAsString();
      std::string qualname = decl->getQualifiedNameAsString();

      if (is_literal(decl)) {
        method->set_name(name, qualname);
        method->set_is_literal(true);
        std::string ty = decl->getType().getAsString();
        method->set_type(ty);
      }
      else if (is_internal_matcher && is_internal_literal(decl)) {
        method->set_name(name, qualname);
        method->set_is_literal(true);
        std::string ty = decl->getType().getAsString();
        method->set_type(ty);
      }
      else if (name == "operator()") {
        method->set_name(name, name);
        method->set_is_literal(true);
      }
      else {
        method->bind_to(name + ";" + qualname);
      }

      // TODO: figure out matchers with arg and submatcher
      // int i = 0;
      for (const ParmVarDecl* parm : decl->parameters()) {
        Node* p = add_node(MT::hasAnyParameter, "hasAnyParameter()", 1);
        // p->add_arg(i);
        TraverseDecl(const_cast<ParmVarDecl*>(parm));
        // i++;
      }

      add_node(MT::hasAnyBody, "hasAnyBody()", getNumChildren(decl->getBody()));
      TraverseStmt(decl->getBody());

      return false;
    }

    bool VisitCXXNewExpr(CXXNewExpr* expr) {
      add_node(MT::cxxNewExpr, "cxxNewExpr()", 1);
      if (expr->isArray()) {
        add_node(MT::hasArraySize, "hasArraySize()", getNumChildren(expr));
      }
      else {
        add_node(MT::hasNewInitializer, "hasNewInitializer()", getNumChildren(expr));
      }

      return true;
    }

    bool VisitCXXOperatorCallExpr(CXXOperatorCallExpr* call) {
      FunctionDecl* callee = call->getDirectCallee();
      if (callee != nullptr) {
        // plus 1 for callee
        add_node(MT::cxxOperatorCallExpr, "cxxOperatorCallExpr()", getNumChildren(call) +1);
        add_node(MT::callee, "callee()", 1);
        Node* fxn = add_node(MT::functionDecl, "functionDecl()", 0);
        fxn->set_is_literal(true);
        fxn->set_name(callee->getNameAsString(), callee->getQualifiedNameAsString());
      }
      else {
        add_node(MT::cxxOperatorCallExpr, "cxxOperatorCallExpr()", getNumChildren(call));
      }
      return true;
    }

    bool VisitCXXThisExpr(CXXThisExpr* expr) {
      add_node(MT::cxxThisExpr, "cxxThisExpr()", getNumChildren(expr));

      return true;
    }

    bool VisitDeclRefExpr(DeclRefExpr* ref) {
      ValueDecl* decl = ref->getDecl();
      std::string name = decl->getNameAsString();
      std::string qualname = decl->getQualifiedNameAsString();
      printf("name: %s\n", name.c_str());
      printf("qual name %s\n", qualname.c_str());

      if (is_literal(ref)) {
        Node* declref = add_node(MT::declRefExpr, "declRefExpr()", getNumChildren(ref) +1);
        declref->set_ignore_casts(true);
        // declref->set_is_literal(true);
        add_node(MT::to, "to()", 1);
        Node* valuedecl = add_node(MT::valueDecl, "valueDecl()", 0);
        valuedecl->set_name(name, qualname);
        valuedecl->set_is_literal(true);
        std::string ty = decl->getType().getAsString();
        valuedecl->set_type(ty);
      }
      else if (is_internal_matcher && is_internal_literal(ref)) {
        Node* declref = add_node(MT::declRefExpr, "declRefExpr()", getNumChildren(ref) +1);
        // declref->set_ignore_casts(true);
        // declref->set_is_literal(true);
        add_node(MT::to, "to()", 1);
        Node* valuedecl = add_node(MT::valueDecl, "valueDecl()", 0);
        valuedecl->set_name(name, qualname);
        valuedecl->set_is_literal(true);
        std::string ty = decl->getType().getAsString();
        valuedecl->set_type(ty);
      }
      else {
        QualType ty = ref->getType();
        while (ty->isPointerType()) {
          printf("is pointer\n");
          ty = ty->getPointeeType();
        }
        auto is_template_param = ty->isTemplateTypeParmType();

        if (is_template_param) {
          Node* declref = add_node(MT::declRefExpr, "declRefExpr()", getNumChildren(ref) +1);
          declref->set_ignore_casts(true);
          declref->bind_to(name + ";" + qualname);

          add_node(MT::hasType, "hasType()", 1);
          ty = ref->getType();
          while (ty->isPointerType()) {
            add_node(MT::pointerType, "pointerType()", 1);
            add_node(MT::pointee, "pointee()", 1);
            ty = ty->getPointeeType();
          }
          Node* type_node = add_node(MT::type, "type", 0);
          type_node->bind_to(ty.getAsString());
        }
        else {
          QualType ty = ref->getType();
          if (!ty->isPointerType()) {
            add_node(MT::anyOf, "anyOf()", 3);
            Node* declref = add_node(MT::declRefExpr, "declRefExpr()", getNumChildren(ref));
            declref->set_ignore_casts(true);
            declref->bind_to(name + ";" + qualname);
            if (ty->isIntegerType()) {
              Node* lit = add_node(MT::integerLiteral, "integerLiteral()", 0);
              lit->set_ignore_casts(true);
              lit->bind_to(name + ";" + qualname);
            }
            else if (ty->isAnyCharacterType()) {
              Node* lit = add_node(MT::characterLiteral, "characterLiteral()", getNumChildren(ref));
              lit->set_ignore_casts(true);
              lit->bind_to(name + ";" + qualname);
            }
            else if (ty->isCompoundType()) {
              Node* lit = add_node(MT::compoundLiteralExpr, "compoundLiteralExpr()", getNumChildren(ref));
              lit->set_ignore_casts(true);
              lit->bind_to(name + ";" + qualname);
            }
            else if (ty->isBooleanType()) {
              Node* lit = add_node(MT::cxxBoolLiteral, "cxxBoolLiteral()", getNumChildren(ref));
              lit->set_ignore_casts(true);
              lit->bind_to(name + ";" + qualname);
            }
            else if (ty->isFixedPointType()) {
              Node* lit = add_node(MT::fixedPointLiteral, "fixedPointLiteral()", getNumChildren(ref));
              lit->set_ignore_casts(true);
              lit->bind_to(name + ";" + qualname);
            }
            else if (ty->isFloatingType()) {
              Node* lit = add_node(MT::floatLiteral, "floatLiteral()", getNumChildren(ref));
              lit->set_ignore_casts(true);
              lit->bind_to(name + ";" + qualname);
            }
            else { // no test for string types, also no default literal type so
              Node* lit = add_node(MT::stringLiteral, "stringLiteral()", getNumChildren(ref));
              lit->set_ignore_casts(true);
              lit->bind_to(name + ";" + qualname);
            }

            Node* gen_expr = add_node(MT::expr, "expr()", getNumChildren(ref));
            gen_expr->set_ignore_casts(true);
            gen_expr->bind_to(name + ";" + qualname);

          }
          else {
            Node* declref = add_node(MT::declRefExpr, "declRefExpr()", getNumChildren(ref));
            declref->set_ignore_casts(true);
            declref->bind_to(name + ";" + qualname);
          }
        }
      }

      // if it's already been given a type by nodes higher up (eg, cxxFunctionalCastExpr)
      // don't overwrite that; need highest level type to match
      // if (!has_type() && decl->getType()->getTypeClass() != clang::Type::TypeClass::Auto) {
      //   std::string type = decl->getType().getAsString();
      //   set_type(type);
      // }

      return true;
    }

    bool VisitDeclStmt(DeclStmt* decl) {
      add_node(MT::declStmt, "declStmt()", getNumChildren(decl));

      return true;
    }

    bool VisitFieldDecl(FieldDecl* decl) {
      std::string name = decl->getNameAsString();
      std::string qualname = decl->getQualifiedNameAsString();

      if (is_literal(decl)) {
        Node* fielddecl = add_node(MT::fieldDecl, "fieldDecl()", 0);
        fielddecl->set_name(name, qualname);
        fielddecl->set_is_literal(true);
        std::string ty = decl->getType().getAsString();
        fielddecl->set_type(ty);
      }
      else if (is_internal_matcher && is_internal_literal(decl)) {
        Node* fielddecl = add_node(MT::fieldDecl, "fieldDecl()", 0);
        fielddecl->set_name(name, qualname);
        fielddecl->set_is_literal(true);
        std::string ty = decl->getType().getAsString();
        fielddecl->set_type(ty);
      }
      else {
        QualType ty = decl->getType();
        while (ty->isPointerType()) {
          printf("is pointer\n");
          ty = ty->getPointeeType();
        }
        auto is_template_param = ty->isTemplateTypeParmType();
        printf("is template type parameter type???? %s\n", is_template_param ? "true" : "false");

        if (is_template_param) {
          Node* fielddecl = add_node(MT::fieldDecl, "fieldDecl()", 1);
          if (StringRef(name).starts_with("clang_rewrite_")) {
            fielddecl->bind_to(name + ";" + qualname);
          }
          else {
            fielddecl->bind_to("clang_rewrite_" + name + ";" + qualname);
          }
          add_node(MT::hasType, "hasType()", 1);
          ty = decl->getType();
          while (ty->isPointerType()) {
            add_node(MT::pointerType, "pointerType()", 1);
            add_node(MT::pointee, "pointee()", 1);
            ty = ty->getPointeeType();
          }
          Node* type_node = add_node(MT::type, "type", 0);
          type_node->bind_to(ty.getAsString());
        }
        else {
          Node* fielddecl = add_node(MT::fieldDecl, "fieldDecl()", 0);
          if (StringRef(name).starts_with("clang_rewrite_")) {
            fielddecl->bind_to(name + ";" + qualname);
          }
          else {
            fielddecl->bind_to("clang_rewrite_" + name + ";" + qualname);
          }
          std::string type = decl->getType().getAsString();
          fielddecl->set_type(type);
        }
      }
      return true;
    }

    bool VisitForStmt(ForStmt* forstmt) {
      add_node(MT::forStmt, "forStmt()", getNumChildren(forstmt));

      return true;
    }

    bool VisitIfStmt(IfStmt* ifstmt) {
      add_node(MT::ifStmt, "ifStmt()", getNumChildren(ifstmt));

      return true;
    }

    bool VisitLambdaExpr(LambdaExpr* expr) {
      add_node(MT::lambdaExpr, "lambdaExpr()", 2);
      add_node(MT::hasCallOperator, "hasCallOperator()", 1);
      TraverseDecl(expr->getCallOperator());

      add_node(MT::hasLambdaBody, "hasLambdaBody()", 1);
      TraverseStmt(expr->getBody());

      return false;
    }

    bool VisitMemberExpr(MemberExpr* expr) {
      add_node(MT::memberExpr, "memberExpr()", 2);
      add_node(MT::member, "member()", 1);
      TraverseDecl(expr->getMemberDecl());
      expr->getMemberDecl()->dump();

      add_node(MT::hasObjectExpression, "hasObjectExpression()", getNumChildren(expr));

      return true;
    }

    bool VisitOMPAtomicDirective(OMPAtomicDirective* dir) {
        add_node(MT::ompAtomicDirective, "ompAtomicDirective()", getNumChildren(dir) + dir->getNumClauses());

        return true;
    }
    bool VisitOMPBarrierDirective(OMPBarrierDirective* dir) {
      add_node(MT::ompBarrierDirective, "ompBarrierDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPCancelDirective(OMPCancelDirective* dir) {
      add_node(MT::ompCancelDirective, "ompCancelDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPCancellationPointDirective(OMPCancellationPointDirective* dir) {
      add_node(MT::ompCancellationPointDirective, "ompCancellationPointDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPCriticalDirective(OMPCriticalDirective* dir) {
      add_node(MT::ompCriticalDirective, "ompCriticalDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPDepobjDirective(OMPDepobjDirective* dir) {
      add_node(MT::ompDepobjDirective, "ompDepobjDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPDispatchDirective(OMPDispatchDirective* dir) {
      add_node(MT::ompDispatchDirective, "ompDispatchDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPErrorDirective(OMPErrorDirective* dir) {
      add_node(MT::ompErrorDirective, "ompErrorDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPFlushDirective(OMPFlushDirective* dir) {
      add_node(MT::ompFlushDirective, "ompFlushDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPInteropDirective(OMPInteropDirective* dir) {
      add_node(MT::ompInteropDirective, "ompInteropDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPMaskedDirective(OMPMaskedDirective* dir) {
      add_node(MT::ompMaskedDirective, "ompMaskedDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPMasterDirective(OMPMasterDirective* dir) {
      add_node(MT::ompMasterDirective, "ompMasterDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPMetaDirective(OMPMetaDirective* dir) {
      add_node(MT::ompMetaDirective, "ompMetaDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPOrderedDirective(OMPOrderedDirective* dir) {
      add_node(MT::ompOrderedDirective, "ompOrderedDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPParallelDirective(OMPParallelDirective* dir) {
      add_node(MT::ompParallelDirective, "ompParallelDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPParallelMaskedDirective(OMPParallelMaskedDirective* dir) {
      add_node(MT::ompParallelMaskedDirective, "ompParallelMaskedDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPParallelMasterDirective(OMPParallelMasterDirective* dir) {
      add_node(MT::ompParallelMasterDirective, "ompParallelMasterDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPParallelSectionsDirective(OMPParallelSectionsDirective* dir) {
      add_node(MT::ompParallelSectionsDirective, "ompParallelSectionsDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPScanDirective(OMPScanDirective* dir) {
      add_node(MT::ompScanDirective, "ompScanDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPSectionDirective(OMPSectionDirective* dir) {
      add_node(MT::ompSectionDirective, "ompSectionDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPSectionsDirective(OMPSectionsDirective* dir) {
      add_node(MT::ompSectionsDirective, "ompSectionsDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPSingleDirective(OMPSingleDirective* dir) {
      add_node(MT::ompSingleDirective, "ompSingleDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetDataDirective(OMPTargetDataDirective* dir) {
      add_node(MT::ompTargetDataDirective, "ompTargetDataDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetDirective(OMPTargetDirective* dir) {
      add_node(MT::ompTargetDirective, "ompTargetDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetEnterDataDirective(OMPTargetEnterDataDirective* dir) {
      add_node(MT::ompTargetEnterDataDirective, "ompTargetEnterDataDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetExitDataDirective(OMPTargetExitDataDirective* dir) {
      add_node(MT::ompTargetExitDataDirective, "ompTargetExitDataDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetParallelDirective(OMPTargetParallelDirective* dir) {
      add_node(MT::ompTargetParallelDirective, "ompTargetParallelDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetTeamsDirective(OMPTargetTeamsDirective* dir) {
      add_node(MT::ompTargetTeamsDirective, "ompTargetTeamsDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetUpdateDirective(OMPTargetUpdateDirective* dir) {
      add_node(MT::ompTargetUpdateDirective, "ompTargetUpdateDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTaskDirective(OMPTaskDirective* dir) {
      add_node(MT::ompTaskDirective, "ompTaskDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTaskgroupDirective(OMPTaskgroupDirective* dir) {
      add_node(MT::ompTaskgroupDirective, "ompTaskgroupDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTaskwaitDirective(OMPTaskwaitDirective* dir) {
      add_node(MT::ompTaskwaitDirective, "ompTaskwaitDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTaskyieldDirective(OMPTaskyieldDirective* dir) {
      add_node(MT::ompTaskyieldDirective, "ompTaskyieldDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTeamsDirective(OMPTeamsDirective* dir) {
      add_node(MT::ompTeamsDirective, "ompTeamsDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPDistributeDirective(OMPDistributeDirective* dir) {
      add_node(MT::ompDistributeDirective, "ompDistributeDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPDistributeParallelForDirective(OMPDistributeParallelForDirective* dir) {
      add_node(MT::ompDistributeParallelForDirective, "ompDistributeParallelForDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPDistributeParallelForSimdDirective(OMPDistributeParallelForSimdDirective* dir) {
      add_node(MT::ompDistributeParallelForSimdDirective, "ompDistributeParallelForSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPDistributeSimdDirective(OMPDistributeSimdDirective* dir) {
      add_node(MT::ompDistributeSimdDirective, "ompDistributeSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPForDirective(OMPForDirective* dir) {
      add_node(MT::ompForDirective, "ompForDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPForSimdDirective(OMPForSimdDirective* dir) {
      add_node(MT::ompForSimdDirective, "ompForSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPGenericLoopDirective(OMPGenericLoopDirective* dir) {
      add_node(MT::ompGenericLoopDirective, "ompGenericLoopDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPMaskedTaskLoopDirective(OMPMaskedTaskLoopDirective* dir) {
      add_node(MT::ompMaskedTaskLoopDirective, "ompMaskedTaskLoopDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPMaskedTaskLoopSimdDirective(OMPMaskedTaskLoopSimdDirective* dir) {
      add_node(MT::ompMaskedTaskLoopSimdDirective, "ompMaskedTaskLoopSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPMasterTaskLoopDirective(OMPMasterTaskLoopDirective* dir) {
      add_node(MT::ompMasterTaskLoopDirective, "ompMasterTaskLoopDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPMasterTaskLoopSimdDirective(OMPMasterTaskLoopSimdDirective* dir) {
      add_node(MT::ompMasterTaskLoopSimdDirective, "ompMasterTaskLoopSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPParallelForDirective(OMPParallelForDirective* dir) {
      add_node(MT::ompParallelForDirective, "ompParallelForDirective()", getNumChildren(dir) + dir->getNumClauses());
      printf("num children %d\n", getNumChildren(dir));
      printf("num clauses %d\n", dir->getNumClauses());
      return true;
    }
    bool VisitOMPParallelForSimdDirective(OMPParallelForSimdDirective* dir) {
      add_node(MT::ompParallelForSimdDirective, "ompParallelForSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPParallelGenericLoopDirective(OMPParallelGenericLoopDirective* dir) {
      add_node(MT::ompParallelGenericLoopDirective, "ompParallelGenericLoopDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPParallelMaskedTaskLoopDirective(OMPParallelMaskedTaskLoopDirective* dir) {
      add_node(MT::ompParallelMaskedTaskLoopDirective, "ompParallelMaskedTaskLoopDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPParallelMaskedTaskLoopSimdDirective(OMPParallelMaskedTaskLoopSimdDirective* dir) {
      add_node(MT::ompParallelMaskedTaskLoopSimdDirective, "ompParallelMaskedTaskLoopSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPParallelMasterTaskLoopDirective(OMPParallelMasterTaskLoopDirective* dir) {
      add_node(MT::ompParallelMasterTaskLoopDirective, "ompParallelMasterTaskLoopDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPParallelMasterTaskLoopSimdDirective(OMPParallelMasterTaskLoopSimdDirective* dir) {
      add_node(MT::ompParallelMasterTaskLoopSimdDirective, "ompParallelMasterTaskLoopSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPSimdDirective(OMPSimdDirective* dir) {
      add_node(MT::ompSimdDirective, "ompSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetParallelForDirective(OMPTargetParallelForDirective* dir) {
      add_node(MT::ompTargetParallelForDirective, "ompTargetParallelForDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetParallelForSimdDirective(OMPTargetParallelForSimdDirective* dir) {
      add_node(MT::ompTargetParallelForSimdDirective, "ompTargetParallelForSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetParallelGenericLoopDirective(OMPTargetParallelGenericLoopDirective* dir) {
      add_node(MT::ompTargetParallelGenericLoopDirective, "ompTargetParallelGenericLoopDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetSimdDirective(OMPTargetSimdDirective* dir) {
      add_node(MT::ompTargetSimdDirective, "ompTargetSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetTeamsDistributeDirective(OMPTargetTeamsDistributeDirective* dir) {
      add_node(MT::ompTargetTeamsDistributeDirective, "ompTargetTeamsDistributeDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetTeamsDistributeParallelForDirective(OMPTargetTeamsDistributeParallelForDirective* dir) {
      add_node(MT::ompTargetTeamsDistributeParallelForDirective, "ompTargetTeamsDistributeParallelForDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetTeamsDistributeParallelForSimdDirective(OMPTargetTeamsDistributeParallelForSimdDirective* dir) {
      add_node(MT::ompTargetTeamsDistributeParallelForSimdDirective, "ompTargetTeamsDistributeParallelForSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetTeamsDistributeSimdDirective(OMPTargetTeamsDistributeSimdDirective* dir) {
      add_node(MT::ompTargetTeamsDistributeSimdDirective, "ompTargetTeamsDistributeSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTargetTeamsGenericLoopDirective(OMPTargetTeamsGenericLoopDirective* dir) {
      add_node(MT::ompTargetTeamsGenericLoopDirective, "ompTargetTeamsGenericLoopDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTaskLoopDirective(OMPTaskLoopDirective* dir) {
      add_node(MT::ompTaskLoopDirective, "ompTaskLoopDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTaskLoopSimdDirective(OMPTaskLoopSimdDirective* dir) {
      add_node(MT::ompTaskLoopSimdDirective, "ompTaskLoopSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTeamsDistributeDirective(OMPTeamsDistributeDirective* dir) {
      add_node(MT::ompTeamsDistributeDirective, "ompTeamsDistributeDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTeamsDistributeParallelForDirective(OMPTeamsDistributeParallelForDirective* dir) {
      add_node(MT::ompTeamsDistributeParallelForDirective, "ompTeamsDistributeParallelForDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTeamsDistributeParallelForSimdDirective(OMPTeamsDistributeParallelForSimdDirective* dir) {
      add_node(MT::ompTeamsDistributeParallelForSimdDirective, "ompTeamsDistributeParallelForSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTeamsDistributeSimdDirective(OMPTeamsDistributeSimdDirective* dir) {
      add_node(MT::ompTeamsDistributeSimdDirective, "ompTeamsDistributeSimdDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTeamsGenericLoopDirective(OMPTeamsGenericLoopDirective* dir) {
      add_node(MT::ompTeamsGenericLoopDirective, "ompTeamsGenericLoopDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPTileDirective(OMPTileDirective* dir) {
      add_node(MT::ompTileDirective, "ompTileDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }
    bool VisitOMPUnrollDirective(OMPUnrollDirective* dir) {
      add_node(MT::ompUnrollDirective, "ompUnrollDirective()", getNumChildren(dir) + dir->getNumClauses());

      return true;
    }

    bool VisitOMPReductionClause(OMPReductionClause* clause) {
      add_node(MT::ompReductionClause, "ompReductionClause", getNumChildren(clause));
      printf("clause num children %d\n", getNumChildren(clause));
      for (auto lhs : clause->lhs_exprs()) {
        lhs->dump();
        add_node(MT::hasAnyLHSExpr, "hasAnyLHSExpr()", 1);
        TraverseStmt(lhs);
      }
      for (auto rhs : clause->rhs_exprs()) {
        rhs->dump();
        add_node(MT::hasAnyRHSExpr, "hasAnyRHSExpr()", 1);
        TraverseStmt(rhs);
      }
      for (auto op : clause->reduction_ops()) {
        op->dump();
        add_node(MT::hasAnyReductionOp, "hasAnyReductionOp()", 1);
        TraverseStmt(op);
      }

      return true;
    }

    bool VisitParenExpr(ParenExpr* parens) {
      add_node(MT::parenExpr, "parenExpr()", 1);
      add_node(MT::hasSubExpr, "hasSubExpr()", getNumChildren(parens));

      return true;
    }

    bool VisitParenListExpr(ParenListExpr* parens) {
      add_node(MT::parenListExpr, "parenListExpr()", 1);
      add_node(MT::hasAnySubExpr, "hasAnySubExpr()", getNumChildren(parens));

      return true;
    }

    bool VisitParmVarDecl(ParmVarDecl* decl) {
      Node* d = add_node(MT::parmVarDecl, "parmVarDecl()", 0);
      std::string name = decl->getNameAsString();
      std::string qualname = decl->getQualifiedNameAsString();

      if (is_literal(decl)) {
        d->set_name(name, qualname);
        d->set_is_literal(true);
        std::string ty = decl->getType().getAsString();
        d->set_type(ty);
      }
      else if (is_internal_matcher && is_internal_literal(decl)) {
        d->set_name(name, qualname);
        d->set_is_literal(true);
        std::string ty = decl->getType().getAsString();
        d->set_type(ty);
      }
      else {
        d->bind_to(name + ";" + qualname);
      }


      return true;
    }

    bool VisitUnaryExprOrTypeTraitExpr(UnaryExprOrTypeTraitExpr* expr) {
      if (!expr->isArgumentType()) {
        add_node(MT::unaryExprOrTypeTraitExpr, "unaryExprOrTypeTraitExpr()", 1);
        add_node(MT::hasSingleArgumentExpr, "hasSingleArgumentExpr()", getNumChildren(expr));
      }
      else { // it's a type and we don't care
        add_node(MT::unaryExprOrTypeTraitExpr, "unaryExprOrTypeTraitExpr()", 0);
      }

      return true;
    }

    bool VisitUnresolvedLookupExpr(UnresolvedLookupExpr* expr) {
      add_node(MT::unresolvedLookupExpr, "unresolvedLookupExpr()", 1);
      add_node(MT::hasAnyDeclaration, "hasAnyDeclaration()", 1);

      Node* named = add_node(MT::namedDecl, "namedDecl()", 0);

      const Decl* d = *(expr->decls().begin());
      if (const NamedDecl* decl = dyn_cast<NamedDecl>(d)) {
        if (is_literal(decl)) {
          named->set_is_literal(true);
          named->set_name(decl->getNameAsString(), decl->getQualifiedNameAsString());
        }
        else if (is_internal_matcher && is_internal_literal(decl)) {
          named->set_is_literal(true);
          named->set_name(decl->getNameAsString(), decl->getQualifiedNameAsString());
        }
        else {
          named->bind_to(decl->getNameAsString());
        }
      }

      return true;
    }

    bool VisitVarDecl(VarDecl* decl) {
      if (isa<ParmVarDecl>(decl)) {
        return true;
      }
      std::string name = decl->getNameAsString();
      std::string qualname = decl->getQualifiedNameAsString();

      // TODO: dunno if the number of children is always 1 but let's hope so for now
      if (is_literal(decl)) {
        Node* d = add_node(MT::varDecl, "varDecl()", 1);
        if (decl->hasInit()) {
          add_node(MT::hasInitializer, "hasInitializer()", 1);
        }
        d->set_is_literal(true);
        std::string type = decl->getType().getAsString();
        d->set_type(type);
        d->set_name(name, qualname);
      }
      else {
        QualType ty = decl->getType();
        while (ty->isPointerType()) {
          printf("is pointer\n");
          ty = ty->getPointeeType();
        }
        auto is_template_param = ty->isTemplateTypeParmType();
        printf("is template type parameter type???? %s\n", is_template_param ? "true" : "false");

        if (is_template_param) {
          Node* d = add_node(MT::varDecl, "varDecl()", 2);
          add_node(MT::hasType, "hasType()", 1);
          ty = decl->getType();
          while (ty->isPointerType()) {
            add_node(MT::pointerType, "pointerType()", 1);
            add_node(MT::pointee, "pointee()", 1);
            ty = ty->getPointeeType();
          }
          Node* type_node = add_node(MT::type, "type", 0);
          type_node->bind_to(ty.getAsString());

          if (decl->hasInit()) {
            add_node(MT::hasInitializer, "hasInitializer()", 1);
            if (decl->getType()->isPointerType()) {
              add_node(MT::ignoringParenImpCasts, "ignoringParenImpCasts()", 1);
            }
          }
          d->bind_to(name + ";" + qualname);
        }
        else {
          Node* d = add_node(MT::varDecl, "varDecl()", 1);
          if (decl->hasInit()) {
            add_node(MT::hasInitializer, "hasInitializer()", 1);
            if (decl->getType()->isPointerType()) {
              add_node(MT::ignoringParenImpCasts, "ignoringParenImpCasts()", 1);
            }
          }
          std::string type = decl->getType().getAsString();
          d->set_type(type);
          d->bind_to(name + ";" + qualname);
        }
      }
      return true;
    }

    bool VisitIntegerLiteral(IntegerLiteral* lit) {
      Node* int_node = add_node(MT::integerLiteral, "integerLiteral()", 1);
      int_node->set_ignore_casts(true);
      Node* equals = add_node(MT::equals, "equals()", 0);
      equals->add_arg((int) lit->getValue().getSExtValue());
      return true;
    }

    bool VisitImplicitCastExpr(ImplicitCastExpr* expr) {
      std::string ty = expr->getType().getAsString();
      //this needs to be put on the *child* of the cast, not the cast itself
      set_type_on_child(ty);
      // set_ignore_casts_on_child();
      add_node(MT::fakeNode, "ImplicitCastExpr", getNumChildren(expr));
      return true;
    }

    bool VisitReturnStmt(ReturnStmt* ret) {
      if (ret->getRetValue()) {
        const FunctionDecl* func = getEnclosingFunction(ret);
        if (func != nullptr) {
          QualType ty = func->getDeclaredReturnType();
          while (ty->isPointerType()) {
            printf("is pointer\n");
            ty = ty->getPointeeType();
          }
          auto is_template_param = ty->isTemplateTypeParmType();
          if (is_template_param) {
            Node* ret_node = add_node(MT::returnStmt, "returnStmt()", 2);
            add_node(MT::hasExpectedReturnType, "hasExpectedReturnType()", 1);
            ty = func->getDeclaredReturnType();
            while (ty->isPointerType()) {
              add_node(MT::pointerType, "pointerType()", 1);
              add_node(MT::pointee, "pointee()", 1);
              ty = ty->getPointeeType();
            }
            Node* type_node = add_node(MT::type, "type", 0);
            type_node->bind_to(ty.getAsString());

            std::string type = ret->getRetValue()->getType().getAsString();
            add_node(MT::hasReturnValue, "hasReturnValue()", getNumChildren(ret));
            ret_node->set_type(type);
          }
          else {
            Node* ret_node = add_node(MT::returnStmt, "returnStmt()", 1);
            std::string type = ret->getRetValue()->getType().getAsString();
            add_node(MT::hasReturnValue, "hasReturnValue()", getNumChildren(ret));
            ret_node->set_type(type);
          }
        }
        else {
          Node* ret_node = add_node(MT::returnStmt, "returnStmt()", 1);
          std::string type = ret->getRetValue()->getType().getAsString();
          add_node(MT::hasReturnValue, "hasReturnValue()", getNumChildren(ret));
          ret_node->set_type(type);
        }
      }
      else {
        add_node(MT::returnStmt, "returnStmt()", getNumChildren(ret));
      }
      return true;
    }

    bool VisitUnaryOperator(UnaryOperator* unop) {
      add_node(MT::unaryOperator, "unaryOperator()", getNumChildren(unop) +1);
      Node* opname = add_node(MT::hasOperatorName, "hasOperatorName()", 0);
      opname->add_arg(unop->getOpcodeStr(unop->getOpcode()));

      return true;
    }

private:
  ASTContext* context;
  std::vector<std::string> literals;
  bool is_internal_matcher = false;
  std::vector<Binding> internal_literals;
  std::string matcher = "";
  Node* root = nullptr;
  Node* current = root;
  // stack for keeping track of branches; int is expected number of children
  std::vector<std::pair<Node*, int>> branch_points;
  bool pending_type = false;
  std::string pending_type_str = "";
  bool pending_ignore_casts = false;

  void dump_branch_points() {
    int stack = 0;
    for (std::pair<Node*, int> pt : branch_points) {
      printf("branch point %d\n", stack);
      pt.first->dump_node(1);
      printf("    has %d children left\n", pt.second);
      stack++;
    }
  }

  Node* add_node(MatcherType sm, std::string code, int children) {
    Node* temp = new Node(sm, code);
    // printf("before node add\n");
    // printf("adding node %s\n", code.c_str());
    // dump_branch_points();
    // if the tree is empty
    if (root == nullptr) {
      // printf("adding root %s\n", code.c_str());
      if (sm == MT::fakeNode) {
        printf("WARNING: root can't be a fake node\n");
      }
      root = temp;
      current = root;
      current->bind_to("clang_rewrite_top_level_match");
      if (sm != MT::fakeNode) {
        handle_pending();
      }
      branch_points.push_back(std::pair<Node*, int>(current, children));
      return temp;
    }
    // if this has multiple children, push it onto the branch stack
    if (children > 1) {
      // printf("node %s should have %d children\n", code.c_str(), children);
      current->add_child(temp);
      current = temp;
      if (sm != MT::fakeNode) {
        handle_pending();
      }
      branch_points.push_back(std::pair<Node*, int>(current, children));
    }
    // if it's a leaf, we've finished adding this child, decrement
    else if (children == 0) {
      // printf("node %s has no more children\n", code.c_str());
      current->add_child(temp);
      current = temp;
      branch_points.back().second--;
      if (sm != MT::fakeNode) {
        handle_pending();
      }
      while (!branch_points.empty() && branch_points.back().second == 0) {
        branch_points.pop_back();
        if (!branch_points.empty()) {
          branch_points.back().second--;
        }
      }
      if (!branch_points.empty()) {
        current = branch_points.back().first;
      }
    }
    // children == 1; stick
    else {
      // printf("node %s should have 1 child\n", code.c_str());
      current->add_child(temp);
      current = temp;
      if (sm != MT::fakeNode) {
        handle_pending();
      }
    }
    // printf("after node add\n");
    // dump_branch_points();
    // printf("------------------------\n");
    return temp;
  }

  bool ignore_pending() {
    if (current->matcher_type == MT::anyOf) {
      return true;
    }
    return false;
  }

  void handle_pending() {
    if (!ignore_pending()) {
      if (pending_type) {
        current->set_type(pending_type_str);
        pending_type = false;
        pending_type_str = "";
      }
      if (pending_ignore_casts) {
        current->set_ignore_casts(true);
        pending_ignore_casts = false;
      }
    }
  }

  void set_type_on_child(std::string type) {
    if (!pending_type) {
      pending_type = true;
      pending_type_str = type;
    }
    // else {
    //   printf("WARNING: would overwrite pending %s with %s\n", pending_type_str.c_str(), type.c_str());
    // }
  }

  void set_ignore_casts_on_child() {
    pending_ignore_casts = true;
  }
};


DeclarationMatcher matcher_stmt =
  functionDecl(allOf(
    hasAttr(attr::Matcher),
    hasBody(compoundStmt(
      hasAnySubstatement(attributedStmt(allOf(
        hasAttr(attr::MatcherBlock),
        hasSubStmt(compoundStmt(anything()).bind("body"))
      )))
    ))
  )).bind("matcher");

DeclarationMatcher matcher_decl =
  functionDecl(allOf(
    hasAttr(attr::Matcher),
    hasBody(compoundStmt(
      hasAnySubstatement(declStmt(hasDescendant(
        namedDecl(hasAttr(attr::MatcherBlock)).bind("body")
      )))
    ))
  )).bind("matcher");

// std::unordered_map<std::string, VariantMatcher> stmt_matchers;
std::vector<MatcherWrapper<ast_matchers::internal::DynTypedMatcher> *> user_matchers;
std::vector<MatcherWrapper<ast_matchers::internal::DynTypedMatcher> *> internal_matchers;

class MatcherGenCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  std::string matcher_name;
  bool is_internal_matcher;
  std::vector<Binding> internal_bindings;
  std::vector<Location> past_matches;

  MatcherGenCallback(bool internal_matcher, std::vector<Binding> internal_binds)
    : is_internal_matcher(internal_matcher), internal_bindings(internal_binds) {}

  void onStartOfTranslationUnit() override {
    // dynamic::registerLocalMatchers();
  }

  void run(const MatchFinder::MatchResult& result) override {
    printf("found matcher\n");
    context = result.Context;

    // const CallExpr* call = result.Nodes.getNodeAs<CallExpr>("matcher");
    // if (call &&
    //   spec_files.find(context->getSourceManager().getFilename(call->getBeginLoc())) != spec_files.end()) {
    //   //TODO
    // }

    const Decl* decl = result.Nodes.getNodeAs<Decl>("matcher");
    const Stmt* stmt = result.Nodes.getNodeAs<Stmt>("matcher");

    bool decl_valid = true;
    bool stmt_valid = true;

    if (!decl || !context->getSourceManager().isWrittenInMainFile(decl->getBeginLoc())) {
      // printf("ERROR: invalid matcher definition\n");
      decl_valid = false;
    }
    if (!stmt || !context->getSourceManager().isWrittenInMainFile(stmt->getBeginLoc())) {
      stmt_valid = false;
    }

    if (!decl_valid && !stmt_valid) {
      printf("ERROR: invalid matcher definition\n");
      return;
    }
    // printf("full function\n");
    // func->dump();

    unsigned int begin_line, begin_col;
    unsigned int end_line, end_col;

    if (decl_valid) {
      FullSourceLoc begin = context->getFullLoc(decl->getBeginLoc());
      FullSourceLoc end = context->getFullLoc(decl->getEndLoc());
      begin_line = begin.getSpellingLineNumber();
      begin_col = begin.getSpellingColumnNumber();
      end_line = end.getSpellingLineNumber();
      end_col = end.getSpellingColumnNumber();

      for (Attr* attr : decl->attrs()) {
        if (attr->getKind() == attr::Matcher) {
          StringRef name = cast<MatcherAttr>(attr)->getMatcherName();
          matcher_name = name.str();
        }
      }
      printf("FOUND matcher (decl) %s at %d:%d - %d:%d\n", matcher_name.c_str(), begin_line, begin_col, end_line, end_col);
    }
    else if (stmt_valid) {
      FullSourceLoc begin = context->getFullLoc(stmt->getBeginLoc());
      FullSourceLoc end = context->getFullLoc(stmt->getEndLoc());
      begin_line = begin.getSpellingLineNumber();
      begin_col = begin.getSpellingColumnNumber();
      end_line = end.getSpellingLineNumber();
      end_col = end.getSpellingColumnNumber();

      if (const AttributedStmt* attrstmt = dyn_cast<AttributedStmt>(stmt)) {
        for (const Attr* attr : attrstmt->getAttrs()) {
          if (attr->getKind() == attr::Matcher) {
            StringRef name = cast<MatcherAttr>(attr)->getMatcherName();
            matcher_name = name.str();
          }
        }
        printf("FOUND matcher (stmt) %s at %d:%d - %d:%d\n", matcher_name.c_str(), begin_line, begin_col, end_line, end_col);
      }
      else {
        printf("FOUND nameless matcher at %d:%d - %d:%d\n", begin_line, begin_col, end_line, end_col);
      }
    }

    if (std::find(past_matches.begin(), past_matches.end(),
        (Location){begin_line, begin_col, end_line, end_col}) != past_matches.end()) {
      printf("duplicate match in matcher gen\n");
      for (Location l : past_matches) {
        printf("\t{%d:%d-%d:%d}\n", l.begin_line, l.begin_col, l.end_line, l.end_col);
      }
      return;
    }
    else {
      past_matches.push_back({begin_line, begin_col, end_line, end_col});
    }

    const Decl* body_decl = result.Nodes.getNodeAs<Decl>("body");
    const Stmt* body_stmt = result.Nodes.getNodeAs<Stmt>("body");

    bool body_decl_valid = true;
    bool body_stmt_valid = true;

    if (!body_decl || !context->getSourceManager().isWrittenInMainFile(body_decl->getBeginLoc())) {
      // printf("ERROR: invalid body\n");
      // return;
      body_decl_valid = false;
    }
    if (!body_stmt || !context->getSourceManager().isWrittenInMainFile(body_stmt->getBeginLoc())) {
      // printf("ERROR: invalid body\n");
      // return;
      body_stmt_valid = false;
    }

    if (!body_decl_valid && !body_stmt_valid) {
      printf("ERROR: invalid matcher body\n");
      return;
    }
    // printf("function body\n");
    // body->dump();

    // std::vector<std::string> literals;

    BuildMatcherVisitor visitor(context, clang_rewrite_literals,
      is_internal_matcher, internal_bindings);

    if (body_stmt_valid) {
      if (const CompoundStmt* body = dyn_cast<CompoundStmt>(body_stmt)) {
        if (body->size() == 1) {
          body->body_front()->dump();
          visitor.TraverseStmt(const_cast<Stmt*>(body->body_front()));
        }
        else {
          printf("WARNING: matcher generation for more than one statement is not "
            "fully implemented and may produce incorrect or invalid results.\n");
          // TODO: figure out multiple statements. ideas:
          // possibly do the compoundStmt thing but bind matchers for hasAnySubstmt
          //    to s1, s2, etc and then verify that loc(s1) < loc(s2) < ...
          // if we want to allow for intervening statements,
          //    loc(s1) < loc(s2) < loc(s3) is good
          // if we have s1; sa; s2; s3 that holds but if s1, s2, and s3 are
          //    reordered at all it'll break
          // if we don't allow intervening statements, we'd need the strict
          //    ordering and something like end(s1) = start(s2) and
          //    end(s2) = start(s3) in addition
          visitor.TraverseStmt(const_cast<CompoundStmt*>(body));
        }
      }
      else {
        visitor.TraverseStmt(const_cast<Stmt*>(body_stmt));
      }
    }
    else if (body_decl_valid) {
      printf("WARNING: matcher generation for declarations is not fully "
             "implemented and may produce incorrect or invalid results.\n");
      visitor.TraverseDecl(const_cast<Decl*>(body_decl));
    }


    Node* matcher = visitor.get_matcher();

    printf("TREE STUFF\n");
    matcher->dump();

    printf("AFTER CLEANING\n");
    matcher->clean_fake_nodes();
    matcher->dump();

    printf("ACTUAL MATCHER\n");
    VariantMatcher varmatcher = make_matcher(matcher, 0);

    std::optional<DynTypedMatcher> dynmatcher = varmatcher.getSingleMatcher();
    if (dynmatcher && decl_valid) {
      MatcherWrapper<DynTypedMatcher>* m = new MatcherWrapper<DynTypedMatcher>(*dynmatcher, matcher_name,
        context->getSourceManager().getFilename(decl->getBeginLoc()).str(),
        begin_line, begin_col);
      if (is_internal_matcher) {
        internal_matchers.push_back(m);
      }
      else {
        user_matchers.push_back(m);
      }

    }
    else if (dynmatcher && stmt_valid) {
      MatcherWrapper<DynTypedMatcher>* m = new MatcherWrapper<DynTypedMatcher>(*dynmatcher, matcher_name,
        context->getSourceManager().getFilename(stmt->getBeginLoc()).str(),
        begin_line, begin_col);
      if (is_internal_matcher) {
        internal_matchers.push_back(m);
      }
      else {
        user_matchers.push_back(m);
      }
    }
    else {
      printf("ERROR: ambiguous matcher\n");
    }
    matcher->clean_tree();
  }
};

}
} //namespaces

#endif //CLANG_MATCHER_GEN_CALLBACK_H
