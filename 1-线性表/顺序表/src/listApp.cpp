#include "pch.h"
#include"list.h"

/*
删除顺序表中最小的元素，空出的位置由最后一个元素填补
*/
bool deleteMin(List*list, int* min)
{
	if (list == NULL || list->length < 1) return false;
	*min = list->data[0];
	int index = 0;
	for (int i = 1, len = list->length; i < len; i++)
		if (list->data[i] < *min) {
			*min = list->data[i];
			index = i;
		}
	list->data[index] = list->data[list->length - 1];
	list->length--;
	return true;
}
/*
将顺序表逆序
*/
void reverseList(List* list)
{
	if (list == NULL) return;
	for (int i = 0, len = list->length; i < len / 2; i++) {
		int tmp = list->data[i];
		list->data[i] = list->data[len - i - 1];
		list->data[len - i - 1] = tmp;
	}
}
/*
删除顺序表中所有值为x的元素
*/
void deleteAllx(List*list, int x)
{
	if (list == NULL) return;
	int count=0;
	for (int i = 0, len = list->length; i < len; i++){
		if (list->data[i] == x) {
			count++;
		}else
			list->data[i - count] = list->data[i];
	}
	list->length -= count;
}
/*
从顺序表删除所有s<=v<=t的元素
*/
bool deleteRange(List*list, int s, int t)
{
	if (s >= t) return false;
	if (list == NULL) return false;
	int count = 0;
	for (int i = 0, len = list->length; i < len; i++) {
		if (list->data[i]>=s&&list->data[i]<=t){
			count++;
		}
		else
			list->data[i - count] = list->data[i];
	}
	list->length -= count;
	return true;
}
/*
删除排序顺序表中的重复元素
*/
void deleteDump(List*list)
{
	int count = 0;
	if (list == NULL) return;
	for (int i = 1; i < list->length; i++) {
		if (list->data[i] == list->data[i - 1])
			count++;
		else
			list->data[i - count] = list->data[i];
	}
	list->length -= count;
}
/*
merge two sorted list
*/
void mergeList(List* a, List* b,List* res)
{
	if (a == NULL || b == NULL || res == NULL)	return;
	if (a->length + b->length > res->maxSize) return;

	int i = 0, j = 0;
	int p = 0;

	while(i < a->length &&j < b->length) {

		if (a->data[i] < b->data[j]) {
			res->data[p++] = a->data[i++];
		}else
			res->data[p++] = b->data[j++];
	}
	while(i<a->length)
		res->data[p++] = b->data[i++];
	while(j< b->length)
		res->data[p++] = a->data[j++];
	res->length = p;
}
/*
find e in list,if found that swap it with next elememnt
if not found, insert it into list, make list ordered as before
*/
void findElement(List* list, int e)
{
	if (list == NULL) return;
	int len = list->length;
	int left = 0, right = len-1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (list->data[mid] < e)
			left = mid + 1;
		else if (list->data[mid] > e)
			right = mid - 1;
		else {
			if (mid == len - 1)return;//the element is last e in list, do nothing
			else {//swap it with next e
				int tmp = list->data[mid + 1];
				list->data[mid + 1] = list->data[mid];
				list->data[mid] = tmp;
			}
			return;
		}
	}
	listInsert(list, left, e);
	//printf("the left is:%d\n", left);
}

//print array into console
void printNums(int nums[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", nums[i]);
	printf("\n");
}