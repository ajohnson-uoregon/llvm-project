# clang-rewrite Readme

The ``clang-rewrite`` tool lives in ``clang-tools-extra/clang-rewrite``.
The main file is ``ClangRewrite.cpp``, which contains only the ``main()`` function;
most of the real code is in ``RewriteCallback.h``, ``MatcherGenCallback.h``,
``NewCodeCallback.h``, and ``ConstructMatchers.cpp``.

The code that finds ``[[clang::matcher]]`` functions and generates the AST matchers
is in ``MatcherGenCallback.h`` and ``ConstructMatchers.h``/``.cpp``. AST matchers are
stored in MatcherWrapper objects (unsurprisingly, in ``MatcherWrapper.h``) so
we can keep some extra information around for when rewriting actually
happens.

The code that finds the modifiers and figures out what the user wants them
to do is in ``NewCodeCallback.h`` and ``CodeAction.h``.

The code that handles rewriting and source-to-source transformation is in
``RewriteCallback.h``.

Most of this tool functions via callbacks that run during AST traversal.

An example of the syntax expected (still a work in progress) is in
``tests/new.cpp``.
