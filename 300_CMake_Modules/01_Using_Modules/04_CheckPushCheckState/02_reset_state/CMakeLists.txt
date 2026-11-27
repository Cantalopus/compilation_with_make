cmake_minimum_required(VERSION 4.0 FATAL_ERROR)
project(reset_state
            VERSION 0.0.1
            DESCRIPTION [[Understanding reset_state in CMakePushCheckState]]
            LANGUAGES C)

macro(my_push_state)
set(MY_SAVED_VARIABLE "${MY_VARIABLE}")
set(MY_SAVED_VARIABLE1 "${MY_VARIABLE1}")
set(MY_SAVED_VARIABLE2 "${MY_VARIABLE2}")
set(MY_SAVED_LIST "${MY_LIST}")
endmacro()

macro(my_pop_state)
set(MY_VARIABLE "${MY_SAVED_VARIABLE}")
set(MY_VARIABLE1 "${MY_SAVED_VARIABLE1}")
set(MY_VARIABLE2 "${MY_SAVED_VARIABLE2}")
set(MY_LIST "${MY_SAVED_LIST}")
endmacro()

include(CMakePushCheckState)
include(CMakePrintHelpers)

set(CMAKE_REQUIRED_FLAGS "-Wall")
set(CMAKE_REQUIRED_DEFINITIONS "-DNUMBER=42")
set(MY_VARIABLE 10)
set(MY_VARIABLE1 66)
set(MY_VARIABLE2 99)

message(STATUS "Before push:")
cmake_print_variables(CMAKE_REQUIRED_FLAGS)
cmake_print_variables(CMAKE_REQUIRED_DEFINITIONS)
cmake_print_variables(MY_VARIABLE)
cmake_print_variables(MY_VARIABLE1)
cmake_print_variables(MY_VARIABLE2)

cmake_push_check_state(RESET)

message(STATUS "Immediately after push:")
cmake_print_variables(CMAKE_REQUIRED_FLAGS)
cmake_print_variables(CMAKE_REQUIRED_DEFINITIONS)
cmake_print_variables(MY_VARIABLE)
cmake_print_variables(MY_VARIABLE1)
cmake_print_variables(MY_VARIABLE2)

set(CMAKE_REQUIRED_FLAGS "-Werror")
set(CMAKE_REQUIRED_DEFINITIONS "-DNUMBER=99")

message(STATUS "After modifications")

cmake_print_variables(CMAKE_REQUIRED_FLAGS)
cmake_print_variables(CMAKE_REQUIRED_DEFINITIONS)

cmake_pop_check_state()

message(STATUS "After pop: ")
cmake_print_variables(CMAKE_REQUIRED_FLAGS)
cmake_print_variables(CMAKE_REQUIRED_DEFINITIONS)
cmake_print_variables(MY_VARIABLE)
cmake_print_variables(MY_VARIABLE1)
cmake_print_variables(MY_VARIABLE2)

message(STATUS "before my push state:")
my_push_state()

set(MY_VARIABLE 100)
set(MY_VARIABLE1 666)
set(MY_VARIABLE2 999)

cmake_print_variables(MY_VARIABLE)
cmake_print_variables(MY_VARIABLE1)
cmake_print_variables(MY_VARIABLE2)

my_pop_state()
message(STATUS "after my pop state:")

cmake_print_variables(MY_VARIABLE)
cmake_print_variables(MY_VARIABLE1)
cmake_print_variables(MY_VARIABLE2)