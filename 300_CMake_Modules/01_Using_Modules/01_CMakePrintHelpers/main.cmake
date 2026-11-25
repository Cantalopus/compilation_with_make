cmake_minimum_required(VERSION 4.0)

include(CMakePrintHelpers)

set(name "calculator")
set(version "1.0.0")
set(languages C CXX)

set(empty_variable "")
set(zero_variable 0)
set(false_variable OFF)

cmake_print_variables(
    name 
    version 
    languages
    empty_variable
    zero_variable
    false_variable
    undifined_variable)