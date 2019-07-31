#pragma once
#ifndef SLOOPLINKLIST_H_
#define SLOOPLINKLIST_H_
#include <stdio.h>
#include<stdlib.h>
//循环单链表
typedef struct node {
	int data;
	struct node* next;
}*SLoopList;
typedef struct node LNode;
//init the single loop list, return head node
extern SLoopList single_loop_list_init();
//append node in list
extern void single_loop_list_append(SLoopList list, int v);
//print the list
extern void single_loop_list_print(SLoopList list);
//every time delete minimum and print it, until linklist is empty
extern void single_loop_list_removeMin(SLoopList list);
#endif // !SLOOPLINKLIST_H_
