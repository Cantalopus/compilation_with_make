cmake_minimum_required(VERSION 4.0)
project(print_properties LANGUAGES CXX)

include(CMakePrintHelpers)

add_library(math STATIC math.cpp)
target_compile_definitions(math
    PRIVATE   INTERNAL_MATH=1
    PUBLIC    MATH_VERSION=2
    INTERFACE MATH_CONSUMER=3
)
add_executable(calculator main.cpp)

target_link_libraries(calculator PRIVATE math)

cmake_print_properties(
    TARGETS math calculator
    PROPERTIES 
        TYPE
        SOURCES
        LINK_LIBRARIES
        COMPILE_DEFINITIONS
        INTERFACE_COMPILE_DEFINITIONS
)