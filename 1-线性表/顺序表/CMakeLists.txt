cmake_minimum_required(VERSION 3.14)
project(List C)

set(CMAKE_C_STANDARD 99)

add_executable(List main.c include/my_bool.h include/list.h
        test/exerciseTest.c test/listTest.h test/test408.c
        list.c list408.c listApp.c)