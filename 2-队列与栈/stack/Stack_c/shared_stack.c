//
// Created by george on 19/8/9.
//
#include "include/shared_stack.h"
#include <stdio.h>
#include<stdlib.h>
shared_stack_t* shared_stack_init(int maxsize)
{
    shared_stack_t *stack = (shared_stack_t *) malloc(sizeof(shared_stack_t));
    stack->maxsize=maxsize;
    stack->data=(int*)malloc(maxsize*sizeof(int));
    stack->left_top=-1;
    stack->right_top=maxsize;
    return stack;
}
bool shared_stack_empty(shared_stack_t* stack,orientation ori)
{
    if(!stack)return true;
    return ori==LEFT_ORIENT ? stack->left_top==-1:
                    stack->right_top==stack->maxsize;
}
void shared_stack_push(shared_stack_t*stack,orientation ori,int data)
{
    if(!stack) return;
    if(stack->left_top+1==stack->right_top){
        printf("stack is full,left is:%d,right is:%d,%d insert fail\n",
                stack->left_top,stack->right_top,data);
        return;
    }
    if(ori==LEFT_ORIENT){
        stack->data[++stack->left_top]=data;
    }else{
        stack->data[--stack->right_top]=data;
    }
}
void shared_stack_pop(shared_stack_t*stack,orientation ori,int*data)
{
    if(!stack) return;
    if(ori==LEFT_ORIENT){
        if(stack->left_top>-1){
            *data=stack->data[stack->left_top--];
        }
    }else{
        if(stack->right_top<stack->maxsize)
            *data=stack->data[stack->right_top++];
    }
}