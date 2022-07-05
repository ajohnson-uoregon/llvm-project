---
title: "MARTINI: The Little Match and Replace Tool for Automatic Code Rewriting"
tags:
  - Clang
  - meteprogramming
  - refactoring
  - AST matchers
authors:
  - name: Alister Johnson
    orcid: 0000-0002-7199-8221
    affiliation: 1
    corresponding: true
  - name: Camille Coti
    affiliation: 2
  - name: Allen D. Malony
    affiliation: 1
  - name: Johannes Doerfert
    orcid: 0000-0001-7870-8963
    affiliation: 3
affiliations:
  - name: University of Oregon, Eugene, OR, USA
    index: 1
  - name: Université du Québec à Montréal, Montréal, QC, Canada
    index: 2
  - name: Argonne National Laboratory, Lemont, IL, USA
    index: 3
date: 30 June 2022
bibliography: cite.bib

---

# Summary

Rewriting code for cleanliness, API changes, and new programming models is a
common, yet time-consuming task. Localized or syntax-based changes are often
mechanical and can be automated with text-based tools, like Unix's
`sed`. However, non-localized or semantic-based changes require specialized
tools that usually come with complex, hard-coded rules that require expertise
in compilers. This means existing techniques for code rewriting are either too
simple for complex tasks or too complex to be customized by non-expert users;
in either case, developers are often forced to manually update their code
instead.

This work presents MARTINI, a new approach to code rewriting built on the
Clang compiler, which exposes complex and semantic-driven rewrite capabilities
to users in a simple and natural way. Rewrite rules are expressed as a pair
of parameterized "before-and-after" code snippets in the source language, one
to describe what to match and one to describe what the replacement looks like.
Through this novel and user-friendly interface, programmers can automate
and customize complex code changes which require a deep understanding of
the language without any knowledge of compiler internals.


# Statement of Need

Once rewrites span code ranges or require semantic reasoning, text-based
tooling is inadequate or requires complex implementations (for example,
tracking balanced parentheses with extended regular expressions).
Traditionally, this is where compiler-based tooling comes in [@rose2].
The compiler's frontend has parsing and semantic analysis capabilities that
allow more complete understanding of the source code and, consequently,
semantic-based rewriting over most arbitrary code ranges. However, developing
and customizing such tooling requires a deep understanding of the compiler
and its rewriting infrastructure (if one exists), which restricts the
developer pool drastically [@xevolver; @omni]. Previously, as long as the
number of rewrites was small and customization was not required,
hard-coded rules in a compiler-based tool were sufficient.
Today, however, language standards are changing more rapidly and new
parallel programming models are constantly being developed.

Programmers who wish to keep their applications up-to-date must use a
streamlined refactoring process [@clangmr]. For instance, testing a new
programming model is an intriguing and often difficult proposition;
parts might be a simple matter of replacing one API with another, but
most often complex changes have to be made as well, especially if the
new model has any kind of parallelism. Other rewriting tasks, such as
adding instrumentation or error-checking asserts, are just as time-consuming
and important. These changes often follow patterns, however, and if
programmers are able to capture those patterns in some way, these tasks
seem like they _should_ be able to be automated.

### Example

As an example, consider the "simple" rewriting task done by the `clang-tidy`
rule ["modernize-use-nullptr"](https://clang.llvm.org/extra/clang-tidy/checks/modernize-use-nullptr.html).
This rule replaces constants, like `NULL` and `0`, assigned to pointer
variables with the C++11 `nullptr` keyword, which is both safer and more
readable. \autoref{fig:modernize_nullptr_example} illustrates the changes
`clang-tidy` can perform. The first replacement, where `a` is initialized
to `0`, could be done with a text-based tool, like `sed`, although
constructing a generic regular expression to match arbitrary types and
variable names could be tricky. However, the other two replacements are
difficult if not impossible
to handle without semantic context. The physical distance between the type
of the variable and the `0`-literal can cross file boundaries, and most
languages allow for various other complexities. This semantic context is
out of reach for purely text-based tools. Being built on the Clang compiler,
MARTINI has the context needed to emulate most of `clang-tidy`'s
"modernize-use-nullptr" rule using just the three matcher-replacer pairs in
\autoref{fig:martini_nullptr_example}. While `clang-tidy`'s rule is over 100
lines of complex code that requires extensive knowledge of Clang internals,
MARTINI can be understood by the average programmer.

![Example to showcase the "modernize-use-nullptr" `clang-tidy` rewrite
rule, which replaces `0`-literal pointers with `nullptr`.\label{fig:modernize_nullptr_example}](modernize-use-nullptr-ex.png)

### Related Work

Most previous work in automatic code rewriting relies on compiler experts
directly working with the code's abstract syntax tree (AST). ClangMR [@clangmr]
and the Clang Transformer library [@transformer] are similar code rewriting
tools implemented in Clang, but both of these use AST matchers (with a
few additions) as a user interface. MARTINI is designed to provide similar
functionality but be usable by non-compiler experts.

Other code rewriting frameworks include the ROSE compiler [@rose2],
Xevolver [@xevolver] (built on ROSE), and the Omni source-to-source
compiler [@omni]. These tools provide more low-level interfaces than ours,
and thus more precise control over rewriting, but at the cost of requiring
users to be compiler experts. Neither of these are very user-friendly,
as users have to directly describe AST manipulations and use syntax
specific to each tool. MARTINI, on the other hand, only requires knowledge
of C++ and the semantics of a few new attributes.

The most similar work to our own is Nobrainer [@nobrainer1; @nobrainer2],
which also uses C/C++ code snippets and AST matchers to match application
code and describe how to modify it, and inspired some of our user interface.
As the Nobrainer project has existed for longer than ours, it supports
more of the C++ standard. However, Nobrainer uses more restrictive and
specialized syntax and generally enforces more restrictions on
transformations than we do. They do this to ensure their transformations
are (type-)safe, but we opted to take a more lenient approach. For example, it's easy
to imagine cases where users may want to change the type of an expression, such as
testing multiple precision arithmetic, but this is nearly impossible
in Nobrainer. Nobrainer's design philosophy is to make
matchers as specific as possible and force users to add generality -
they assume all names in a matcher are literals unless they are specified
as parameters and do their best to enforce safety. Our philosophy is almost
precisely the opposite: our matchers are as general as possible and
users must add specificity, e.g., with literals, and we allow users to
define any transformations they wish with minimal restrictions on safety.
Nobrainer is also, sadly, not open-source.

![MARTINI's equivalent to `clang-tidy`'s "modernize-use-nullptr" rule, using abbreviated MARTINI syntax.\label{fig:martini_nullptr_example}](martini-nullptr-ex.png)


# References
