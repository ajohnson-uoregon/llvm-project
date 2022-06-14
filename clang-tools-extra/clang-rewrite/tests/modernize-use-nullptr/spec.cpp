template <typename T>
[[clang::matcher("nullptr-decl")]]
auto null_match() {
  [[clang::matcher_block]]
  {
    T* var = 0;
  }
}

template <typename T>
[[clang::replace("nullptr-decl")]]
auto null_replace() {
  [[clang::matcher_block]]
  {
    T* var = nullptr;
  }
}

template <typename T>
[[clang::matcher("nullptr-asgn")]]
auto null2_match() {
  T* var = nullptr;
  [[clang::matcher_block]]
  {
    var = 0;
  }
}

template <typename T>
[[clang::replace("nullptr-asgn")]]
auto null2_replace() {
  T* var = nullptr;
  [[clang::matcher_block]]
  {
    var = nullptr;
  }
}

template <typename T>
[[clang::matcher("nullptr-ret")]]
T* null3_match() {
  [[clang::matcher_block]]
  {
    return 0;
  }
}

template <typename T>
[[clang::replace("nullptr-ret")]]
T* null3_replace() {
  [[clang::matcher_block]]
  {
    return nullptr;
  }
}
