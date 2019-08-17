cmake_minimum_required(VERSION 3.14)
project(NumBaseTransform C)

set(CMAKE_C_STANDARD 99)

add_executable(NumBaseTransform main.c include/my_stack.h my_stack.c dec2bin.c include/dec2bin.h)