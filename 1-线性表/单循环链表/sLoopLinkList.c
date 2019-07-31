#include"sLoopLinkList.h"
SLoopList single_loop_list_init()
{
	LNode* head = (LNode*)malloc(sizeof(LNode));
	head->next = head;
	return head;
}
void single_loop_list_append(SLoopList list, int v)
{
	if (list == NULL) return;
	LNode* head = list;
	while (list->next != head)
		list = list->next;
	LNode* tmp = (LNode*)malloc(sizeof(LNode));
	tmp->data = v;
	tmp->next = head;
	list->next = tmp;
}
void single_loop_list_print(SLoopList list)
{
	if (list == NULL || list->next == list) {
		printf("(NULL)");
		return;
	}
	LNode* head = list;
	while (list->next != head) {
		printf("%d->", list->next->data);
		list = list->next;
	}
	printf("head(%d)\n", head->next->data);
}
//按照链表中的最小值删除，依次清空整个链表
void single_loop_list_removeMin(SLoopList list)
{
	LNode* head = list;
	if (list == NULL) return;
	if (list->next == list) {
		//printf("just have head node\n");
		free(list);
		return;
	}
	LNode* minPrev = head;
	int min = head->next->data;
	while (list->next != head) {
		if (list->next->data < min) {
			min = list->next->data;
			minPrev = list;
		}
		list = list->next;
	}
	LNode* del = minPrev->next;
	minPrev->next = minPrev->next->next;
	printf("del:%d\n", min);
	free(del);
	//printf("in the tail:");
	//single_loop_list_print(head);
	single_loop_list_removeMin(head);
}