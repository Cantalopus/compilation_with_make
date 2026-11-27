cmake_minimum_required(VERSION 4.0)
project(source_compilation_tests 
            VERSION 0.0.0
            DESCRIPTION [[CheckCXXSourceCompiles module usage]]
            LANGUAGES CXX)

include(CheckCXXSourceCompiles)
include(CMakePrintHelpers)

check_cxx_source_compiles(
    [[
        int main()
        {
            return 0;
        }
    ]]
    TEST_ONE
)

check_cxx_source_compiles(
    [[
        int main()
        {
            return 42;
        }
    ]]
    TEST_TWO
)

check_cxx_source_compiles(
    [[
        int main()
        {
            return 10;
        }
    ]]
    TEST_VALID
)

check_cxx_source_compiles(
    [[
        int main()
        {
            return number;
        }
    ]]
    TEST_COMPILATION
)

check_cxx_source_compiles(
    [[
        int calculate();

        int main()
        {
            return calculate();
        }
    ]]
    TEST_LINKING
)

cmake_print_variables(
    TEST_VALID
    TEST_COMPILATION
    TEST_LINKING
)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

check_cxx_source_compiles(
    [[
        int calculate();

        int main()
        {
            return calculate();
        }
    ]]
    TEST_STATIC_LIBRARY
)

cmake_print_variables(
    TEST_LINKING
    TEST_STATIC_LIBRARY
)

unset(CMAKE_TRY_COMPILE_TARGET_TYPE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

check_cxx_source_compiles(
    [[
        template<typename T> 
        concept Number = requires(T a)
        {
            a + a;
        };

        int main()
        {
            return 0;
        }
    ]]
    CONCEPTS_WITH_CPP17
)

set(CMAKE_CXX_STANDARD 20)

check_cxx_source_compiles(
    [[
        template<typename T> 
        concept Number = requires(T a)
        {
            a + a;
        };

        int main()
        {
            return 0;
        }
    ]]
    CONCEPTS_WITH_CPP20
)

cmake_print_variables(
    CONCEPTS_WITH_CPP17
    CONCEPTS_WITH_CPP20
)

set(CMAKE_REQUIRED_FLAGS "-Wall -Wextra")

check_cxx_source_compiles(
    [[
        int main()
        {
            int unused_variable = 42;
            return 0;
        }
    ]]
    TEST_WITH_WARNINGS
)

set(CMAKE_REQUIRED_FLAGS "-Wall -Wextra -Werror")

check_cxx_source_compiles(
    [[
        int main()
        {
            int unused_variable = 42;
            return 0;
        }
    ]]
    TEST_WITH_WERROR
)

unset(CMAKE_REQUIRED_FLAGS)

cmake_print_variables(
    TEST_WITH_WARNINGS
    TEST_WITH_WERROR
)

set(MY_VARIABLE 42 CACHE STRING "Example" FORCE)
message(STATUS "$CACHE{MY_VARIABLE}")