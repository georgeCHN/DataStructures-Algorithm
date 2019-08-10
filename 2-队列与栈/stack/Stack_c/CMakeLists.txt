cmake_minimum_required(VERSION 3.14)
project(Stack C)

set(CMAKE_C_STANDARD 99)

add_executable(Stack main.c include/my_stack.h my_stack.c include/shared_stack.h shared_stack.c
        test/stack_test.h test/stack_test.c
        list/linklist.h list/linklist.c  include/my_bool.h)