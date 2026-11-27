cmake_minimum_required(VERSION 4.0 FATAL_ERROR)
project(preserved_variables
            VERSION 0.0.1
            DESCRIPTION [[Experiments with CMakePushCheckState]]
            LANGUAGES C CXX)

macro(my_push_state)
set(SAVED_MY_VARIABLE "${MY_VARIABLE}")
set(SAVED_MY_LIST "${MY_LIST}")
endmacro()

macro(my_pop_state)
set(MY_VARIABLE "${SAVED_MY_VARIABLE}")
set(MY_LIST "${SAVED_MY_LIST}")
endmacro()

include(CMakePushCheckState)
include(CMakePrintHelpers)

set(CMAKE_REQUIRED_FLAGS "-Wall")
set(MY_VARIABLE 10)
set(MY_LIST 22 33 44 55 66)

message(STATUS "****************Before push: ")
cmake_print_variables(CMAKE_REQUIRED_FLAGS)
cmake_print_variables(MY_VARIABLE)
cmake_print_variables(MY_LIST)

cmake_push_check_state()

set(CMAKE_REQUIRED_FLAGS "-Wall -Werror")
set(MY_VARIABLE 20)
set(MY_LIST 200 300 400 500 600)

message(STATUS "****************After modifications: ")
cmake_print_variables(CMAKE_REQUIRED_FLAGS)
cmake_print_variables(MY_VARIABLE)
cmake_print_variables(MY_LIST)
 
cmake_pop_check_state()

message(STATUS "****************After pop: ")
cmake_print_variables(CMAKE_REQUIRED_FLAGS)
cmake_print_variables(MY_VARIABLE)
cmake_print_variables(MY_LIST)

message(STATUS "****************Before my_push_state: ")

my_push_state()

set(CMAKE_REQUIRED_FLAGS "-Wall -Werror")
set(MY_VARIABLE 10)
set(MY_LIST 22 33 44 55 66)

cmake_print_variables(CMAKE_REQUIRED_FLAGS)
cmake_print_variables(MY_VARIABLE)
cmake_print_variables(MY_LIST)

my_pop_state()

message(STATUS "****************Before my_pop_state: ")

cmake_print_variables(CMAKE_REQUIRED_FLAGS)
cmake_print_variables(MY_VARIABLE)
cmake_print_variables(MY_LIST)