# cpp-template

## Dependencies

* [clang 6+](https://clang.llvm.org/)
* [Conan](https://conan.io/)
* [CMake 3.15+](https://cmake.org/)
* [Doxygen](http://doxygen.nl/)
* [ccache](https://ccache.dev/)
* [Cppcheck](http://cppcheck.sourceforge.net/)
* [include-what-you-use](https://include-what-you-use.org/)
* [Ninja](https://ninja-build.org/)

## Build

Example:

```
export CC=clang
export CXX=clang++
mkdir build
cd build
ccmake -GNinja ..
ninja
```

## Sanitizer Runtime options

Example:

```
export ASAN_OPTIONS=detect_stack_use_after_return=1,detect_leaks=1
export UBSAN_OPTIONS=print_stacktrace=1
```

For nicer stack traces, `llvm-symbolizer` should be on your path.

