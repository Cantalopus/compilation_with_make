cmake_minimum_required(VERSION 4.0)
project(nested_states
            VERSION 0.0.1
            DESCRIPTION [[Using nested states with CMakePushCheckState]]
            LANGUAGES C)

include(CMakePrintHelpers)
include(CMakePushCheckState)

set(CMAKE_REQUIRED_FLAGS "-Wall")

message(STATUS "Initial state: ")
cmake_print_variables(CMAKE_REQUIRED_FLAGS)

cmake_push_check_state()

set(CMAKE_REQUIRED_FLAGS "-Wextra")

message(STATUS "First modification:")
cmake_print_variables(CMAKE_REQUIRED_FLAGS)

cmake_push_check_state()

set(CMAKE_REQUIRED_FLAGS "-Werror")

message(STATUS "Second modification:")
cmake_print_variables(CMAKE_REQUIRED_FLAGS)

cmake_pop_check_state()

message(STATUS "First pop:")
cmake_print_variables(CMAKE_REQUIRED_FLAGS)

cmake_pop_check_state()

message(STATUS "Second pop:")
cmake_print_variables(CMAKE_REQUIRED_FLAGS)