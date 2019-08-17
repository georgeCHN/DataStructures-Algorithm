//
// Created by geoge on 19/8/17.
//
#include <stdio.h>
#include "include/my_stack.h"
char hex(int n)
{
    if(n>15){
        return '\b';
    }
    if(n<10) return (char)n;
    char alpha[]={'a','b','c','d','e','f'};
    return alpha[n-10];
}
void format_tips(int to)
{
    switch (to){
        case 2:
            printf("0b"); break;
        case 8:
            printf("O");  break;
        case 16:
            printf("0x"); break;
        default:
            printf("");
    }
}
//core algorithm, which transform base10 to other
//进制转换,除二取余法,其他进制类似
void transform(int n,int base,int to)
{
    my_stack_t *stack = stack_init(100);
    int tmp;
    while(n!=0){
        tmp=n%to;
        n=n/to;
        if(to==16)
            tmp=hex(tmp);
        stack_push(stack,tmp);
    }
    format_tips(to);
    while(!stack_is_empty(stack)){
        stack_pop(stack,&tmp);
        if(tmp>10)
            printf("%c",tmp);
        else
            printf("%d",tmp);
    }
    printf("\n");
}

