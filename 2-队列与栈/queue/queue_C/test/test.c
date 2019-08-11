#include "../my_queue.h"
#include <stdio.h>
//
// Created by george on 19/8/10.
//
void test_queue()
{
    my_queue *ptr = queue_init(5);
    for(int i=1;i<7;i++){
        printf("%d-th time enqueue\n",i);
        queue_enqueue(ptr,i);
    }

    int p;
    for(int i=0;i<6;i++){
        queue_dequeue(ptr,&p);
        printf("%d-th time dequeue %d\n",i,p);
    }
}
void test_queue_inverse()
{
    my_queue *ptr = queue_init(5);
    for(int i=0;i<5;i++)
        queue_enqueue(ptr,i);
    queue_inverse(ptr);
    int p;
    for(int i=0;i<5;i++){
        queue_dequeue(ptr,&p);
        printf("dequeue is %d\n",p);
    }

}
void test_main()
{
    //test_queue();
    test_queue_inverse();
}
