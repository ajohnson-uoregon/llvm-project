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

#include <string>
#include <vector>
#include <unordered_map>

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
  explicit BuildMatcherVisitor(ASTContext* context)
    : context(context) {}


    Node* get_matcher() {
      return root;
    }

    // TODO: placeholder until we actually figure out literals
    bool is_literal(Stmt* stmt) {
      return false;
    }

    int getNumChildren(Stmt* stmt) {
      int num_children = 0;
      for (auto iter = stmt->child_begin(); iter != stmt->child_end(); iter++) {
        num_children++;
      }
      return num_children;
    }

    bool VisitCallExpr(CallExpr* call) {
      FunctionDecl* callee = call->getDirectCallee();
      if (callee != nullptr) {
        // plus 1 for callee
        add_node(MT::callExpr, "callExpr()", getNumChildren(call) +1);
        add_node(MT::callee, "callee()", 1);
        add_node(MT::functionDecl, "functionDecl()", 0);
        set_name(callee->getNameAsString());
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

    bool VisitCXXConstructExpr(CXXConstructExpr* expr) {
      if (expr->isElidable()) {
        printf("is elidable\n");
      }
      std::string ty = expr->getType().getAsString();
      //this needs to be put on the *child* of the cast, not the cast itself
      add_type_to_child(ty);
      return true;
    }

    bool VisitCXXFunctionalCastExpr(CXXFunctionalCastExpr* cast) {
      std::string ty = cast->getTypeAsWritten().getAsString();
      //this needs to be put on the *child* of the cast, not the cast itself
      add_type_to_child(ty);
      return true;
    }

    bool VisitDeclRefExpr(DeclRefExpr* ref) {
      ValueDecl* decl = ref->getDecl();
      std::string name = decl->getNameAsString();

      add_node(MT::declRefExpr, "declRefExpr()", getNumChildren(ref));
      bind_to(name);
      set_ignore_casts(true);
      if (is_literal(ref)) {
        set_is_literal(true);
      }

      // if it's already been given a type by nodes higher up (eg, cxxFunctionalCastExpr)
      // don't overwrite that; need highest level type to match
      if (!has_type() && decl->getType()->getTypeClass() != clang::Type::TypeClass::Auto) {
        std::string type = decl->getType().getAsString();
        add_type(type);
      }
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

    // bool VisitImplicitCastExpr(ImplicitCastExpr* expr) {
    //   set_ignore_casts(true);
    //   return true;
    // }

    bool VisitReturnStmt(ReturnStmt* ret) {
      if (ret->getRetValue()) {
        add_node(MT::returnStmt, "returnStmt()", 1);
        std::string type = ret->getRetValue()->getType().getAsString();
        add_node(MT::hasReturnValue, "hasReturnValue()", getNumChildren(ret));
        add_type(type);
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
      bind_to("match");
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
      add_type(pending_type_str);
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

  void add_type(std::string type) {
    current->has_type = true;
    current->type = type;
  }

  void add_type_to_child(std::string type) {
    pending_type = true;
    pending_type_str = type;
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

    BuildMatcherVisitor visitor(context);

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

#endif
