#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchersInternal.h"

#include "clang/ASTMatchers/Dynamic/Registry.h"

#include "ConstructMatchers.h"

#include <vector>

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
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made matcher (4) %s (%s)\n", MatcherName.str().c_str(), BoundName.str().c_str());
  return Out;
}

// mostly copy-paste from handle_bindable_node but need to add hasAnySubstatement
VariantMatcher handle_compoundStmt(Node* root, int level) {
  std::vector<VariantValue> child_matchers;

  if (root->has_type) {
    child_matchers.push_back(constructMatcher("hasType",
        constructMatcher("asString", StringRef(root->type), level+6), level+5));
  }
  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->name), level+5));
  }

  if (root->children.size() > 0) {
    for (Node* child : root->children) {
      child_matchers.push_back(constructMatcher("hasAnySubstatement",
          make_matcher(child, level+6), level+5));
    }
  }
  else {
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

  if (root->has_type) {
    child_matchers.push_back(constructMatcher("hasType",
        constructMatcher("asString", StringRef(root->type), level+6), level+5));
  }
  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->name), level+5));
  }

  if (root->children.size() > 0) {
    for (Node* child : root->children) {
      child_matchers.push_back(make_matcher(child, level+5));
    }
  }
  else {
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

VariantMatcher handle_non_bindable_node(Node* root, StringRef name, int level) {
  std::vector<VariantValue> child_matchers;

  if (root->has_type) {
    child_matchers.push_back(constructMatcher("hasType", constructMatcher("asString", StringRef(root->type), level+6), level+5));
  }
  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->name), level+5));
  }
  if (root->bound) {
    child_matchers.push_back(constructBoundMatcher("expr", StringRef(root->bound_name), level+5));
  }

  if (root->children.size() > 0) {
    for (Node* child : root->children) {
      child_matchers.push_back(make_matcher(child, level+5));
    }
  }
  else {
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

  if (root->has_type) {
    child_matchers.push_back(constructMatcher("hasType", constructMatcher("asString", StringRef(root->type), level+6), level+5));
  }
  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->name), level+5));
  }

  if (root->children.size() > 0) {
    for (Node* child : root->children) {
      child_matchers.push_back(make_matcher(child, level+5));
    }
  }
  else {
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
    case MT::compoundStmt:
      return handle_compoundStmt(root, level);
      break;
    case MT::returnStmt:
      return handle_bindable_node(root, "returnStmt", level);
      break;
    case MT::hasReturnValue:
      return handle_non_bindable_node(root, "hasReturnValue", level);
      break;
    case MT::declRefExpr: //TODO: make to() its own node and figure out literals
      return handle_declRefExpr(root, level);
      break;
    case MT::callExpr:
      return handle_bindable_node(root, "callExpr", level);
      break;
    default:
      printf("ERROR: unimplemented matcher type %d\n", (int) root->matcher_type);
      return VariantMatcher();
      break;
  }
}
