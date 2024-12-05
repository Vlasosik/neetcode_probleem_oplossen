cmake_minimum_required(VERSION 3.29)

project(neetcode)

set(CMAKE_CXX_STANDARD 17)

add_executable(neetcode main.cpp
        include/ArraysHashingSolutions.h
        src/ArraysHashingSolutions.cpp
        include/TwoPointers.h
        src/TwoPointers.cpp
)

target_include_directories(neetcode PRIVATE include)

