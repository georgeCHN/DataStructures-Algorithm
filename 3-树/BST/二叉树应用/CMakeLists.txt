cmake_minimum_required(VERSION 3.14)
project(BST C)

set(CMAKE_C_STANDARD 99)

add_executable(BST main.c
        bt/btPrint.c bt/binaryTree.h bt/binaryTree.c queue/my_queue.h queue/my_queue.c
        test/test.h test/test.c
        bst.c bst.h bstApp.c)