#include"dLoopLinkList.h"
#include"dLoopLinkListApp.h"

bool dloop_list_is_symmetry(DLoopLinkList list)
{
	DNode* rear = list->prev;
	list = list->next;
	//在奇数个元素时，list==rear;偶数个元素时list->next==rear
	while (list!=rear && list->next!=rear) {
		if (list->data == rear->data) {
			list = list->next;
			rear = rear->prev;
		}
		else {
			return false;
		}
	}
	return true;
}
void dloop_list_joint(DLoopLinkList a, DLoopLinkList b)
{
	if (a == NULL || b == NULL)return;
	if (b->next == b) return;

	DNode* aTail = a->prev;
	DNode* bHead = b;
	DNode* bTail = bHead->prev;
	aTail->next = bHead->next;
	bHead->next->prev = aTail;
	bTail->next = a;
	a->prev = bTail;
	free(bHead);
}
