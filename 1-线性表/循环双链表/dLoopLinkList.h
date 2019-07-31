#pragma once
#ifndef DLINKLIST_H_
#define DLINKLIST_H_
typedef struct node {
	int data;
	struct node* prev;
	struct node* next;

}*DLoopLinkList;
typedef struct node DNode;
typedef enum { true = 1, false = 0 }bool;
extern DLoopLinkList dloop_list_init();
extern void dloop_list_append(DLoopLinkList list, int x);
extern void dloop_list_print(DLoopLinkList list);

#endif // !DLINKLIST_H_
