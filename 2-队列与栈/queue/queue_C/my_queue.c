// Created by george on 19/8/10.
#include "my_queue.h"
#include "stack/my_stack.h"
#include<stdlib.h>
#include<stdio.h>
#include <limits.h>

my_queue* queue_init(int maxsize)
{
    my_queue* queue=(my_queue*)malloc(sizeof(my_queue));
    queue->front=0;
    queue->rear=0;
    queue->tag=false;
    queue->data=(int*)malloc(maxsize*sizeof(int));
    queue->maxsize=maxsize;
    return queue;
}
void queue_enqueue(my_queue* queue,int data)
{
    if(!queue) return;
    //队满
    if(queue->tag && queue->rear==queue->front){
        printf("queue is full\n");
        return;
    }
    queue->data[queue->rear]=data;
    queue->rear=(queue->rear+1)%queue->maxsize;
    //置队满
    queue->tag=true;
}
void queue_dequeue(my_queue* queue,int* data)
{
    if(!queue) return;
    //队空
    if(!queue->tag && queue->rear==queue->front){
        printf("queue is empty\n");
        *data=INT_MAX;
        return;
    }
    *data=queue->data[queue->front];
    queue->front=(queue->front+1)%queue->maxsize;
    queue->tag=false;
}
bool queue_empty(my_queue* queue)
{
    if(!queue)
        exit(-1);
    return !queue->tag && queue->rear==queue->front;
}
bool queue_full(my_queue* queue)
{
    if(!queue) exit(-1);
    return queue->tag && queue->rear==queue->front;
}
void queue_inverse(my_queue*queue)
{
    if(!queue) return;
    my_stack_t *stack = stack_init(queue->maxsize);
    while(!queue_empty(queue)){
        int p;
        queue_dequeue(queue,&p);
        stack_push(stack,p);
    }
    while(!stack_is_empty(stack)){
        int p;
        stack_pop(stack,&p);
        queue_enqueue(queue,p);
    }
}