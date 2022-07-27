# clang-rewrite Readme

## How-To

A (slightly outdated) PDF of these instructions is available [here](https://github.com/ajohnson-uoregon/llvm-project/blob/feature-ajohnson/clang-tools-extra/clang-rewrite/Instructions.pdf).

### Getting Started

Required dependencies:
- [CMake](https://cmake.org/install/) ≥ 3.13.4

Optional dependencies:
- [Ninja](https://ninja-build.org/) build system

##### Building `clang-rewrite`/MARTINI:
1. Install CMake and Ninja (recommended for quicker build of LLVM, but not
required).
2. Clone our fork of the LLVM monorepo.
  - `git clone https://github.com/ajohnson-uoregon/llvm-project.git`
3. Check out `europar22-artifact` branch (for version used in that paper) or
  `feature-ajohnson` branch (for development version; may not always work).
  - `git checkout europar22-artifact`
4. Follow instructions to build LLVM, including `clang` and `clang-tools-extra`
projects. Full instructions: https://llvm.org/docs/GettingStarted.html. Short
instructions:
  - Enter `llvm-project` directory.
  - `mkdir build`
  - `cd build`
  - For Ninja (recommended):

        cmake -G Ninja \
        -DLLVM_TARGETS_TO_BUILD="X86;NVPTX;AMDGPU" \
        -DCMAKE_INSTALL_PREFIX="<install dir>" \
        -DCMAKE_BUILD_TYPE=RelWithDebInfo \
        -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra" \
        ../llvm

        ninja -j <N> install
  - For Unix make:

        cmake -G "Unix Makefiles" \
        -DLLVM_TARGETS_TO_BUILD="X86;NVPTX;AMDGPU" \
        -DCMAKE_INSTALL_PREFIX="<install dir>" \
        -DCMAKE_BUILD_TYPE=RelWithDebInfo \
        -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra" \
        ../llvm

        cmake --build . -j <N> --target install
5. The MARTINI/`clang-rewrite` executable will be in the install directory chosen
when building LLVM.

#### Notes on Build

- The majority of our contributions are in `llvm-project/clang-tools-extra/clang-rewrite`.
- LLVM/Clang is a _very_ large project, and will take several hours to build
even when done in parallel.
- Parallel builds are _highly_ recommended, but will use a large amount of memory when linking the final libraries and executables. The last approx. 500 targets may need to be built in serial if your machine has ≤24GB of memory.

### Instructions for Running Tests

These tests should reproduce the results from our EuroPar '22 paper. As of July 2022, we recommend running these tests with the version of the code from EuroPar,
as the `feature-ajohnson` branch is under active development and thus somewhat unstable and may not always work.

#### modernize-use-nullptr

In `llvm-project/clang-tools-extra/clang-rewrite/tests/modernize-use-nullptr`,
run:
- `clang-rewrite --inst-file=spec.cpp test.cpp --`

The file `spec.cpp` contains the matchers and replacers used to emulate
modernize-use-nullptr’s functionality. The file `test.cpp` contains the code
to be rewritten and the expected result.

The above command should only take a few seconds and produce a file named
`test.test_final.cpp` with the rewritten code (and expected result for comparison).
This example corresponds to the one presented in the paper’s Introduction.

#### Instrumentation

In `llvm-project/clang-tools-extra/clang-rewrite/tests/inst`, run:
- `clang-rewrite --inst-file=inst.cpp test.cpp -- --std=c++20`

The file `inst.cpp` contains the matchers and replacers used to instrument single argument function calls and lambdas. The file `test.cpp` contains the code to be
rewritten and the expected result.

The above command should only take a few seconds and produce a file named
`test.test_final.cpp` with the rewritten code (and expected result for comparison).
This example corresponds to the one presented in Section 3, the first case study
on instrumentation. (Note: There is a small bug in the rewriting infrastructure for the EuroPar '22 version of clang-rewrite that sometimes leaves an extra character behind in the output for this example. As of June 2022, the rewriting infrastructure is undergoing major improvements to make it less bug-prone going forward.)

#### HIPIFY

Dependencies:
- A machine with an AMD GPU and associated drivers and compilers. Our machine had:
  - two 14-core, hyperthreaded Intel Xeon(R) E5-2680v4 CPUs running at 2.40GHz
  - 128 GB of RAM
  - two AMD Instinct MI100 GPUs
  - `hipcc` 4.4.21432-f9dccde4 based on AMD Clang 13.0.0 and ROCm 4.5.2
- `hipify-perl` (we had the same version as `hipcc` above)
- `hipify-clang` (we used git hash `61241a4` and compiled with `gcc` 9.3.0)

Both `hipify-perl` and `hipify-clang` can be obtained from https://github.com/ROCm-Developer-Tools/HIPIFY.

##### Building AMD's HIPIFY

Short version of the instructions at the above link for building `hipify-clang` and `hipify-perl`:

1. Create a directory for HIPIFY and enter it:
  - `mkdir HIPIFY`
  - `cd HIPIFY`
2. Clone AMD’s repository and checkout the `rocm-4.5.2` branch (this is the version we used):
  - `git clone https://github.com/ROCm-Developer-Tools/HIPIFY.git`
  - `git checkout rocm-4.5.2`
3. In the top level `HIPIFY` directory (_not_ the `hipify` directory created by the clone) make directories for the build:
  - `mkdir build dist`
  - `cd build`
4. In the build directory, run cmake and make (note: you may have to install libtinfo-dev with your package manager):
  -
    ```
    cmake \
    -DCMAKE INSTALL PREFIX=../dist \
    -DCMAKE BUILD TYPE=Release \
    ../hipify
    ```
  - `make -j install`
5. The `hipify-clang` executable should now be in `HIPIFY/dist`. To generate `hipify-perl`:
  - `cd ../dist`
  - `./hipify-clang --perl`
6. `hipify-clang` and `hipify-perl` should now both be in the `dist` directory.

##### Running the tests

In `llvm-project/clang-tools-extra/clang-rewrite/tests/hipify`:

1. Unzip mini-nbody.zip, enter the `mini-nbody-master/cuda` directory.
2. Produce `hipify-perl` and/or `hipify-clang` versions of each test in `mini-nbody-master/cuda`, following directions here: https://github.com/ROCm-Developer-Tools/HIPIFY. (Note: You may have to manually delete the SHMOO `#ifdef`s, some versions of HIPIFY don’t handle them well.) Example commands:
  - `hipify-clang nbody-orig.cu -- -I..`
  - `perl hipify-perl nbody-orig.cu > nbody-orig.hip`
3. Produce MARTINI/`clang-rewrite` versions of the tests in `mini-nbody-master/cuda` by running, e.g.,
  - `clang-rewrite --inst-file=../../hipify.cpp nbody-orig.cu -- -I.. -I../.. -x cuda --std=c++20`
4. MARTINI/`clang-rewrite` versions with two times the number of threads
at kernel launch can be produced by replacing `hipify.cpp` in the above with
`hipify-x2-threads.cpp`.
5. Compile each test, e.g.,
  - `hipcc nbody-orig.cu.hip -I.. -o nbody-orig`
6. Run each test (e.g., `./nbody-orig`). Output should look something like this:
  ```
  Iteration 1: 0.499 seconds
  Iteration 2: 0.191 seconds
  Iteration 3: 0.191 seconds
  Iteration 4: 0.191 seconds
  Iteration 5: 0.191 seconds
  Iteration 6: 0.191 seconds
  Iteration 7: 0.191 seconds
  Iteration 8: 0.191 seconds
  Iteration 9: 0.203 seconds
  Iteration 10: 0.192 seconds
  300000 Bodies: average 467.571 Billion Interactions / second
  ```

##### Interpreting the Results

Times in Table 1 in the paper are reported in ms. The average and standard
deviation time in the table were calculated over the 10 iterations that each test
runs. The first two sets of results in the table (columns under MARTINI-HIPIFY
labeled "Unmodified" and "#Threads x2") were found using `clang-rewrite`
with `hipify.cpp` and `hipify-x2-threads.cpp`, respectively. We expect performance from `hipify.cpp` to always match performance from `hipify-clang` and
`hipify-perl`, since they should produce nearly identical code. We expect performance from `hipify-x2-threads.cpp` to be somewhat faster on large problem
sizes for all tests except `nbody-orig` (which is unoptimized and not expected to
parallelize well). How much faster will depend on the GPU.

### Notes on Running `clang-rewrite`

- The `--inst-file` argument is a holdover from when MARTINI/`clang-rewrite`
was envisioned as purely an instrumentation tool, and has been changed to
`--spec-file` in `feature-ajohnson`. It is still `--inst-file` in the EuroPar '22 version.
- The `--` at/near the end of the `clang-rewrite` (and `hipify-clang`) commands _is_ necessary; it is how Clang’s libtooling infrastructure detects which
commands are to be passed directly to the compiler, in lieu of reading from
a compilation database.
- As this is a prototype still in very active development, there is a decent
amount of debugging information dumped to `stdout` to assist in debugging.
If you run into any errors, please open an issue including the specification file, code file, and any output from `clang-rewrite`.
- Some of the example matchers and replacers in the paper were edited for
brevity/space, as mentioned in the paper. The matchers and replacers in the
artifact use the full syntax `clang-rewrite` currently expects. This syntax is subject to change.

## Source Files

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

## Contributing

If you'd like to contribute to this project, fork this repo and pull request. If your contribution is to portions of this project that have been upstreamed to LLVM/Clang already, follow their guildlines for contributions.

To report a bug or ask a question, email me (ajohnson (at) cs.uoregon.edu) or open an issue on github.
