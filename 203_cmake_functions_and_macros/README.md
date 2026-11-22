# Functions and Macros  
Pay espeically close attention to the difference between a variable input to a `macro()` and a `macro(<name> [argument])`
```CMake
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
```