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

using MT = MatcherType;

DynTypedMatcher rettest =
  returnStmt(
    hasReturnValue(
      ignoringParenImpCasts(
        allOf(
          hasType(asString("int")),
          expr().bind("x")
        )
      )
    )
  );

class BuildMatcherVisitor : public RecursiveASTVisitor<BuildMatcherVisitor> {
public:
  explicit BuildMatcherVisitor(ASTContext* context, std::vector<std::string> literals)
    : context(context), literals(literals) {}


    Node* get_matcher() {
      return root;
    }

    bool is_literal(NamedDecl* decl) {
      printf("BUT IS IT LITERAL\n");
      DeclContext* con = decl->getDeclContext();
      if (auto ns = dyn_cast<NamespaceDecl>(con)) {
        printf("NAMESPACE\n");
        // ns->dump();
        if (ns->getNameAsString() == "clang_rewrite_literals") {
          printf("%s is in literal ns\n", ns->getNameAsString().c_str());
          return true;
        }
      }
      if (std::find(literals.begin(), literals.end(), decl->getNameAsString()) != literals.end() ||
          std::find(literals.begin(), literals.end(), decl->getQualifiedNameAsString()) != literals.end()) {
        printf("%s is in list of literals\n", decl->getNameAsString().c_str());
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

    bool VisitCallExpr(CallExpr* call) {
      // short circuit to not double up, yay class inheritance
      if (isa<CUDAKernelCallExpr>(call)) {
        return true;
      }
      FunctionDecl* callee = call->getDirectCallee();
      if (callee != nullptr) {
        // plus 1 for callee
        add_node(MT::callExpr, "callExpr()", getNumChildren(call));
        add_node(MT::callee, "callee()", 1);
        add_node(MT::functionDecl, "functionDecl()", 0);
        if (is_literal(callee)) {
          set_is_literal(true);
          set_name(callee->getNameAsString());
        }
        else {
          bind_to(callee->getNameAsString());
        }
        update_tree(0);
      }
      else {
        add_node(MT::callExpr, "callExpr()", getNumChildren(call));
        update_tree(getNumChildren(call));
      }
      return true;
    }

    bool VisitCompoundStmt(CompoundStmt* comp) {
      add_node(MT::compoundStmt, "compountStmt()", getNumChildren(comp));
      update_tree(getNumChildren(comp));
      return true;
    }

    bool VisitCUDAKernelCallExpr(CUDAKernelCallExpr* call) {
      CallExpr* conf = call->getConfig();
      printf("KERNEL CONF\n");
      conf->dump();

      FunctionDecl* kern = call->getDirectCallee();
      if (kern != nullptr) {
        // plus 1 for callee
        add_node(MT::cudaKernelCallExpr, "cudaKernelCallExpr()", getNumChildren(call));
        add_node(MT::callee, "callee()", 1);
        add_node(MT::functionDecl, "functionDecl()", 0);
        if (is_literal(kern)) {
          set_is_literal(true);
          set_name(kern->getNameAsString());
        }
        else {
          bind_to(kern->getNameAsString());
        }
        update_tree(0);
      }
      else {
        add_node(MT::cudaKernelCallExpr, "cudaKernelCallExpr()", getNumChildren(call));
        update_tree(getNumChildren(call));
      }

      return true;
    }

    bool VisitCXXConstructExpr(CXXConstructExpr* expr) {
      if (expr->isElidable()) {
        printf("is elidable\n");
      }
      std::string ty = expr->getType().getAsString();
      //this needs to be put on the *child* of the cast, not the cast itself
      set_type_on_child(ty);
      return true;
    }

    bool VisitCXXFunctionalCastExpr(CXXFunctionalCastExpr* cast) {
      std::string ty = cast->getTypeAsWritten().getAsString();
      //this needs to be put on the *child* of the cast, not the cast itself
      set_type_on_child(ty);
      return true;
    }

    bool VisitDeclRefExpr(DeclRefExpr* ref) {
      ValueDecl* decl = ref->getDecl();
      std::string name = decl->getNameAsString();

      add_node(MT::declRefExpr, "declRefExpr()", getNumChildren(ref) + 1);
      set_ignore_casts(true);
      if (is_literal(ref)) {
        set_is_literal(true);
        add_node(MT::to, "to()", 1);
        add_node(MT::valueDecl, "valueDecl()", 0);
        set_name(name);
        std::string ty = decl->getType().getAsString();
        set_type(ty);
        update_tree(0);
      }
      else {
        bind_to(name);
      }

      // if it's already been given a type by nodes higher up (eg, cxxFunctionalCastExpr)
      // don't overwrite that; need highest level type to match
      // if (!has_type() && decl->getType()->getTypeClass() != clang::Type::TypeClass::Auto) {
      //   std::string type = decl->getType().getAsString();
      //   set_type(type);
      // }
      update_tree(getNumChildren(ref));
      return true;
    }

    bool VisitIntegerLiteral(IntegerLiteral* lit) {
      add_node(MT::integerLiteral, "integerLiteral()", 1);
      add_node(MT::equals, "equals()", 0);
      add_arg((int) lit->getValue().getSExtValue());
      update_tree(0);
      return true;
    }

    bool VisitImplicitCastExpr(ImplicitCastExpr* expr) {
      std::string ty = expr->getType().getAsString();
      //this needs to be put on the *child* of the cast, not the cast itself
      set_type_on_child(ty);
      return true;
    }

    bool VisitReturnStmt(ReturnStmt* ret) {
      if (ret->getRetValue()) {
        add_node(MT::returnStmt, "returnStmt()", 1);
        std::string type = ret->getRetValue()->getType().getAsString();
        add_node(MT::hasReturnValue, "hasReturnValue()", getNumChildren(ret));
        set_type(type);
        update_tree(getNumChildren(ret));
      }
      else {
        add_node(MT::returnStmt, "returnStmt()", getNumChildren(ret));
        update_tree(getNumChildren(ret));
      }
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
  int added_children = 0;
  bool pending_type = false;
  std::string pending_type_str = "";

  void update_tree(int children) {
    // if it's a leaf, set the current node to the last branch point and maybe pop it
    if (children == 0) {
      current = branch_points.back().first;
      if (added_children == branch_points.back().second) {
        branch_points.pop_back();
        added_children = 0;
      }
    }
  }

  void add_node(MatcherType sm, std::string code, int children) {
    Node* temp = new Node(sm, code);
    // if the tree is empty
    if (root == nullptr) {
      root = temp;
      current = root;
      current->parent = nullptr;
      bind_to("clang_rewrite_top_level_match");
      handle_pending();
      branch_points.push_back(std::pair<Node*, int>(current, children));
      return;
    }
    // if this has multiple children, push it onto the branch stack
    if (children > 1) {
      current->add_child(current, temp);
      temp->parent = current;
      current = temp;
      handle_pending();
      branch_points.push_back(std::pair<Node*, int>(current, children));
    }
    // if it's a leaf, we've finished adding this child, increment;
    // actually popping from branch_points is handled by update_tree because
    // we might have other things to do to this node and that has to wait
    else if (children == 0) {
      current->add_child(current, temp);
      temp->parent = current;
      current = temp;
      added_children++;
      handle_pending();
    }
    // children == 1; stick
    else {
      current->add_child(current, temp);
      temp->parent = current;
      current = temp;
      handle_pending();
    }
  }

  void handle_pending() {
    if (pending_type) {
      set_type(pending_type_str);
      pending_type = false;
      pending_type_str = "";
    }
  }

  void set_ignore_casts(bool b) {
    current->ignore_casts = b;
  }

  void bind_to(std::string name) {
    current->bound = true;
    current->bound_name = name;
  }

  void set_type(std::string type) {
    if (!current->has_type) {
      current->has_type = true;
      current->type = type;
    }
    // else {
    //   printf("WARNING: would overwrite %s with %s\n", current->type.c_str(), type.c_str());
    // }
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

  bool has_type() {
    return current->has_type;
  }

  void set_name(std::string name) {
    current->has_name = true;
    current->name = name;
  }

  void set_is_literal(bool b) {
    current->is_literal = b;
  }

  void add_arg(VariantValue arg) {
    current->args.push_back(arg);
  }
};


DeclarationMatcher matcher =
  functionDecl(allOf(
    hasAttr(attr::Matcher),
    hasBody(compoundStmt(
      hasAnySubstatement(attributedStmt(allOf(
        isAttr(attr::MatcherBlock),
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

  void run(const MatchFinder::MatchResult& result) override {
    printf("found matcher\n");
    context = result.Context;

    const FunctionDecl* func = result.Nodes.getNodeAs<FunctionDecl>("matcher");

    if (!func || !context->getSourceManager().isWrittenInMainFile(func->getBeginLoc())) {
      printf("ERROR: invalid matcher definition\n");
      return;
    }
    printf("full function\n");
    func->dump();

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
    printf("function body\n");
    body->dump();

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

    // printf(":BIRBSCREM:\n");
    // Node* testtree = new Node(MT::cudaKernelCallExpr, "cudaKernelCallExpr");
    // testtree->bound = true;
    // testtree->bound_name = "clang_rewrite_top_level_match";
    // Node* arg1 = new Node(MT::declRefExpr, "declRefExpr");
    // arg1->bound = true;
    // arg1->bound_name = "arg1";
    // arg1->ignore_casts = true;
    // arg1->has_type = true;
    // arg1->type = "float *";
    // testtree->add_child(testtree, arg1);
    // Node* arg2 = new Node(MT::declRefExpr, "declRefExpr");
    // arg2->has_name = true;
    // arg2->name = "arg2";
    // arg2->ignore_casts = true;
    // arg2->has_type = true;
    // arg2->type = "float *";
    // arg2->is_literal = true;
    // testtree->add_child(testtree, arg2);
    //
    // testtree->dump();
    //
    // VariantMatcher testmatcher = make_matcher(testtree, 0);
    //
    // llvm::Optional<DynTypedMatcher> testdynmatcher = testmatcher.getSingleMatcher();
    // if (testdynmatcher) {
    //   printf("YAY IT WORKY\n");
    // }
    // else {
    //   printf("OH NOES :<\n");
    // }

    Node* matcher = visitor.get_matcher();

    printf("TREE STUFF\n");
    matcher->dump();

    printf("ACTUAL MATCHER\n");
    VariantMatcher varmatcher = make_matcher(matcher, 0);

    printf("TYPES???\n");
    if (varmatcher.hasTypedMatcher<DynTypedMatcher>()) {
      printf("dyntype okay!\n");
    }
    if (varmatcher.hasTypedMatcher<Expr>()) {
      printf("expr okay!\n");
    }
    if (varmatcher.hasTypedMatcher<Decl>()) {
      printf("Decl okay!\n");
    }
    if (varmatcher.hasTypedMatcher<Stmt>()) {
      printf("stmt okay!\n");
    }
    if (varmatcher.hasTypedMatcher<CUDAKernelCallExpr>()) {
      printf("cudaKernelCallExpr okay!\n");
    }
    printf("END TYPES???\n");

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

#endif
