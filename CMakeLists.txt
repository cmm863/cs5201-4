cmake_minimum_required(VERSION 3.3)
project(4)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/Users/connor/sp2016/cs5201/Homework/4")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES driver.cpp mathvector.h mathvector.hpp tests.h mathmatrix.h mathmatrix.hpp)
add_executable(4 ${SOURCE_FILES})