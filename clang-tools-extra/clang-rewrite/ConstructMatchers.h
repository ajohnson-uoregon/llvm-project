#ifndef CLANG_CONSTRUCT_MATCHERS_H
#define CLANG_CONSTRUCT_MATCHERS_H

#include "clang/ASTMatchers/Dynamic/Registry.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchersInternal.h"
#include "clang/ASTMatchers/Dynamic/VariantValue.h"

#include <string>
#include <algorithm>

using namespace clang::ast_matchers;
using namespace clang::ast_matchers::dynamic;

namespace clang {
namespace rewrite_tool {

enum class MatcherType {
  fakeNode,
  binaryOperator,
  callee,
  callExpr,
  compoundStmt,
  cudaKernelCallExpr,
  cxxConstructExpr,
  cxxDefaultArgExpr,
  cxxFunctionalCastExpr,
  cxxOperatorCallExpr,
  declRefExpr,
  equals,
  functionDecl,
  hasExpectedReturnType,
  hasInitializer,
  hasLHS,
  hasOperatorName,
  hasReturnValue,
  hasRHS,
  hasType,
  ignoringParenImpCasts,
  integerLiteral,
  pointerType,
  pointee,
  returnStmt,
  to,
  type,
  valueDecl,
  varDecl,
};

class Node {
public:
  MatcherType matcher_type;
  std::string matcher_string; // for debug/dumping purposes
  bool bound = false;
  std::string bound_name; // the name the matcher should be bound to
  bool has_name = false;
  std::string name; // the actual name of the thing, eg function name, var name
  bool has_type = false;
  std::string type;
  bool ignore_casts = false;
  bool is_literal = false;
  Node* children = nullptr; // start of linked list of children, managed by child->next_sibling
  Node* next_sibling = nullptr; // null when last child in list
  std::vector<VariantValue> args;
  Node* parent = nullptr;

  Node(MatcherType m, std::string ms) : matcher_type(m), matcher_string(ms) {}

  void add_child(Node* child) {
    if (this->children == nullptr) {
      this->children = child;
    }
    else {
      Node* temp = this->children;
      while (temp->next_sibling != nullptr) {
        temp = temp->next_sibling;
      }
      temp->next_sibling = child;
    }
    child->parent = this;
  }

  void set_ignore_casts(bool b) {
    this->ignore_casts = b;
  }

  void bind_to(std::string name) {
    // if the node is already bound, add sneaky copy with same matcher type bound
    // to the other name; allows for multiple names to be bound to the same node,
    // eg if the top level node (bound to "clang_rewrite_top_level_match") also
    // needs to be bound to something
    if (this->bound) {
      Node* copy = new Node(this->matcher_type, this->matcher_string + "_copy");
      copy->bound = true;
      copy->bound_name = name;
      this->add_child(copy);
    }
    else {
      this->bound = true;
      this->bound_name = name;
    }
  }

  bool is_bound() {
    return this->bound;
  }

  void set_type(std::string type) {
    this->has_type = true;
    this->type = type;
  }

  bool is_typed() {
    return this->has_type;
  }

  void set_name(std::string name) {
    this->has_name = true;
    this->name = name;
  }

  bool is_named() {
    return this->has_name;
  }

  void set_is_literal(bool b) {
    this->is_literal = b;
  }

  void add_arg(VariantValue arg) {
    this->args.push_back(arg);
  }

  Node* get_child_or_null(MatcherType type) {
    for (Node* child = this->children; child != nullptr; child = child->next_sibling) {
      if (child->matcher_type == type) {
        return child;
      }
    }
    return nullptr;
  }

  bool self_or_child_bound_to(std::string name) {
    if (this->bound && this->bound_name == name) {
      return true;
    }
    for (Node* child = this->children; child != nullptr; child = child->next_sibling) {
      if (child->self_or_child_bound_to(name)) {
        return true;
      }
    }
    return false;
  }

  bool self_or_child_named(std::string name) {
    if (this->has_name && this->name == name) {
      return true;
    }
    for (Node* child = this->children; child != nullptr; child = child->next_sibling) {
      if (child->self_or_child_named(name)) {
        return true;
      }
    }
    return false;
  }

  void clean_fake_nodes_help(Node* n) {
    if (n == nullptr) {
      return;
    }
    Node* prev_child = n->children;
    Node* current_child = n->children;
    Node* next_child;
    if (n->children) {
      next_child = n->children->next_sibling;
    }
    else {
      next_child = nullptr;
    }

    while (current_child) {
      if (current_child->matcher_type == MatcherType::fakeNode) {
        Node* first_grandchild = current_child->children;
        if (first_grandchild) {
          // printf("first gc exists: ");
          // first_grandchild->dump_node(0);
          if (prev_child != current_child) {
            // printf("not at start of children list, set prev_child->next_sibling to first gc\n");
            prev_child->next_sibling = first_grandchild;
          }
          else {
            // printf("at start of children list, set children to first gc\n");
            n->children = first_grandchild;
          }
          Node* temp_gc = first_grandchild;
          temp_gc->parent = n;
          while (temp_gc->next_sibling) {
            temp_gc->parent = n;
            temp_gc = temp_gc->next_sibling;
          }
          temp_gc->next_sibling = next_child;
        }
        else {
          // printf("has no grandchildren\n");
          if (prev_child != current_child) {
            // printf("not at start of children list, set prev_child->next_sibling to next_child\n");
            prev_child->next_sibling = next_child;
          }
          else {
            // printf("at start of children list, set children to next child\n");
            n->children = next_child;
          }

        }

        if (prev_child == current_child && first_grandchild) {
          prev_child = first_grandchild;
        }
        else {
          prev_child = n->children;
        }
        delete current_child;
        if (first_grandchild) {
          current_child = first_grandchild;
        }
        else {
          current_child = n->children;
        }

        if (current_child) {
          next_child = current_child->next_sibling;
        }
        else {
          next_child = nullptr;
        }

        clean_fake_nodes_help(current_child);
      }
      else {
        prev_child = current_child;
        current_child = current_child->next_sibling;
        if (current_child) {
          next_child = current_child->next_sibling;
        }

        clean_fake_nodes_help(current_child);
      }
    }
  }

  void clean_fake_nodes() {
    clean_fake_nodes_help(this);
  }

  void dump_help(Node* n, int tab_depth) {
    for (int i = 0; i < tab_depth; i++) {
      printf("   |");
    }
    printf("%s;", n->matcher_string.c_str());
    if (n->ignore_casts) {
      printf("  ignore casts;");
    }
    if (n->has_type) {
      printf("  has type %s;", n->type.c_str());
    }
    if (n->bound) {
      printf("  bound to %s;", n->bound_name.c_str());
    }
    if (n->has_name) {
      printf("  named %s;", n->name.c_str());
    }
    if (n->is_literal) {
      printf("  is literal;");
    }
    printf("\n");
    for (Node* child = n->children; child != nullptr; child = child->next_sibling) {
      dump_help(child, tab_depth+1);
    }
  }

  void dump_node(int tab_depth) {
    for (int i = 0; i < tab_depth; i++) {
      printf("    ");
    }
    printf("%s;", this->matcher_string.c_str());
    if (this->ignore_casts) {
      printf("  ignore casts;");
    }
    if (this->has_type) {
      printf("  has type %s;", this->type.c_str());
    }
    if (this->bound) {
      printf("  bound to %s;", this->bound_name.c_str());
    }
    if (this->has_name) {
      printf("  named %s;", this->name.c_str());
    }
    if (this->is_literal) {
      printf("  is literal;");
    }
    printf("\n");
  }

  void dump() {
    dump_help(this, 0);
  }

  void clean_tree() {
    Node* child = this->children;
    Node* temp = this->children;
    while (child) {
      temp = child->next_sibling;
      child->clean_tree();
      child = temp;
    }

    delete this;
  }
};

VariantMatcher constructMatcher(StringRef MatcherName, int tab,
                                Diagnostics *Error = nullptr);
VariantMatcher constructMatcher(StringRef MatcherName,
                                const VariantValue &Arg1,
                                int tab,
                                Diagnostics *Error = nullptr);
VariantMatcher constructMatcher(StringRef MatcherName,
                                const VariantValue &Arg1,
                                const VariantValue &Arg2,
                                int tab,
                                Diagnostics *Error = nullptr);
VariantMatcher constructMatcher(StringRef MatcherName,
                                std::vector<VariantValue> args,
                                int tab,
                                Diagnostics* Error = nullptr);

VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
                                     int tab,
                                     Diagnostics *Error = nullptr);
VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
                                     const VariantValue &Arg1,
                                     int tab,
                                     Diagnostics *Error = nullptr);
VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
                                     const VariantValue &Arg1,
                                     const VariantValue &Arg2,
                                     int tab,
                                     Diagnostics *Error = nullptr);
VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
                                     std::vector<VariantValue> args,
                                     int tab,
                                     Diagnostics* Error = nullptr);

VariantMatcher make_matcher(Node* root, int level);

}
} //namespace

#endif // CLANG_CONSTRUCT_MATCHERS_H
