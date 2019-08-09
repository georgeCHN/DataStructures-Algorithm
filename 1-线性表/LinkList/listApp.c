#include"include/listApp.h"
#include"include/linklist.h"
#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>

LinkList list_delete_x(LinkList list, int x)
{
	if (!list) return NULL;
	if (list->data == x) {
		LNode* tmp = list;
		list = list->next;
		free(tmp);
		list=list_delete_x(list, x);
	}
	else
		list->next=list_delete_x(list->next, x);
	return list;
}

void list_delete_x_NonRecursion(LinkList list, int x)
{
	LNode* tmp = list;
	while (tmp&&tmp->next) {
		if (tmp->next->data == x) {
			LNode* del = tmp->next;
			tmp->next = tmp->next->next;
			free(del);
		}else
			tmp = tmp->next;
	}
}

void list_print_inverse(LinkList list)
{
	if (list == NULL) return;
	else {
		list_print_inverse(list->next);
		printf("%d->", list->data);
	}
	
}

LinkList list_inverse(LinkList list)
{
	LNode* headNode = list;
	list = list->next;
	LNode* head = list;
	list = list->next;
	head->next = NULL;
	while (list) {
		LNode* tmp = list->next;
		list->next = head;
		head = list;
		list = tmp;
	}

	headNode->next = head;//make reduplication-head node
	return headNode;

}

void list_delete_min(LinkList list)
{
	//使用一个前向指针，如果遇到小的数，则替换minPtr
	LNode* tmp = list;
	if (!tmp || !tmp->next) return;
	int min = tmp->next->data;
	LNode* minPrev = list;
	while (tmp->next) {
		if (tmp->next->data < min) {
			min = tmp->next->data;
			minPrev = tmp;
		}
		tmp = tmp->next;
	}
	LNode* bedel = minPrev->next;
	minPrev->next = minPrev->next->next;
	//printf("min:%d->\n", min);
	free(bedel);

}
void list_insert_as_sorted(LinkList list, LNode* node)
{
	//list_print(list);
	if (!list || !node) return;
	LNode* head = list;
	if (!head->next) { 
		head->next = node; 
		node->next = NULL;
		return;
	}
	LNode* prior = head;
	while (head->next) {
		if ( head->next->data < node->data) {
			prior = head->next;
			head = head->next;
		}
		else {
			node->next = head->next;
			prior->next = node;
			return;
		}
	}
	head->next = node;
	node->next = NULL;
}

LinkList list_sort(LinkList list)
{
	if (!list) return NULL;
	LNode * head = list;
	LNode* tmp = list->next;
	head->next = NULL;//generate a linklist
	while (tmp) {
		LNode* next = tmp->next;
		list_insert_as_sorted(head, tmp);
		tmp = next;
	}
	return head;
}

void list_delete_range(LinkList list, int i, int j)
{
	if (!list) return;
	while (list->next) {
		if (list->next->data <= j && list->next->data >= i) {
			LNode* tmp = list->next;
			list->next = list->next->next;
			free(tmp);
		}
		else
			list = list->next;
	}
}

LinkList list_comm(LinkList a, LinkList b)
{
	if (!a || !b) return NULL;//
	int alen=list_length(a);
	int blen = list_length(b);
	for (int i = 0; i < blen - alen; i++)//假设b长于a
		b = b->next;
	for (int i = 0; i < alen - blen; i++)//假设b长于a
		a = a->next;
	//去掉头节点
	a = a->next;
	b = b->next;
	while (a && b && a != b) {
		a = a->next;
		b = b->next;
	}
	LNode* head = (LNode*)malloc(sizeof(LNode));
	head->next = a;
	return head;
}
void list_seperate_by_odd_and_even(LinkList list, LinkList a, LinkList b)
{
	if (!list || !b || !a) return;
	int i = 1;
	LNode* tmp = list->next;
	while (tmp) {
		LNode* next = tmp->next;
		if (i% 2 == 1) {
			a->next = tmp;
			a = a->next;
			a->next = NULL;
		}
		else{
			/*
			b->next = tmp;
			b = b->next;
			b->next = NULL;
			*/
			//注释是10题的解,没注释的是11题的解，两者很相似
			tmp->next = b->next;
			b->next = tmp;
		}
		tmp = next;
		i++;
	}
}
void list_remove_duplicated(LinkList list)
{
	if (!list) return;
	while (list->next) {
		if (list->data == list->next->data) {
			LNode* tmp = list->next;
			list->next = list->next->next;
			free(tmp);
		}
		else
			list = list->next;
	}
}
LinkList list_merge_by_desc(LinkList a, LinkList b)
{
	if (a == NULL) return b;
	if (b == NULL) return a;
	LNode* head = a;
	a = a->next;
	b = b->next;
	head->next = NULL;
	LNode* tmp;
	while (a&&b) {
		
		if (a->data < b->data) {
			tmp = a->next;
			a->next = head->next;
			head->next = a;
			a = tmp;
		}
		else {
			tmp = b->next;
			b->next = head->next;
			head->next = b;
			b = tmp;
		}
	}
	while (a && !b) {
		tmp = a->next;
		a->next = head->next;
		head->next = a;
		a = tmp;
	}
	while (b && !a) {
		tmp = b->next;
		b->next = head->next;
		head->next = b;
		b = tmp;
	}
	return head;
}
LinkList list_merge_comm(LinkList a, LinkList b)
{
	if (!a || !b) return NULL;
	a = a->next;
	b = b->next;
	LNode* head = list_init();
	while (a&&b) {
		if (a->data < b->data)
			a = a->next;
		else if (a->data > b->data)
			b = b->next;
		else {
			list_append(head, a->data);
			a = a->next;
			b = b->next;
		}
	}
	return head;
}
void list_interaction(LinkList a, LinkList b)
{
	if (!a || !b) return;
	b = b->next;
	while (a&&b) {
		if (a->next->data > b->data) {
			LNode* tmp = b;
			b = b->next;
			free(tmp);
		}
		else if (a->next->data < b->data) {
			LNode* tmp = a->next;
			a->next = a->next->next;
			free(tmp);
		}
		else {
			a = a->next;
			LNode* tmp = b;
			b = b->next;
			free(tmp);
		}
	}
	
	LNode* tmp = a->next;;
	a->next = NULL;
	a = tmp;
	while (a) {//清除余下的节点
		LNode* tmp = a;
		a = a->next;
		free(tmp);
	}
	while (b) {//清除余下的节点
		LNode* tmp = b;
		b = b->next;
		free(tmp);
	}
}
bool list_is_subsequence(LinkList a, LinkList b)
{
	if (!a || !b) return false;
	a = a->next;
	b = b->next;
	while (a && b) {
		if (a->data != b->data)
			a = a->next;
		else
			break;
	}
	while (a && b) {
		if (b->data != a->data)
			return false;
		else {
			a = a->next;
			b = b->next;
		}
	}
	return b==NULL;
}

int list_408_lastN(LinkList list, int k)
{
	if (!list) return NULL;
	if (k < 1) return NULL;
	LNode* front = list->next;
	LNode* rear = list->next;
	for (int i = 1; i < k; i++) {
		if (!front) return 0;
		front = front->next;
	}
	if (!front) return 0;

	while (front->next) {
		front = front->next;
		rear = rear->next;
	}
	printf("last %d-th value is: %d\n",k, rear->data);
	return 1;
}

void list_408_remove_duplicate(LinkList list,int n)
{
	//题目给出了所有元素不会大于n，所以用哈希表来映射位置
	if (!list) return;
	bool* flags = (bool*)malloc(sizeof(bool)*(n+1));//|data|<=n
	//printf("sizeof is:%d\n", (n+1)*(sizeof false));
	memset(flags, false, (n + 1)*(sizeof false));
	while (list->next){
		int i = abs(list->next->data);
		if(flags[i]){
			LNode* tmp = list->next;
			list->next = list->next->next;
			free(tmp);
		}
		else {
			list = list->next;//一定要在不删除的情况下移动指针，任何情况都移动指针会漏掉某些元素
		}
		flags[i] = true;
	}
}