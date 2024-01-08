cmake_minimum_required(VERSION 3.26)
project(test_lib)

set(CMAKE_CXX_STANDARD 17)

add_library(test_lib math_helper.cpp channel.cpp)

