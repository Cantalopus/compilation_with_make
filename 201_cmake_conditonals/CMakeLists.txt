cmake_minimum_required(VERSION 4.0)
project(conditionals
    VERSION 0.0.0
    DESCRIPTION [[Working with CMake Conditional statements]]
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(hello ON)
if( #[[TRUE]] #[[ON]] #[[YES]] #[[1]] #[[1.9]] #[[-5]] #[[Y]] #[[y]]
    #[[OFF]]  #[[OFF]] #[[NO]] #[[0]] #[[nothing]] #[[T]] #[[hjkdhj]] #[[hello]])
    message(STATUS "Evaluates to true.")
else()
    message(STATUS "Evaluates to false")
endif()

if( TRUE OR FALSE) #TRUE
    message(STATUS "( TRUE OR FALSE) Evaluates to true.")
else()
    message(STATUS "( TRUE OR FALSE) Evaluates to false")
endif()

if( TRUE AND FALSE) #FALSE
    message(STATUS "( TRUE AND FALSE) Evaluates to true.")
else()
    message(STATUS "( TRUE AND FALSE) Evaluates to false")
endif()

if( 10 LESS 1) #FALSE
    message(STATUS "( 10 LESS 1) Evaluates to true.")
else()
    message(STATUS "( 10 LESS 1) Evaluates to false")
endif()

if( 10 LESS 11) #TRUE
    message(STATUS "( 10 LESS 11) Evaluates to true.")
else()
    message(STATUS "( 10 LESS 11) Evaluates to false")
endif()

if( 10 LESS 10) #FALSE
    message(STATUS "( 10 LESS 10) Evaluates to true.")
else()
    message(STATUS "( 10 LESS 10) Evaluates to false")
endif()

if( 10 LESS_EQUAL 10) #TRUE
    message(STATUS "( 10 LESS_EQUAL 10) Evaluates to true.")
else()
    message(STATUS "( 10 LESS_EQUAL 10) Evaluates to false")
endif()

if( 3.13 GREATER 3.7 ) #FALSE
    message(STATUS "( 3.13 GREATER 3.7 ) Evaluates to true.")
else()
    message(STATUS "( 3.13 GREATER 3.7 ) Evaluates to false")
endif()

if( 3.13 VERSION_GREATER 3.7 ) #TRUE
    message(STATUS "( 3.13 VERSION_GREATER 3.7 ) Evaluates to true.")
else()
    message(STATUS "( 3.13 VERSION_GREATER 3.7 ) Evaluates to false")
endif()

if( "Hello" STREQUAL "Hello" ) #TRUE
    message(STATUS [[( "Hello" STREQUAL "Hello" ) Evaluates to true.]])
else()
    message(STATUS [[( "Hello" STREQUAL "Hello" ) Evaluates to false]])
endif()

if( "Hello" STREQUAL "HELLO" ) #FALSE
    message(STATUS [[( "Hello" STREQUAL "HELLO" ) Evaluates to true.]])
else()
    message(STATUS [[( "Hello" STREQUAL "HELLO" ) Evaluates to false]])
endif()