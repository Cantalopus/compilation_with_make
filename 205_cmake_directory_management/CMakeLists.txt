cmake_minimum_required(VERSION 4.0)
project(directory_management
            VERSION 0.0.0
            DESCRIPTION [[Listfiles in different subdirectories]]
            LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "CMAKE_PROJECT_DESCRIPTION: ${CMAKE_PROJECT_DESCRIPTION}")
include(cmake/test.cmake) #[[There is NO new scope with 
                             include() as if we pasted 
                             the file here]]

# Prints directory of the current file
message(STATUS [[${CMAKE_CURRENT_LIST_DIR}: Prints 
the location of this file 
from ROOT:]] " ${CMAKE_CURRENT_LIST_FILE}")

#[[
set(PERSON_NAME "Wes")
message(STATUS "PERSON_NAME before add_subdirectory(): ${PERSON_NAME}")

add_subdirectory(src bin)
message(STATUS "PERSON_NAME after add_subdirectory(): ${PERSON_NAME}")
]]