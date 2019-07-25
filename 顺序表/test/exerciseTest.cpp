// 顺序表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "list.h"
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int applicationTest(void)
{

	List* alist=initList(20);
	srand((unsigned)time(NULL));
	List* blist = initList(10);
	List* resList = initList(20);
	for (int i = 0; i < 10; i++) {

		listInsert(alist, 0, rand() % 100);
		//listInsert(blist, 0, rand() % 7);
	}
	listInsert(alist, 0, 49);
	qsort(alist->data,alist->length,sizeof(alist->data[0]),cmp);
	listPrint(alist);
	findElement(alist, 50);
	listPrint(alist);
	qsort(blist->data, blist->length, sizeof(blist->data[0]), cmp);
	listPrint(blist);
	mergeList(alist, blist, resList);
	listPrint(resList);

	return 0;
}