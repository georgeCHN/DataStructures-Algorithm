//
// Created by george on 19/8/9.
//
#include "my_stack.h"
#include "../binaryTree.h"
#include<stdbool.h>

my_stack_t* stack_init(int maxsize)
{
    if(maxsize<=0) return NULL;
    my_stack_t* stack=(my_stack_t*)malloc(sizeof(my_stack_t));
    stack->data=(BiTree)malloc(maxsize*sizeof(BiNode));
    stack->top=-1;
    stack->maxsize=maxsize;
    return stack;
}
bool stack_push(my_stack_t* stack, BiNode data)
{
    if(stack->top==stack->maxsize-1) return false;
    stack->data[++stack->top]=data;
    return true;
}
bool stack_pop(my_stack_t*stack,BiTree data)
{
    if(stack==NULL||data==NULL) return false;
    if(stack->top<0){
        data=NULL;
        return false;
    }
    *data=stack->data[stack->top--];
    return true;
}
bool stack_is_empty(my_stack_t*stack)
{
    if(stack==NULL) return true;
    return stack->top==-1;
}
BiNode* stack_top(my_stack_t* stack)
{
    if(stack_is_empty(stack)) return NULL;
    return &stack->data[stack->top];
}
int stack_count(my_stack_t* stack)
{
    return stack->top+1;
}