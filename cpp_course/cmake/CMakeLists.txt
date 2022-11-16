cmake_minimum_required(VERSION 3.22)
project(cmake_testapp)

add_library(lib lib.hpp lib.cpp)
add_executable(cmake_testapp main.cpp)