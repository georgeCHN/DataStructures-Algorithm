#include"dLoopLinkList.h"
//#include"pch.h"
#include<stdio.h>
#include<stdlib.h>
void print()
{
	printf("c source file\n");
}
DLoopLinkList dloop_list_init()
{
	DNode* head = (DNode*)malloc(sizeof(DNode));
	head->next = head;
	head->prev = head;
	return head;
}
void dloop_list_append(DLoopLinkList list,int x)
{
	if (!list) return;
	DNode* head = list;
	while (list->next != head)
		list = list->next;
	DNode* tmp = (DNode*)malloc(sizeof(DNode));
	tmp->data = x;
	tmp->next = head;
	tmp->prev = list;
	head->prev = tmp;
	list->next = tmp;
}
void dloop_list_print(DLoopLinkList list)
{
	if (!list||list->next==list) return;
	DNode* head = list;
	int i = 0;
	while (list && list->next != head) {
		printf("%d->", list->next->data);
		list = list->next;
	}
	printf("head(%d)\n",head->next->data);

}