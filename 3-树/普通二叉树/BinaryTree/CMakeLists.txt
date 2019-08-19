cmake_minimum_required(VERSION 3.14)
project(BinaryTree C)

set(CMAKE_C_STANDARD 99)

add_executable(BinaryTree main.c binaryTree.h binaryTree.c
        queue/my_queue.c queue/my_queue.h btPrint.c test/test.h test/test.c btApp.c
        stack/my_stack.c stack/my_stack.h
        btApp.h)