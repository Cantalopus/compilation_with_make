# Documentation
```Bash
cmake --help-module CheckIncludeFile
```
[Click here](doc.md), to read the --help documentation
# What we've learned here:
- include(CheckIncludeFile) loads the module.
- check_include_file() tests whether a header can actually be included and compiled.
- try_compile() allows CMake to perform compilation tests during configuration.
- CMakeConfigureLog.yaml records these tests.
- Test results are stored in the CMake cache, including failed tests.
- -U selectively removes cache entries.
- --fresh discards the existing cache and associated configuration state.
- CMake variables and C preprocessor macros are independent.
- target_compile_definitions() provides a mechanism for communicating definitions to the compiler.