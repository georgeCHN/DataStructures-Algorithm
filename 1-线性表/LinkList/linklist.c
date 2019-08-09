#include "include/linklist.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>

#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
LinkList list_init(void)
{
	LinkList head =(LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	head->data = INT_MAX;
	return head;
}
void list_append(LinkList list,int v)
{
	if (list == NULL) return;
	LNode* tmp = list;
	while (tmp&&tmp->next){
		tmp = tmp->next;
	}
	LNode* node = (LNode*)malloc(sizeof(LNode));
	node->data = v;
	node->next = NULL;
	tmp->next = node;
}
void list_print(LinkList list)
{
	if (list == NULL) return;
	LNode* tmp=list->next;
	char buff[1024];
	memset(buff, 0, 1024);
	while (tmp!=NULL) {          
		char* tmpArea = (char*)malloc(sizeof(char)*16);
		sprintf(tmpArea, "%d->", tmp->data);
		strcat(buff, tmpArea);
		tmp = tmp->next;
		free(tmpArea);
	}
	if (strlen(buff) > 1) {
		buff[strlen(buff) - 1] = '\0';
		buff[strlen(buff) - 1] = '\0';
	}
	printf("%s\n",buff);
}
LNode* list_getElement(LinkList list, int index)
{
	if (list == NULL)return NULL;
	if (index == 0) return list;
	int count = 0;
	LNode* tmp = list;
	while (tmp && count<index) {
		count++;
		tmp = tmp->next;
	}
	return tmp;
}
void list_delete(LinkList list, int index)
{
	if (index <= 0) return;
	LNode* prev=list_getElement(list, index - 1);
	if (!prev||!prev->next) return;
	LNode* tmp = prev->next;
	prev->next = tmp->next;
	free(tmp);
}
int list_length(LinkList list)
{
	if (!list) return 0;
	LNode* tmp = list->next;
	int c = 0;
	while (tmp) {
		tmp = tmp->next;
		c++;
	}
	return c;
}
void list_insert(LinkList list, int index,int v)
{
	if (!list) return;
	if (index > list_length(list)+1||index<1) return;
	if (index == list_length(list) + 1) { 
		list_append(list, v); 
		return;
	}
	LNode* prev=list_getElement(list, index - 1);
	LNode* curr = (LNode*)malloc(sizeof(LNode));
	curr->data = v;
	curr->next = prev->next;
	prev->next = curr;
}