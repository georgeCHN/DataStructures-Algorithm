#pragma once
#ifndef DLINKLIST_H_
#define DLINKLIST_H_
#include<stdlib.h>
#include<stdio.h>
//保存一个频度域，当访问依次，频度+1，链表按照频度排序
typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
	int freq;
}*DLinkList;
typedef struct node DNode;
extern DLinkList dlinklist_init();
extern void dlinklist_append(DLinkList list, int v);
extern void dlinklist_print(DLinkList list);
//访问一次，按照freq的大小排序
extern void dlinklist_locate(DLinkList list, int x, DNode* ptr);
#endif // !DLINKLIST_H_

