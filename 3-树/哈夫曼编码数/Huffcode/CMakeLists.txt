cmake_minimum_required(VERSION 3.14)
project(Huffcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(Huffcode main.cpp huffman.cpp huffman.h preprocess.cpp)