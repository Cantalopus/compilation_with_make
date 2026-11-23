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


set(PERSON_NAME "Wes")
message(STATUS "PERSON_NAME before add_subdirectory(): ${PERSON_NAME}")

add_subdirectory(src bin)
message(STATUS "PERSON_NAME after add_subdirectory(): ${PERSON_NAME}")