//
// Created by george on 19/8/10.
//

#ifndef QUEUE_MY_QUEUE_H
#define QUEUE_MY_QUEUE_H
#include <stdbool.h>
typedef struct{
    int* data;
    bool tag;
    int front;
    int rear;
    int maxsize;
}my_queue;
//circulate queue use tag to differentiate empty and full
my_queue* queue_init(int maxsize);
//if queue is full, return doing nothing
void queue_enqueue(my_queue* queue,int data);
//if queue is empty, data store INT_MAX
void queue_dequeue(my_queue* queue,int* data);
bool queue_empty(my_queue* queue);
bool queue_full(my_queue* queue);
//inverse the queue, by the stack to reverse
void queue_inverse(my_queue*queue);
#endif //QUEUE_MY_QUEUE_H
