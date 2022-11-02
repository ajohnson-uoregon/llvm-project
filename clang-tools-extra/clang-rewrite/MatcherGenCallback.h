#ifndef CLANG_MATCHER_GEN_CALLBACK_H
#define CLANG_MATCHER_GEN_CALLBACK_H

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchersInternal.h"

#include "clang/Lex/Lexer.h"
#include "clang/Lex/Token.h"

#include "clang/AST/ASTConsumer.h"
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
  explicit BuildMatcherVisitor(ASTContext* context, std::vector<std::string> literals)
    : context(context), literals(literals) {}


    Node* get_matcher() {
      return root;
    }

    bool is_literal(NamedDecl* decl) {
      // printf("BUT IS IT LITERAL\n");
      DeclContext* con = decl->getDeclContext();
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

    int getNumChildren(Stmt* stmt) {
      int num_children = 0;
      for (auto iter = stmt->child_begin(); iter != stmt->child_end(); iter++) {
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
        else {
          fxn->bind_to(callee->getNameAsString());
        }
      }
      else {
        add_node(MT::callExpr, "callExpr()", getNumChildren(call));
      }
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

    bool VisitCXXFunctionalCastExpr(CXXFunctionalCastExpr* cast) {
      std::string ty = cast->getTypeAsWritten().getAsString();
      //this needs to be put on the *child* of the cast, not the cast itself
      set_type_on_child(ty);
      add_node(MT::fakeNode, "cxxFunctionalCastExpr", getNumChildren(cast));
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
        fxn->set_name(callee->getNameAsString(), callee->getNameAsString());
      }
      else {
        add_node(MT::callExpr, "cxxOperatorCallExpr()", getNumChildren(call));
      }
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
        declref->set_is_literal(true);
        add_node(MT::to, "to()", 1);
        Node* valuedecl = add_node(MT::valueDecl, "valueDecl()", 0);
        valuedecl->set_name(name, qualname);
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
            add_node(MT::anyOf, "anyOf()", 2);
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
              Node* lit = add_node(MT::compoundLiteral, "compoundLiteral()", getNumChildren(ref));
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

    bool VisitForStmt(ForStmt* forstmt) {
      add_node(MT::forStmt, "forStmt()", getNumChildren(forstmt));

      return true;
    }

    bool VisitParenExpr(ParenExpr* parens) {
      add_node(MT::parenExpr, "parenExpr()", 1);
      add_node(MT::hasSubExpr, "hasSubExpr()", getNumChildren(parens));

      return true;
    }

    bool VisitVarDecl(VarDecl* decl) {
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
      while (branch_points.back().second == 0) {
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


DeclarationMatcher matcher =
  functionDecl(allOf(
    hasAttr(attr::Matcher),
    hasBody(compoundStmt(
      hasAnySubstatement(attributedStmt(allOf(
        hasAttr(attr::MatcherBlock),
        hasSubStmt(compoundStmt(anything()).bind("body"))
      )))
    ))
  )).bind("matcher");

// std::unordered_map<std::string, VariantMatcher> stmt_matchers;
std::vector<MatcherWrapper<ast_matchers::internal::DynTypedMatcher> *> user_matchers;

class MatcherGenCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  std::string matcher_name;

  void onStartOfTranslationUnit() override {
    // dynamic::registerLocalMatchers();
  }

  void run(const MatchFinder::MatchResult& result) override {
    printf("found matcher\n");
    context = result.Context;

    const FunctionDecl* func = result.Nodes.getNodeAs<FunctionDecl>("matcher");

    if (!func || !context->getSourceManager().isWrittenInMainFile(func->getBeginLoc())) {
      printf("ERROR: invalid matcher definition\n");
      return;
    }
    // printf("full function\n");
    // func->dump();

    FullSourceLoc begin = context->getFullLoc(func->getBeginLoc());
    FullSourceLoc end = context->getFullLoc(func->getEndLoc());
    unsigned int begin_line = begin.getSpellingLineNumber();
    unsigned int begin_col = begin.getSpellingColumnNumber();
    unsigned int end_line = end.getSpellingLineNumber();
    unsigned int end_col = end.getSpellingColumnNumber();

    for (Attr* attr : func->attrs()) {
      if (attr->getKind() == attr::Matcher) {
        StringRef name = cast<MatcherAttr>(attr)->getMatcherName();
        matcher_name = name.str();
      }
    }
    printf("FOUND matcher %s at %d:%d - %d:%d\n", matcher_name.c_str(), begin_line, begin_col, end_line, end_col);

    const CompoundStmt* body = result.Nodes.getNodeAs<CompoundStmt>("body");
    if (!body || !context->getSourceManager().isWrittenInMainFile(body->getBeginLoc())) {
      printf("ERROR: invalid body\n");
      return;
    }
    // printf("function body\n");
    // body->dump();

    // std::vector<std::string> literals;

    BuildMatcherVisitor visitor(context, clang_rewrite_literals);

    if (body->size() == 1) {
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

    Node* matcher = visitor.get_matcher();

    printf("TREE STUFF\n");
    matcher->dump();

    printf("AFTER CLEANING\n");
    matcher->clean_fake_nodes();
    matcher->dump();

    printf("ACTUAL MATCHER\n");
    VariantMatcher varmatcher = make_matcher(matcher, 0);

    llvm::Optional<DynTypedMatcher> dynmatcher = varmatcher.getSingleMatcher();
    if (dynmatcher) {
      MatcherWrapper<DynTypedMatcher>* m = new MatcherWrapper<DynTypedMatcher>(*dynmatcher, matcher_name,
        context->getSourceManager().getFilename(func->getBeginLoc()).str(),
        begin_line, begin_col);
      user_matchers.push_back(m);
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
