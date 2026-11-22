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
    message(STATUS "Evaluates to TRUE.")
else()
    message(STATUS "Evaluates to FALSE.")
endif()

if( TRUE OR FALSE) #TRUE
    message(STATUS "( TRUE OR FALSE) Evaluates to TRUE.")
else()
    message(STATUS "( TRUE OR FALSE) Evaluates to FALSE.")
endif()

if( TRUE AND FALSE) #FALSE
    message(STATUS "( TRUE AND FALSE) Evaluates to TRUE.")
else()
    message(STATUS "( TRUE AND FALSE) Evaluates to FALSE.")
endif()

if( 10 LESS 1) #FALSE
    message(STATUS "( 10 LESS 1) Evaluates to TRUE.")
else()
    message(STATUS "( 10 LESS 1) Evaluates to FALSE.")
endif()

if( 10 LESS 11) #TRUE
    message(STATUS "( 10 LESS 11) Evaluates to TRUE.")
else()
    message(STATUS "( 10 LESS 11) Evaluates to FALSE.")
endif()

if( 10 LESS 10) #FALSE
    message(STATUS "( 10 LESS 10) Evaluates to TRUE.")
else()
    message(STATUS "( 10 LESS 10) Evaluates to FALSE.")
endif()

if( 10 LESS_EQUAL 10) #TRUE
    message(STATUS "( 10 LESS_EQUAL 10) Evaluates to TRUE.")
else()
    message(STATUS "( 10 LESS_EQUAL 10) Evaluates to FALSE.")
endif()

if( 3.13 GREATER 3.7 ) #FALSE
    message(STATUS "( 3.13 GREATER 3.7 ) Evaluates to TRUE.")
else()
    message(STATUS "( 3.13 GREATER 3.7 ) Evaluates to FALSE.")
endif()

if( 3.13 VERSION_GREATER 3.7 ) #TRUE
    message(STATUS "( 3.13 VERSION_GREATER 3.7 ) Evaluates to TRUE.")
else()
    message(STATUS "( 3.13 VERSION_GREATER 3.7 ) Evaluates to FALSE.")
endif()

if( "Hello" STREQUAL "Hello" ) #TRUE
    message(STATUS [[( "Hello" STREQUAL "Hello" ) Evaluates to TRUE.]])
else()
    message(STATUS [[( "Hello" STREQUAL "Hello" ) Evaluates to FALSE.]])
endif()

if( "Hello" STREQUAL "HELLO" ) #FALSE
    message(STATUS [[( "Hello" STREQUAL "HELLO" ) Evaluates to TRUE.]])
else()
    message(STATUS [[( "Hello" STREQUAL "HELLO" ) Evaluates to FALSE.]])
endif()

#set(MYVAR FALSE)
#set(MYVAR "" CACHE STRING "docstring")

if(DEFINED MYVAR)
    message(STATUS "MYVAR is defined")
else()
    message(STATUS "MYVAR is NOT defined")
endif()

set(TESTVAR1 "jkhfdjh")
set(TESTVAR2 "Hello")

if( ${TESTVAR1} ) #FALSE
    message(STATUS [[( ${TESTVAR} ) Evaluates to TRUE.]])
else()
    message(STATUS [[( ${TESTVAR} ) Evaluates to FALSE.]])
endif()

if(   TESTVAR1   ) #TRUE
    message(STATUS [[(   TESTVAR1   ) Evaluates to TRUE.]])
else()
    message(STATUS [[(   TESTVAR1   ) Evaluates to FALSE.]])
endif()

set(TESTVAR1 "TESTVAR2")

if( ${TESTVAR1} STREQUAL "Hello" ) #TRUE
    message(STATUS [[( ${TESTVAR1} STREQUAL "Hello" ) Evaluates to TRUE.]])
else()
    message(STATUS [[( ${TESTVAR1} STREQUAL "Hello" ) Evaluates to FALSE.]])
endif()

if( TESTVAR1 STREQUAL "Hello" ) #FALSE
    message(STATUS [[(   TESTVAR1 STREQUAL "Hello" ) Evaluates to TRUE.]])
else()
    message(STATUS [[(   TESTVAR1 STREQUAL "Hello" ) Evaluates to FALSE.]])
endif()

message(STATUS "TEATVAR1 value: " ${TESTVAR1})
message(STATUS "TEATVAR1 value: "   TESTVAR1 )
message(STATUS "TEATVAR1 value: "   ${${TESTVAR1}} )