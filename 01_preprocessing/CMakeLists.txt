cmake_minimum_required(VERSION 3.28)
project(preprocessing 
            VERSION 1.0.0
            DESCRIPTION "Inspecting preprocessing file"
            LANGUAGES C )

message(STATUS "Before setting CACHE_VAR, it has the value: \
${CACHE_VAR}")

set(CACHE_VAR "In cache!" CACHE STRING "An example \
of a cache variable")

set(VAR1 A)
set(VAR2 B)
set(VAR_NUM 2)

set(X 10)
set(Y 3)
math(EXPR X "(${X} * 4) + (33 / ${Y})")
message(STATUS "X: ${X}")

message(STATUS "${VAR${VAR_NUM}}")
message(STATUS [=[$ENV{PATH}]=])

add_library(chicken STATIC chicken.c)
    target_include_directories(chicken 
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
    target_compile_definitions(chicken PUBLIC EXIT_STATUS=66)
          
add_executable(rooster main.c)  
    target_link_libraries(rooster PRIVATE chicken)