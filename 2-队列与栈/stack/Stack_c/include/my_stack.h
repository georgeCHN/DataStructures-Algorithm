//
// Created by george on 19/8/9.
//

#ifndef STACKANDQUEUE_MY_STACK_H
#define STACKANDQUEUE_MY_STACK_H
#include <stdlib.h>
#include<stdio.h>
#include "../list/linklist.h"
#include "my_bool.h"
typedef struct stack{
    int* data;
    int top;
    int maxsize;
}my_stack_t;
extern my_stack_t* stack_init(int maxsize);
extern bool stack_push(my_stack_t* stack,int data);
extern bool stack_pop(my_stack_t*stack,int *data);
extern bool stack_is_empty(my_stack_t*stack);
//3.3习题
extern bool is_regular(int* oper,int len);
//3.4判断链表是否中心对称
extern bool is_symmetry_list(LinkList list);
#endif //STACKANDQUEUE_MY_STACK_H
