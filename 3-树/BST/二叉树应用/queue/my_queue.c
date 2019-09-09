// Created by george on 19/8/10.
#include "my_queue.h"
#include "../bt/binaryTree.h"
#include<stdlib.h>
#include<stdio.h>
#include <limits.h>
#include<string.h>

my_queue* queue_init(int maxsize)
{
    my_queue* queue=(my_queue*)malloc(sizeof(my_queue));
    queue->front=0;
    queue->rear=0;
    queue->tag=false;
    queue->data=(BiNode*)malloc(maxsize*sizeof(BiNode));
    queue->maxsize=maxsize;
    return queue;
}
void queue_enqueue(my_queue* queue,BiNode data)
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

void queue_dequeue(my_queue* queue,BiNode* data)
{
    if(!queue) return;
    //队空
    if(!queue->tag && queue->rear==queue->front){
        printf("queue is empty\n");
        //*data=INT_MAX;
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
int queue_count(my_queue* queue)
{
    if(!queue) return 0;
    return (queue->rear+queue->maxsize-queue->front)%queue->maxsize;
}
bool queue_full(my_queue* queue)
{
    if(!queue) exit(-1);
    return queue->tag && queue->rear==queue->front;
}