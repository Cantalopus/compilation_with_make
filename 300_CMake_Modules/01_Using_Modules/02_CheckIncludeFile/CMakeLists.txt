cmake_minimum_required(VERSION 4.0)
project(check_include_file_example LANGUAGES C)

include(CheckIncludeFile)
include(CMakePrintHelpers)

check_include_file("stdio.h" HAS_STDIO)
check_include_file("stdlib.h" HAS_STDLIB)
check_include_file("windows.h" HAS_WINDOWS)

cmake_print_variables(
    HAS_STDIO
    HAS_STDLIB
    HAS_WINDOWS
)

if ( HAS_STDIO )
    message(STATUS "Found stdio.h")
else()
    message(STATUS "stdio.h was not found")
endif()

if ( HAS_STDLIB )
    message(STATUS "Found stdlib.h")
else()
    message(STATUS "stdlib.h was not found")
endif()

if ( HAS_WINDOWS )
    message(STATUS "Found windows.h")
else()
    message(STATUS "windows.h was not found")
endif()

add_executable(example main.c)

if(HAS_STDIO)
    target_compile_definitions(example PRIVATE HAS_STDIO=42)
endif()

if(HAS_WINDOWS)
   target_compile_definitions(example PRIVATE HAS_WINDOWS)
endif()
