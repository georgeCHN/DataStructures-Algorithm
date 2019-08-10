cmake_minimum_required(VERSION 3.14)
project(calculate)

set(CMAKE_CXX_STANDARD 14)

add_executable(calculate main.cpp calculate.h calculate.cpp ListStack.h)