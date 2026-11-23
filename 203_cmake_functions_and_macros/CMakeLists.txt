cmake_minimum_required(VERSION 4.0)
project(functions_and_macros
            VERSION 0.0.0
            DESCRIPTION [[Using functions and macros in CMake]]
            LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

macro(print_greeting)
    message(STATUS "Hello ${GREET_NAME}")
endmacro()

# The macro is pastes in: message(STATUS "Hello ${GREET_NAME}")
set(GREET_NAME "Alice")
message("print_greeting(): ")
print_greeting()
#[[ print_greeting() == message(STATUS "Hello ${GREET_NAME}")]]
#[[
-- Hello Alice
]]

macro(print_greeting2 INPUT_NAME)# INPUT_NAME is an arg, not a variable
    message(STATUS "Hello ${INPUT_NAME}")# supplements <argument>
    message(STATUS "Hello ${GREET_NAME}")# supplements <variable>

    if( DEFINED INPUT_NAME )
        message(STATUS "INPUT_NAME is defined.")
    else()
        message(STATUS "INPUT_NAME is NOT defined.") #<<<
    endif()

    if( DEFINED GREET_NAME )
        message(STATUS "GREET_NAME is defined.") #<<<
    else()
        message(STATUS "GREET_NAME is NOT defined.")
    endif()
endmacro()

message("print_greeting2(): ")
print_greeting2( ${GREET_NAME} )
#[[
-- Hello Alice
-- Hello Alice
-- INPUT_NAME is NOT defined.
-- GREET_NAME is defined.
]]

macro(pass_value MYVAR)
    message(STATUS "In pass_value")
    message(STATUS "    MYVAR: ${MYVAR}")
endmacro()


set(CITY Nashville)
pass_value(   CITY  )
#[[
-- In pass_value
--     MYVAR: CITY
]]
pass_value( ${CITY} )
#[[
-- In pass_value
--     MYVAR: Nashville
]]

macro(pass_name MYVAR)
    message(STATUS "In pass_name")
    message(STATUS "    MYVAR: ${MYVAR}")
    message(STATUS "    \$\{MYVAR}: ${MYVAR}" )
endmacro()

pass_name( CITY )
#[[
-- In pass_name
--     MYVAR: CITY
--     ${MYVAR}: CITY
]]

set(TESTVAR "asdf")
message(STATUS "TESTVAR before macro: ${TESTVAR}")

macro(set_to_three MYVAR)
    message(STATUS "MYVAR: ${MYVAR}")
    set(${MYVAR} "3")
endmacro()

set_to_three( TESTVAR )
message(STATUS "TESTVAR after macro: ${TESTVAR}")
message(STATUS "MYVAR after macro: ${MYVAR}")
#[[
-- TESTVAR before macro: asdf
-- MYVAR: TESTVAR
-- TESTVAR after macro: 3
-- MYVAR after macro:
]]

macro(custom_add X_IN Y_IN SUM_OUT)
    math(EXPR ${SUM_OUT} "${X_IN} + ${Y_IN}")
endmacro()

set(X 3)
set(Y 5)
set(SUM "asdf")

custom_add(${X} ${Y} SUM)
message(STATUS "SUM after macro: ${SUM}")
message(STATUS "asdf: ${asdf}")


# Functions

function(print_greet_func)
    message(STATUS "Hello ${NAME}")
    set(NAME "Robert")
    message(STATUS "NAME at the end of print_greet_func(): ${NAME}")
endfunction()

set(NAME "Wes")
print_greet_func()

message(STATUS "NAME after print_greet_func(): ${NAME}")

# PARENT_SCOPE
function(print_greet_func1)
    message(STATUS "Hello ${NAME1}")
    set(NAME1 "Dobert" PARENT_SCOPE)
    message(STATUS "NAME at the end of print_greet_func(): ${NAME1}")
endfunction()

set(NAME1 "Fes")
print_greet_func1()

message(STATUS "NAME after print_greet_func(): ${NAME1}")