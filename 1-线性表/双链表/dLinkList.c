#include"dLinkList.h"
DLinkList dlinklist_init()
{
	DNode* head = (DNode*)malloc(sizeof(DNode));
	head->next = NULL;
	head->prev = NULL;
	head->freq = 1000000;
	return head;
}
void dlinklist_append(DLinkList list, int v)
{
	if (list == NULL) return;
	while (list->next)
		list = list->next;
	DNode* tmp = (DNode*)malloc(sizeof(DNode));
	tmp->data = v;
	tmp->freq = 0;
	tmp->next = NULL;
	tmp->prev = list;
	list->next = tmp;
}
void dlinklist_print(DLinkList list)
{
	if (list == NULL) return;
	while (list->next) {
		printf("%d(%d)->", list->next->data, list->next->freq);
		list = list->next;
	}
	printf("END\n");
}
//访问一次，按照freq的大小排序
void dlinklist_locate(DLinkList list, int x, DNode* ptr)
{
	DNode* head = list;
	if (list == NULL) {
		ptr = NULL;
		return;
	}
	list = list->next;
	while (list != NULL && list->data != x)
		list = list->next;
	if (list == NULL) {//没找到
		ptr = NULL;
		return;
	}
	else {
		printf("found it,data is:%d,freq is:%d\n", list->data, list->freq);
		list->freq++;
		DNode* target = list;
		//取下来该节点，做尾节点检查
		if (list->next)
			list->next->prev = list->prev;
		list->prev->next = list->next;
		while (head->next && head->next->freq > target->freq) {
			head = head->next;
		}
		head->next->prev = target;
		target->next = head->next;
		head->next = target;
		target->prev = head;
		ptr = list;
	}
}