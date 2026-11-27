cmake_minimum_required(VERSION 4.0)
project(required_definitions
            VERSION 0.0.1
            DESCRIPTION [[Temporarily changing preprocessor definitions]]
            LANGUAGES CXX)

include(CMakePrintHelpers)
include(CMakePushCheckState)
include(CheckCXXSourceCompiles)

set(TEST_SOURCE [[
    #ifndef TEST_AFTER_POP
        #error Feature is not enabled 
    #endif

    int main()
    {
        return 42;
    }]])

# First test
check_cxx_source_compiles( #TEST_BEFORE_PUSH
    "${TEST_SOURCE}"
    TEST_BEFORE_PUSH)

cmake_push_check_state(RESET)

    set(CMAKE_REQUIRED_DEFINITIONS "-DENABLE_FEATURE")

# Second test
    check_cxx_source_compiles( #TEST_DURING_PUSH
        "${TEST_SOURCE}"
        TEST_DURING_PUSH)

cmake_pop_check_state()

# Third test
check_cxx_source_compiles( #TEST_AFTER_POP
    "${TEST_SOURCE}"
    TEST_AFTER_POP)

cmake_print_variables(TEST_BEFORE_PUSH)
cmake_print_variables(TEST_DURING_PUSH)
cmake_print_variables(TEST_AFTER_POP  )