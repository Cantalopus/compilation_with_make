cmake_minimum_required(VERSION 4.0)
project(source_compilation_tests 
            VERSION 0.0.0
            DESCRIPTION [[CheckCXXSourceCompiles module usage]]
            LANGUAGES CXX)

include(CheckCXXSourceCompiles)
include(CMakePrintHelpers)
include(CMakePushCheckState)

set(CMAKE_REQUIRED_FLAGS "-Wall")

message(STATUS "Before push: ")
cmake_print_variables(CMAKE_REQUIRED_FLAGS)

cmake_push_check_state()

set(CMAKE_REQUIRED_FLAGS "-Wall -Wextra -Werror")

message(STATUS "After push and modifications: ")
cmake_print_variables(CMAKE_REQUIRED_FLAGS)

cmake_pop_check_state()

message(STATUS "After pop: ")
cmake_print_variables(CMAKE_REQUIRED_FLAGS)

my_pop_state()
