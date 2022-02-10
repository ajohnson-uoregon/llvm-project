#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchersInternal.h"

#include "clang/ASTMatchers/Dynamic/Registry.h"

#include "ConstructMatchers.h"

#include <vector>
#include <string>

using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::ast_matchers::dynamic;

using ast_matchers::internal::Matcher;

using MT = MatcherType;
using R = clang::ast_matchers::dynamic::Registry;

std::vector<ParserValue> Args() { return std::vector<ParserValue>(); }
std::vector<ParserValue> Args(const VariantValue &Arg1) {
  std::vector<ParserValue> Out(1);
  Out[0].Value = Arg1;
  return Out;
}
std::vector<ParserValue> Args(const VariantValue &Arg1,
                              const VariantValue &Arg2) {
  std::vector<ParserValue> Out(2);
  Out[0].Value = Arg1;
  Out[1].Value = Arg2;
  return Out;
}
std::vector<ParserValue> Args(std::vector<VariantValue> args) {
  std::vector<ParserValue> out(args.size());
  for (unsigned int i = 0; i < args.size(); i++) {
    out[i].Value = args[i];
  }
  return out;
}

std::string VariantValue_asString(VariantValue val, bool dump_matcher) {
  if (val.isBoolean()) {
    return "boolean: " + std::to_string(val.getBoolean());
  }
  else if (val.isDouble()) {
     return "double: " + std::to_string(val.getDouble());
  }
  else if (val.isUnsigned()) {
    return "unsigned: " + std::to_string(val.getUnsigned());
  }
  else if (val.isString()) {
    return "string: " + val.getString();
  }
  else if (val.isNodeKind()) {
    return "AST node: " + val.getNodeKind().asStringRef().str();
  }
  else if (val.isMatcher()) {
    if (dump_matcher) {
      return "matcher: " + val.getMatcher().getTypeAsString();
    }
    else {
      return "matcher";
    }
  }
  else {
    return "unknown/bad value";
  }
}


// make matchers for non-bound nodes
VariantMatcher constructMatcher(StringRef MatcherName, int tab,
                                Diagnostics *Error = nullptr) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  llvm::Optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructMatcher(*Ctor, {}, Args(), Error);
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made matcher (1) %s\n", MatcherName.str().c_str());
  return Out;
}

VariantMatcher constructMatcher(StringRef MatcherName,
                                const VariantValue &Arg1,
                                int tab,
                                Diagnostics *Error = nullptr) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  llvm::Optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructMatcher(*Ctor, {}, Args(Arg1), Error);
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("  with arg %s\n", VariantValue_asString(Arg1, false).c_str());
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made matcher (2) %s\n", MatcherName.str().c_str());
  return Out;
}

VariantMatcher constructMatcher(StringRef MatcherName,
                                const VariantValue &Arg1,
                                const VariantValue &Arg2,
                                int tab,
                                Diagnostics *Error = nullptr) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  llvm::Optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructMatcher(*Ctor, {}, Args(Arg1, Arg2), Error);
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("  with arg %s\n", VariantValue_asString(Arg1, false).c_str());
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("  with arg %s\n", VariantValue_asString(Arg2, false).c_str());
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made matcher (3) %s\n", MatcherName.str().c_str());
  return Out;
}

VariantMatcher constructMatcher(StringRef MatcherName,
                                std::vector<VariantValue> args,
                                int tab,
                                Diagnostics* Error = nullptr) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  llvm::Optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructMatcher(*Ctor, {}, Args(args), Error);
  }
  for (auto arg : args) {
    for (int i = 0; i < tab; i++) {
      printf("  ");
    }
    printf("  with arg %s\n", VariantValue_asString(arg, false).c_str());
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made matcher (4) %s\n", MatcherName.str().c_str());
  return Out;
}


// make matchers for bound nodes
VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
                                     int tab,
                                     Diagnostics *Error = nullptr) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  llvm::Optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructBoundMatcher(*Ctor, {}, BoundName, Args(), Error);
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made bound matcher (1) %s (%s)\n", MatcherName.str().c_str(), BoundName.str().c_str());
  return Out;
}

VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
                                     const VariantValue &Arg1,
                                     int tab,
                                     Diagnostics *Error = nullptr) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  llvm::Optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructBoundMatcher(*Ctor, {}, BoundName, Args(Arg1), Error);
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("  with arg %s\n", VariantValue_asString(Arg1, false).c_str());
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made bound matcher (2) %s (%s)\n", MatcherName.str().c_str(), BoundName.str().c_str());
  return Out;
}

VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
                                     const VariantValue &Arg1,
                                     const VariantValue &Arg2,
                                     int tab,
                                     Diagnostics *Error = nullptr) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  llvm::Optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructBoundMatcher(*Ctor, {}, BoundName, Args(Arg1, Arg2), Error);
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("  with arg %s\n", VariantValue_asString(Arg1, false).c_str());
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("  with arg %s\n", VariantValue_asString(Arg2, false).c_str());
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made bound matcher (3) %s (%s)\n", MatcherName.str().c_str(), BoundName.str().c_str());
  return Out;
}

VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
                                     std::vector<VariantValue> args,
                                     int tab,
                                     Diagnostics* Error = nullptr) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  llvm::Optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructBoundMatcher(*Ctor, {}, BoundName, Args(args), Error);
  }
  for (auto arg : args) {
    for (int i = 0; i < tab; i++) {
      printf("  ");
    }
    printf("  with arg %s\n", VariantValue_asString(arg, false).c_str());
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made matcher (4) %s (%s)\n", MatcherName.str().c_str(), BoundName.str().c_str());
  return Out;
}

// mostly copy-paste from handle_bindable_node but need to add hasAnySubstatement
VariantMatcher handle_compoundStmt(Node* root, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //       constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }
  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->name), level+5));
  }

  if (root->children) {
    for (Node* child = root->children; child != nullptr; child = child->next_sibling) {
      child_matchers.push_back(constructMatcher("hasAnySubstatement",
          make_matcher(child, level+6), level+5));
    }
  }
  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  if (child_matchers.size() > 1) {
    if (root->ignore_casts) {
      //TODO will we ever have ignore_casts on a compoundStmt? probably not,
      // but do we still want to have ignoringParenImpCasts on the outside?
      if (root->bound) {
        return constructBoundMatcher("compoundStmt", StringRef(root->bound_name),
                constructMatcher("ignoringParenImpCasts",
                  constructMatcher("allOf", child_matchers, level+3), level+2), level+1);
      }
      else {
        return constructMatcher("compoundStmt",
                constructMatcher("ignoringParenImpCasts",
                  constructMatcher("allOf", child_matchers, level+3), level+2), level+1);
      }
    }
    else { // no ignore casts
      if (root->bound) {
        return constructBoundMatcher("compoundStmt", StringRef(root->bound_name),
                constructMatcher("allOf", child_matchers, level+2), level+1);
      }
      else {
        return constructMatcher("compoundStmt",
                constructMatcher("allOf", child_matchers, level+2), level+1);
      }
    } // ignore_casts
  }
  else { // child_matchers.size() == 1
    if (root->ignore_casts) {
      if (root->bound) {
        return constructBoundMatcher("compoundStmt", StringRef(root->bound_name),
                constructMatcher("ignoringParenImpCasts", child_matchers[0], level+2), level+1);
      }
      else {
        return constructMatcher("compoundStmt",
                constructMatcher("ignoringParenImpCasts", child_matchers[0], level+2), level+1);
      }
    }
    else { // no ignore casts
      if (root->bound) {
        return constructBoundMatcher("compoundStmt", StringRef(root->bound_name), child_matchers[0], level+1);
      }
      else {
        return constructMatcher("compoundStmt", child_matchers[0], level+1);
      }
    } // ignore_casts
  } // child_matchers.size()
}

VariantMatcher handle_declRefExpr(Node* root, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  std::string name = "expr";

  // if this is a literal node, we want to match the same actual reference,
  // so don't match a generic expr, match the ref
  // if the traversal bound it to a name, we want that to be the actual name
  // drop a warning if we're overwriting a name, which theoretically should
  // never happen but we should always check
  if (root->is_literal) {
    name = "declRefExpr";
    if (root->bound) {
      root->bound = false;
      if (root->has_name) {
        printf("WARNING: renaming node named %s to %s\n",
            root->name.c_str(), root->bound_name.c_str());
      }
      root->has_name = true;
      root->name = root->bound_name;
    }
  }

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //       constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }
  if (root->has_name) {
    // printf("WARNING: putting hasName inside expr()\n");
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->name), level+5));
  }

  if (root->children) {
    for (Node* child = root->children; child != nullptr; child = child->next_sibling) {
      child_matchers.push_back(make_matcher(child, level+5));
    }
  }
  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  // this swaps
  if (child_matchers.size() > 1) {
    if (root->ignore_casts) {
      if (root->bound) {
        return constructMatcher("ignoringParenImpCasts",
                constructBoundMatcher(name, StringRef(root->bound_name),
                  constructMatcher("allOf", child_matchers, level+3), level+2), level+1);
      }
      else {
        return constructMatcher("ignoringParenImpCasts",
                constructMatcher(name,
                  constructMatcher("allOf", child_matchers, level+3), level+2), level+1);
      }
    }
    else { // no ignore casts
      if (root->bound) {
        return constructBoundMatcher(name, StringRef(root->bound_name),
                constructMatcher("allOf", child_matchers, level+2), level+1);
      }
      else {
        return constructMatcher(name,
                constructMatcher("allOf", child_matchers, level+2), level+1);
      }
    } // ignore_casts
  }
  else { // child_matchers.size() == 1
    if (root->ignore_casts) {
      if (root->bound) {
        return constructMatcher("ignoringParenImpCasts",
                constructBoundMatcher(name, StringRef(root->bound_name),
                  child_matchers[0], level+2), level+1);
      }
      else {
        return constructMatcher("ignoringParenImpCasts",
                constructMatcher(name, child_matchers[0], level+2), level+1);
      }
    }
    else { // no ignore casts
      if (root->bound) {
        return constructBoundMatcher(name, StringRef(root->bound_name), child_matchers[0], level+1);
      }
      else {
        return constructMatcher(name, child_matchers[0], level+1);
      }
    } // ignore_casts
  } // child_matchers.size()
}

VariantMatcher handle_callExpr(Node* root, std::string call_type, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //       constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }
  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->name), level+5));
  }

  std::string callee_name = "";
  Node* callee = root->get_child_or_null(MT::callee);
  if (callee != nullptr) {        // functionDecl name
    printf("callee not null\n");
    Node* funcdecl = callee->get_child_or_null(MT::functionDecl);
    if (funcdecl != nullptr) {
      printf("funcdecl not null\n");
      if (funcdecl->is_named()) {
        callee_name = funcdecl->name;
      }
      else if (funcdecl->is_bound()) {
        callee_name = funcdecl->bound_name;
      }
      else {
        printf("WARNING: callee has no name\n");
      }
    }
  }

  if (root->children) {
    int argnum = 0; // SHRUG I guess the order works out?
    for (Node* child = root->children; child != nullptr; child = child->next_sibling) {
      if (child->matcher_type == MT::callee) {
        child_matchers.push_back(make_matcher(child, level+5));
      }
      // need to special case for cudaKernelCallExpr so the call to
      // __cudaPushCallConfiguration isn't treated as an argument
      else if (root->matcher_type == MT::cudaKernelCallExpr &&
               child->matcher_type == MT::callExpr) {
        Node* cuda_call_conf = child->get_child_or_null(MT::callee);
        if (cuda_call_conf && cuda_call_conf->children->name == "__cudaPushCallConfiguration") {
          // tree *should* look like
          // CallExpr <- child
          //  callee <- children[0]
          //    functionDecl  for __cudaPushCallConfiguration
          //  declRefExpr to function <- children[1]
          //  declRefExprs to at least 2 args <- children[2-5]
          Node* temp_child = child->children; // callee
          temp_child = temp_child->next_sibling; // declRefExpr to fxn
          temp_child = temp_child->next_sibling; // first arg
          if (temp_child) {
            child_matchers.push_back(constructMatcher("cudaGridDim",
              make_matcher(temp_child, level+6), level+5));
            temp_child = temp_child->next_sibling; // second arg (guaranteed)
            child_matchers.push_back(constructMatcher("cudaBlockDim",
              make_matcher(temp_child, level+6), level+5));
            temp_child = temp_child->next_sibling; // third arg or null
          }
          if (temp_child) {
            child_matchers.push_back(constructMatcher("cudaSharedMemPerBlock",
              make_matcher(temp_child, level+6), level+5));
            temp_child = temp_child->next_sibling; // fourth arg or null
          }
          else {
            child_matchers.push_back(constructMatcher("cudaSharedMemPerBlock",
              constructMatcher("cxxDefaultArgExpr", constructMatcher("anything", level+7), level+6), level+5));
          }
          if (temp_child) {
            child_matchers.push_back(constructMatcher("cudaStream",
              make_matcher(temp_child, level+6), level+5));
          }
          else {
            child_matchers.push_back(constructMatcher("cudaStream",
              constructMatcher("cxxDefaultArgExpr", constructMatcher("anything", level+7), level+6), level+5));
          }
        }
      }
      else {
        if (!child->self_or_child_bound_to(callee_name) &&
            !child->self_or_child_named(callee_name)) {
          child_matchers.push_back(constructMatcher("hasArgument", argnum,
              make_matcher(child, level+6), level+5));
          argnum++;
        }
      }
    }
    child_matchers.push_back(constructMatcher("argumentsGivenCountIs", VariantValue(argnum), level+5));
  }
  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  if (child_matchers.size() > 1) {
    if (root->ignore_casts) {
      if (root->bound) {
        return constructMatcher("ignoringParenImpCasts",
                constructBoundMatcher(call_type, StringRef(root->bound_name),
                  constructMatcher("allOf", child_matchers, level+3), level+2), level+1);
      }
      else {
        return constructMatcher("ignoringParenImpCasts",
                constructMatcher(call_type,
                  constructMatcher("allOf", child_matchers, level+3), level+2), level+1);
      }
    }
    else { // no ignore casts
      if (root->bound) {
        return constructBoundMatcher(call_type, StringRef(root->bound_name),
                constructMatcher("allOf", child_matchers, level+2), level+1);
      }
      else {
        return constructMatcher(call_type,
                constructMatcher("allOf", child_matchers, level+2), level+1);
      }
    } // ignore_casts
  }
  else { // child_matchers.size() == 1
    if (root->ignore_casts) {
      if (root->bound) {
        return constructMatcher("ignoringParenImpCasts",
                constructBoundMatcher(call_type, StringRef(root->bound_name),
                  child_matchers[0], level+2), level+1);
      }
      else {
        return constructMatcher("ignoringParenImpCasts",
                constructMatcher(call_type, child_matchers[0], level+2), level+1);
      }
    }
    else { // no ignore casts
      if (root->bound) {
        return constructBoundMatcher(call_type, StringRef(root->bound_name), child_matchers[0], level+1);
      }
      else {
        return constructMatcher(call_type, child_matchers[0], level+1);
      }
    } // ignore_casts
  } // child_matchers.size()
}

VariantMatcher handle_non_bindable_node(Node* root, StringRef name, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //     constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }
  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->name), level+5));
  }
  if (root->bound) {
    printf("WARNING: binding on a non bindable node\n");
  }

  if (root->children) {
    for (Node* child = root->children; child != nullptr; child = child->next_sibling) {
      child_matchers.push_back(make_matcher(child, level+5));
    }
  }
  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  if (child_matchers.size() > 1) {
    if (root->ignore_casts) {
      return constructMatcher("ignoringParenImpCasts",
              constructMatcher(name,
                constructMatcher("allOf", child_matchers, level+3), level+2), level+1);
    }
    else {
      return constructMatcher(name,
              constructMatcher("allOf", child_matchers, level+2), level+1);
    }
  } // child_matchers.size() > 1
  else { // child_matchers.size() == 1
    if (root->ignore_casts) {
      return constructMatcher("ignoringParenImpCasts",
              constructMatcher(name, child_matchers[0], level+2), level+1);
    }
    else {
      return constructMatcher(name, child_matchers[0], level+1);
    }
  } // child_matchers.size()
}

VariantMatcher handle_bindable_node(Node* root, StringRef name, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //     constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }

  if (root->has_type && root->matcher_type == MatcherType::varDecl) {
    child_matchers.push_back(constructMatcher("hasType",
      constructMatcher("asString", StringRef(root->type), level+6), level+5));
  }

  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->name), level+5));
  }

  if (root->children) {
    for (Node* child = root->children; child != nullptr; child = child->next_sibling) {
      child_matchers.push_back(make_matcher(child, level+5));
    }
  }
  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  if (child_matchers.size() > 1) {
    if (root->ignore_casts) {
      if (root->bound) {
        return constructMatcher("ignoringParenImpCasts",
                constructBoundMatcher(name, StringRef(root->bound_name),
                  constructMatcher("allOf", child_matchers, level+3), level+2), level+1);
      }
      else {
        return constructMatcher("ignoringParenImpCasts",
                constructMatcher(name,
                  constructMatcher("allOf", child_matchers, level+3), level+2), level+1);
      }
    }
    else { // no ignore casts
      if (root->bound) {
        return constructBoundMatcher(name, StringRef(root->bound_name),
                constructMatcher("allOf", child_matchers, level+2), level+1);
      }
      else {
        return constructMatcher(name,
                constructMatcher("allOf", child_matchers, level+2), level+1);
      }
    } // ignore_casts
  }
  else { // child_matchers.size() == 1
    if (root->ignore_casts) {
      if (root->bound) {
        return constructMatcher("ignoringParenImpCasts",
                constructBoundMatcher(name, StringRef(root->bound_name),
                  child_matchers[0], level+2), level+1);
      }
      else {
        return constructMatcher("ignoringParenImpCasts",
                constructMatcher(name, child_matchers[0], level+2), level+1);
      }
    }
    else { // no ignore casts
      if (root->bound) {
        return constructBoundMatcher(name, StringRef(root->bound_name), child_matchers[0], level+1);
      }
      else {
        return constructMatcher(name, child_matchers[0], level+1);
      }
    } // ignore_casts
  } // child_matchers.size()
}

VariantMatcher make_matcher(Node* root, int level) {
  switch(root->matcher_type) {
    case MT::callee:
      return handle_non_bindable_node(root, "callee", level);
      break;
    case MT::callExpr:
      return handle_callExpr(root, "callExpr", level);
      break;
    case MT::compoundStmt:
      return handle_compoundStmt(root, level);
      break;
    case MT::cudaKernelCallExpr:
      return handle_callExpr(root, "cudaKernelCallExpr", level);
      break;
    // case MT::cxxDefaultArgExpr:
    //   return handle_non_bindable_node(root, "cxxDefaultArgExpr", level);
    //   break;
    case MT::declRefExpr: //TODO: figure out literals and to()
      return handle_declRefExpr(root, level);
      break;
    case MT::equals:
      return handle_non_bindable_node(root, "equals", level);
      break;
    case MT::functionDecl:
      return handle_bindable_node(root, "functionDecl", level);
      break;
    case MT::hasInitializer:
      return handle_non_bindable_node(root, "hasInitializer", level);
      break;
    case MT::hasReturnValue:
      return handle_non_bindable_node(root, "hasReturnValue", level);
      break;
    case MT::hasType:
      return handle_non_bindable_node(root, "hasType", level);
      break;
    case MT::ignoringParenImpCasts:
      return handle_non_bindable_node(root, "ignoringParenImpCasts", level);
      break;
    case MT::integerLiteral:
      return handle_non_bindable_node(root, "integerLiteral", level);
      break;
    case MT::pointerType:
      return handle_bindable_node(root, "pointerType", level);
      break;
    case MT::pointee:
      return handle_bindable_node(root, "pointee", level);
      break;
    case MT::returnStmt:
      return handle_bindable_node(root, "returnStmt", level);
      break;
    case MT::to:
      return handle_non_bindable_node(root, "to", level);
      break;
    case MT::type:
      return handle_bindable_node(root, "type", level);
      break;
    case MT::valueDecl:
      return handle_bindable_node(root, "valueDecl", level);
      break;
    case MT::varDecl:
      return handle_bindable_node(root, "varDecl", level);
      break;
    default:
      printf("ERROR: unimplemented matcher type %d\n", (int) root->matcher_type);
      return VariantMatcher();
      break;
  }
}
