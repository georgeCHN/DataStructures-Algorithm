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
void test_bracket_balance()
{
    const char* str="(1+2-3)";
    printf("%d\n",bracket_balance(str));
    const char* str2=")(1-2)";
    printf("%d\n",bracket_balance(str2));
    const char* str3="([{1+2}])";
    printf("%d\n",bracket_balance(str3));
    const char* str4="([{1+2}])))";
    printf("%d\n",bracket_balance(str4));
}
void test_train_schedule()
{
    const  char* str="HHSSHSS";
    train_schedule(str);
}

int recur(int n,int x)
{
    if(n==0) return 1;
    if(n==1) return 2*x;
    return 2*x*recur(n-1,x)-2*(n-1)*recur(n-2,x);
}
void test_stack_simulate_recursion()
{
    int n=10,x=1;
    int res = stack_simulate_recursion(n, x);
    int recur_res=recur(n,x);
    printf("%d vs %d\n",res,recur_res);

}
void test_ferry_schedule(){
    ferry_schedule("TTCCCCCCTTCCT");
}
void test_main()
{
    //test_queue();
    //test_queue_inverse();
    //test_bracket_balance();
    //test_train_schedule();
    //test_stack_simulate_recursion();
    test_ferry_schedule();
}
