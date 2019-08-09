cmake_minimum_required(VERSION 3.14)
project(LinkList C)

set(CMAKE_C_STANDARD 99)

add_executable(LinkList main.c
        include/linklist.h include/listApp.h
        test/test.h test/testBasic.c
        linklist.c listApp.c include/my_bool.h)