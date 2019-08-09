#include<stdio.h>
#include"include/list.h"

//enter maxSize, return a list
List* initList(int maxSize)
{
	List* list = (List*)malloc(sizeof(List));
	list->data = (int*)malloc(sizeof(int)*maxSize);
	list->maxSize = maxSize;
	list->length = 0;
	return list;
}
//insert into i position(i from 0 to length-1)
bool listInsert(List* list, int i, int e)
{
	if (list == NULL) return false;
	if (i<0 || i>list->length) return false;
	if (list->length >= list->maxSize) return false;
	for (int j = list->length; j > i; j--) {
		list->data[j] = list->data[j - 1];
	}
	list->data[i] = e;
	list->length++;
	return true;
}
//delete i element(i from 0 to length-1) from list, keep deleted element in *e
bool listDelete(List* list, int i, int* e)
{
	if (list == NULL) return false;
	if (i < 0 || i >= list->length) return false;
	*e = list->data[i];
	for (int j = i; j < list->length - 1; j++)
		list->data[j] = list->data[j + 1];
	list->length--;
	return true;
}
void listPrint(List* list)
{
	for (int i = 0; i < list->length; i++)
		printf("%d ", list->data[i]);
	printf("\n");
}