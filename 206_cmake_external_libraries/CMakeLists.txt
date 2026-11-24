cmake_minimum_required(VERSION 4.0)
project(multi-file
            VERSION 0.0.0
            DESCRIPTION [[Multi-file CMake project example]]
            LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(yamlexample src/main.cpp)
target_compile_features(yamlexample PUBLIC cxx_std_20)
find_package(yaml-cpp REQUIRED)
target_link_libraries(yamlexample PRIVATE yaml-cpp)