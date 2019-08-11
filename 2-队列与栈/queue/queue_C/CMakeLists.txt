cmake_minimum_required(VERSION 3.14)
project(Queue C)

set(CMAKE_C_STANDARD 99)

add_executable(Queue main.c my_queue.h my_queue.c test/test.c test/test.h
        stack/my_stack.c stack/my_stack.h
        )