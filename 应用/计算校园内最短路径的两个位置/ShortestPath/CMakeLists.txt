cmake_minimum_required(VERSION 3.14)
project(ShortestPath)

set(CMAKE_CXX_STANDARD 14)

add_executable(ShortestPath main.cpp graph.cpp include/algorithm.h algorithm.cpp)