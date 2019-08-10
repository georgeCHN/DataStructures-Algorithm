//
// Created by george on 19/8/9.
//
#include "include/my_stack.h"
#include "list/linklist.h"
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
//application
bool is_regular(int* oper,int len)
{
    if(len<1||oper==NULL) return true;
    my_stack_t* stack=stack_init(len);
    for(int i=0;i<len;i++){
        if(oper[i]==1)
            stack_push(stack,1);
        else{
            int t;
            bool res=stack_pop(stack,&t);
            if(!res) return false;
        }
    }
    return stack_is_empty(stack);
}
bool is_symmetry_list(LinkList list)
{
    int len=list_length(list);
    my_stack_t *stack = stack_init(len/2);
    int i=0;
    int t;
    for(;i<len/2;i++){
        t=list_getElement(list,i+1)->data;
        stack_push(stack,t);
    }
    if(len%2==1)//处理奇数个元素，中位数不算，往后移一位
        i++;
    while(!stack_is_empty(stack)&&i<len){
        int tmp;
        stack_pop(stack,&tmp);
        if(tmp!=list_getElement(list,i+1)->data)
            return false;
        i++;
    }
    return stack_is_empty(stack) && i>=len;
}