cmake_minimum_required(VERSION 4.0)
project(cmake_lists 
            VERSION 0.0.0
            DESCRIPTION [[lists usage in the CMake language.]]
            LANGUAGES CXX )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Foreach Loops
set(CITIES Los Angeles Chicago New York)
message(STATUS "Value of CITIES:  ${CITIES}")
#-- Value of CITIES:  Los;Angeles;Chicago;New;York

set(CITIES "Los Angeles" Chicago "New York")
message(STATUS "Value of CITIES:  ${CITIES}")
#-- Value of CITIES:  Los Angeles;Chicago;New York

foreach(CITY IN LISTS CITIES)
    message(STATUS "This city is: ${CITY}")
endforeach()

foreach(CITY IN LISTS CITIES ITEMS Houston Orlando)
    message(STATUS "This city is: ${CITY}")
endforeach()


# Foreach Range Loops
foreach(ILOOP RANGE 3)
    message(STATUS "ILOOP: ${ILOOP}")
endforeach()
#[[
-- ILOOP: 0
-- ILOOP: 1
-- ILOOP: 2
-- ILOOP: 3
]]

foreach(ILOOP RANGE 3 5)
    message(STATUS "ILOOP: ${ILOOP}")
endforeach()
#[[
-- ILOOP: 3
-- ILOOP: 4
-- ILOOP: 5
]]

foreach(ILOOP RANGE 0 10 2)
    message(STATUS "ILOOP: ${ILOOP}")
endforeach()
#[[
-- ILOOP: 0
-- ILOOP: 2
-- ILOOP: 4
-- ILOOP: 6
-- ILOOP: 8
-- ILOOP: 10
]]


# While Loops
set(ILOOP 0)
while(ILOOP LESS 3)
    message(STATUS "ILOOP: ${ILOOP}")
    math(EXPR ILOOP "${ILOOP} + 1")
endwhile()
#[[
-- ILOOP: 0
-- ILOOP: 1
-- ILOOP: 2
]]