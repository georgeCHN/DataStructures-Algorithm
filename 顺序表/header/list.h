#pragma once
#include<stdio.h>
#ifndef LIST_H
#define LIST_H

typedef struct {
	int maxSize;
	int length;
	int* data;

}List;
//basic
extern List* initList(int maxSize);
extern bool listInsert(List* list, int i, int e);
extern bool listDelete(List* list, int i, int* e);
extern void listPrint(List* list);
//application
extern bool deleteMin(List*list, int* min);
extern void reverseList(List* list);
extern void deleteAllx(List*list, int x);
extern bool deleteRange(List*list, int s, int t);
extern void deleteDump(List*list);
extern void mergeList(List* a, List* b, List* res);
extern void findElement(List* list, int e);
//408
extern void circulatingShift(int nums[], int len, int p);
extern void circulatShift(int nums[], int len, int p);
extern int findMidNum(int a[], int len1, int b[], int len2);
extern int minNumber(int nums[], int len);
extern int majorityElement(int nums[], int len);
//tools
extern void printNums(int nums[], int len);

#endif // !LIST_H