//
// Created by george on 19/8/9.
//
#include "my_stack.h"
my_stack_t* stack_init(int maxsize)
{
    if(maxsize<=0) return NULL;
    my_stack_t* stack=(my_stack_t*)malloc(sizeof(my_stack_t));
    stack->data=(int*)malloc(maxsize*sizeof(int));
    stack->top=-1;
    stack->maxsize=maxsize;
    return stack;
}
bool stack_push(my_stack_t* stack,int data)
{
    if(stack->top==stack->maxsize-1) return false;
    stack->data[++stack->top]=data;
    return true;
}
bool stack_pop(my_stack_t*stack,int *data)
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
void stack_top(my_stack_t* stack,int *data)
{
    if(stack->top>-1)
        *data=stack->data[stack->top];
}