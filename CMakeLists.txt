cmake_minimum_required(VERSION 3.25)
project(cunit)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(cunit ./include/CUnit.h ./src/CUnit.cpp)
