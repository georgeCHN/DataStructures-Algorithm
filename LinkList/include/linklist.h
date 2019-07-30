#pragma once
#ifndef LINKLIST_H_
#define LINKLIST_H_
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;
typedef struct LNode* LinkList;
//append into list in tail of list
extern void list_append(LinkList list, int v);
//print list
extern void list_print(LinkList list);
//init a linklist, return a head node
extern LinkList list_init(void);
//return node by index, the range of index between 1 and list's length
extern LNode* list_getElement(LinkList list, int index);
//delete a node in list, by index that range between 1 and list's length
extern void list_delete(LinkList list, int index);
//return list's length
extern int list_length(LinkList list);
//insert into list, by index and value
extern void list_insert(LinkList list, int index, int v);
#endif