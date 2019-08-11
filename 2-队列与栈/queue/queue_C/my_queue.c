// Created by george on 19/8/10.
#include "my_queue.h"
#include "stack/my_stack.h"
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
//判断括号是否匹配
bool bracket_balance(const char* str)
{
    if(str==NULL) return false;
    int i=0;
    int len = (int)strlen(str);
    my_stack_t *stack = stack_init(len);
    for(;str[i]!='\0';i++){
        int p;
        switch (str[i]){
            case '(':
                stack_push(stack,'(');
                break;
            case '[':
                stack_push(stack,'[');
                break;
            case '{':
                stack_push(stack,'{');
                break;
            case ')':
                if(stack_is_empty(stack))
                    return false;
                stack_pop(stack,&p);
                if(p!='(')
                    return false;
                break;
            case ']':
                if(stack_is_empty(stack))
                    return false;
                stack_pop(stack,&p);
                if(p!='[')
                    return false;
                break;
            case '}':
                if(stack_is_empty(stack))
                    return false;
                stack_pop(stack,&p);
                if(p!='{')
                    return false;
                break;
            default:
                //nothing do do
                ;
        }
    }
    return stack_is_empty(stack);
}

/**
 * 递归方程,用栈来模拟
 *        {1, n=0
 * Pn(x)= {2x, n=1
 *        {2xPn-1(x)-2(n-1)Pn-2(x), n>1
 *
 */
int stack_simulate_recursion(int n,int x)
{
    if(n==0) return 1;
    if(n==1) return 2*x;
    my_stack_t *stack = stack_init(n+1);
    stack_push(stack,1);
    stack_push(stack,2*x);
    for(int i=2;i<=n;i++){
        int n1,n2;
        stack_pop(stack,&n1);
        stack_pop(stack,&n2);
        int tmp=2*x*n1-2*(i-1)*n2;
        stack_push(stack,n1);
        stack_push(stack,tmp);
    }
    int res;
    stack_top(stack,&res);
    return res;
}

void train_schedule(const char* str)
{
    if(str==NULL) return;
    int len = (int)strlen(str);
    my_stack_t *stack = stack_init(len);
    for(int i=0;str[i]!='\0';i++){
        switch(str[i]){
            case 'H':
                stack_push(stack,'H');
                stack_push(stack,i);
                break;
            case 'h':
                stack_push(stack,'h');
                stack_push(stack,i);
                break;
            default:
                printf("%d(%c)--",i,str[i]);
        }
    }
    int p,q;
    while (!stack_is_empty(stack)){
        stack_pop(stack,&p);
        stack_pop(stack,&q);
        printf("%d(%c)--",p,q);
    }
}
//轮渡调度
//无聊的题目描述
void  ferry_schedule(const char* str)
{
    int size=(int)strlen(str);
    my_queue *schedule = queue_init(2*size);
    my_queue *client = queue_init(2*size);
    my_queue *trunk = queue_init(2*size);
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='C'){
            queue_enqueue(client,i);
            queue_enqueue(client,'C');
        }
        else{
            queue_enqueue(trunk,i);
            queue_enqueue(trunk,'T');
        }
    }
    int client_cnt=0;
    int total=0;
    while(total<size){
        int i=0;
        if(client_cnt<4&& !queue_empty(client)){
            int index;
            queue_dequeue(client,&index);
            printf("C(%d)--",index);
            queue_dequeue(client,&index);
            client_cnt++;
            total++;
        }
        else if(client_cnt==4 && !queue_empty(trunk)){
            int index;
            queue_dequeue(trunk,&index);
            printf("T(%d)--",index);
            queue_dequeue(trunk,&index);
            total++;
            client_cnt=0;
        }else if(client_cnt==4&& queue_empty(trunk)){//卡车队列空
            while(!queue_empty(client)){
                int index;
                queue_dequeue(client,&index);
                printf("C(%d)--",index);
                queue_dequeue(client,&index);
                total++;
            }
        }else{//客车队列空,用货车代替客车排列，仍然是4个客车一个货车
            int index;
            queue_dequeue(trunk,&index);
            printf("T(%d)--",index);
            queue_dequeue(trunk,&index);
            total++;
            client_cnt++;
        }
    }
}