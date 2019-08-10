//
// Created by geoge on 19/8/9.
//

#ifndef STACKANDQUEUE_SHARED_STACK_H
#define STACKANDQUEUE_SHARED_STACK_H
#include "my_bool.h"

typedef enum{
    LEFT_ORIENT,
    RIGHT_ORIENT
}orientation;
typedef struct shared_stack{
    int* data;
    int left_top;
    int right_top;
    int maxsize;
}shared_stack_t;
extern shared_stack_t* shared_stack_init(int maxsize);
extern bool shared_stack_empty(shared_stack_t* stack,orientation ori);
void shared_stack_push(shared_stack_t*stack,orientation ori,int data);
extern void shared_stack_pop(shared_stack_t*stack,orientation ori,int*data);
#endif //STACKANDQUEUE_SHARED_STACK_H
