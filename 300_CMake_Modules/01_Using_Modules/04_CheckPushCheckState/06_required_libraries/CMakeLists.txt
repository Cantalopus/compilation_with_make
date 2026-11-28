cmake_minimum_required(VERSION 4.1)
project(required_libraries
            VERSION 0.0.1
            DESCRIPTION [[Testing external libraries]]
            LANGUAGES C CXX)

include(CMakePrintHelpers)
include(CheckCXXSourceCompiles)
include(CMakePushCheckState)

set(TEST_SOURCE [[ //source code
    #include<arithmetic.h>
    
    int main()
    {
        return add(10, 20);
    }]])

cmake_push_check_state(RESET) #set(req)-check inc/lib

    set(CMAKE_REQUIRED_INCLUDES  # check includes
        "${CMAKE_CURRENT_SOURCE_DIR}/external/include")

    check_cxx_source_compiles(   #TEST_WITH_HEADER
        "${TEST_SOURCE}"
        TEST_WITH_HEADER )

    set(CMAKE_REQUIRED_LIBRARIES #TEST_WITH_LIBRARY
        "${CMAKE_CURRENT_SOURCE_DIR}/external/lib/libarithmetic.a")

    check_cxx_source_compiles(   #check library
        "${TEST_SOURCE}"
        TEST_WITH_LIBRARY
    )

cmake_pop_check_state()

check_cxx_source_compiles( #TEST_AFTER_POP
    "${TEST_SOURCE}"
    TEST_AFTER_POP )

cmake_print_variables(TEST_WITH_HEADER)
cmake_print_variables(TEST_WITH_LIBRARY)
cmake_print_variables(TEST_AFTER_POP)