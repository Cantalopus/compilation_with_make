cmake_minimum_required(VERSION 4.1)
project(required_includes #0.0.1 C CXX
            VERSION 0.0.1
            DESCRIPTION [[Using CMAKE_REQUIRED_INCLUDES]]
            LANGUAGES C CXX )
# Modules:
include( CMakePrintHelpers      )
include( CMakePushCheckState    )
include( CheckCXXSourceCompiles )
include( CheckIncludeFile       )

check_include_file("settings.h" TEST_BEFORE_PUSH)

cmake_push_check_state(RESET) #check_include_file()

    set(CMAKE_REQUIRED_INCLUDES #external/include
        "${CMAKE_CURRENT_SOURCE_DIR}/external/include")

    cmake_print_variables(CMAKE_REQUIRED_INCLUDES)
    
    check_include_file("settings.h" TEST_DURING_PUSH)

cmake_pop_check_state()

cmake_print_variables(CMAKE_REQUIRED_INCLUDES)

check_include_file("settings.h" TEST_AFTER_POP)

cmake_print_variables(TEST_BEFORE_PUSH) 
cmake_print_variables(TEST_DURING_PUSH)
cmake_print_variables(TEST_AFTER_POP)