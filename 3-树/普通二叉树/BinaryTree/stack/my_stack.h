//
// Created by george on 19/8/9.
//

#ifndef STACKANDQUEUE_MY_STACK_H
#define STACKANDQUEUE_MY_STACK_H
#include <stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include "../binaryTree.h"
typedef struct stack{
    BiTree data;
    int top;
    int maxsize;
}my_stack_t;
extern my_stack_t* stack_init(int maxsize);
extern bool stack_push(my_stack_t* stack, struct binNode data);
extern bool stack_pop(my_stack_t*stack,BiTree data);
extern bool stack_is_empty(my_stack_t*stack);
BiNode* stack_top(my_stack_t* stack);
int stack_count(my_stack_t* stack);
#endif //STACKANDQUEUE_MY_STACK_H
