cmake_minimum_required(VERSION 4.0)
project(G_expressions
            VERSION 0.0.0
            DESCRIPTION [[CMake generator expressions]]
            LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GENERATOR_RESULT $<1:Hello World>)
set(GENERATOR_RESULT1 $<VERSION_GREATER:1.3,1.15>)
set(GENERATOR_RESULT2 $<$<AND:$<STREQUAL:TEST,TEST>,$<VERSION_GREATER:1.15,1.3>>:Hello>)

file(GENERATE OUTPUT out.txt CONTENT 
    "Geneator result: ${GENERATOR_RESULT}")

file(GENERATE OUTPUT out1.txt CONTENT 
    "Geneator result: ${GENERATOR_RESULT1}")

file(GENERATE OUTPUT out2.txt CONTENT 
    "Geneator result: ${GENERATOR_RESULT2}")