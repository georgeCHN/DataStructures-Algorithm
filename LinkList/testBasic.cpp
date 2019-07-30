#include "pch.h"
#include"linklist.h"
#include "listApp.h"
#include"test.h"
#include<stdio.h>

void test(LinkList list)
{
	list_print(list);
	int len = list_length(list);
	printf("len=%d\n", len);

	while (true) {
		int v;
		printf("enter value:");
		scanf_s("%d", &v);
		int p;
		printf("enter position:");
		scanf_s("%d", &p);
		list_insert(list, p, v);
		list_print(list);
	}
}
void test_deleteX(LinkList list, int x)
{
	list=list_delete_x(list, x);
	list_print(list);
}
void test_common()
{
	LinkList a = list_init();
	int nums[] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < sizeof nums / sizeof 0; i++)
		list_append(a, nums[i]);
	list_print(a);
	int nums2[] = { 100,99,98 };
	LinkList b = list_init();
	for (int i = 0; i < sizeof nums2 / sizeof 0; i++)
		list_append(b, nums2[i]);

	list_getElement(b, 3)->next = list_getElement(a, 1);
	list_print(b);
	LinkList comm = list_comm(a, b);
	list_print(comm);
}
void test_seperate_by0and1()
{
	LinkList list = list_init();
	int nums[] = { 51,16,7,18,91,10 ,1,2,3,4};
	for (int i = 0; i < sizeof nums / sizeof 0; i++)
		list_append(list, nums[i]);
	list_print(list);
	LinkList a = list_init();
	LinkList b = list_init();
	list_seperate_by_odd_and_even(list, a, b);
	
	list_print(a);
	list_print(b);
}
void test_merg_by_desc()
{
	LinkList a = list_init();
	LinkList b = list_init();
	int nums[] = { -1,1,1,7,8,9,10 ,10,20,30,40,40,40 };
	for (int i = 0; i < sizeof nums / sizeof 0; i++)
		list_append(a, nums[i]);
	int nums2[] = { 7,9,11,100,1999,2000 };
	for (int i = 0; i < sizeof nums2 / sizeof 0; i++)
		list_append(b, nums2[i]);
	list_print(a);
	list_print(b);
	LinkList res = list_merge_by_desc(a, b);
	list_print(res);
}
void test_merge_comm()
{
	LinkList a = list_init();
	LinkList b = list_init();
	int nums[] = { -1,1,1,7,8,9,10 ,10,20,30,40,40,40,2000 };
	for (int i = 0; i < sizeof nums / sizeof 0; i++)
		list_append(a, nums[i]);
	int nums2[] = {2,5, 7,9,10,20,40,2000 };
	for (int i = 0; i < sizeof nums2 / sizeof 0; i++)
		list_append(b, nums2[i]);
	list_print(a);
	list_print(b);
	LinkList res=list_merge_comm(a, b);
	list_print(res);
}
void test_merge_interact()
{
	LinkList a = list_init();
	LinkList b = list_init();
	int nums[] = { -1,1,1,7,8,9,10 ,10,20,30,40,40,40,2000 };
	for (int i = 0; i < sizeof nums / sizeof 0; i++)
		list_append(a, nums[i]);
	int nums2[] = { 2,5, 7,9,10,20,40,2000 };
	for (int i = 0; i < sizeof nums2 / sizeof 0; i++)
		list_append(b, nums2[i]);
	list_print(a);
	list_print(b);
	list_interaction(a,b);
	list_print(a);

}
void test_subsequence()
{
	LinkList a = list_init();
	LinkList b = list_init();
	int nums[] = { -1,1,1,7,8,9,10 ,10,20,30,40,40,40,2000 };
	for (int i = 0; i < sizeof nums / sizeof 0; i++)
		list_append(a, nums[i]);
	int nums2[] = { 7,8,9,10,10};
	for (int i = 0; i < sizeof nums2 / sizeof 0; i++)
		list_append(b, nums2[i]);
	list_print(a);
	list_print(b);
	bool is=list_is_subsequence(a, b);
	if (is)
		printf("true");
	else
		printf("false");

}

void test_408_lastNth()
{
	LinkList a = list_init();
	int nums[] = { -1,1,1,7,8,9,10 ,10,20,30,40,40,40,2000 };
	for (int i = 0; i < sizeof nums / sizeof 0; i++)
		list_append(a, nums[i]);
	list_print(a);
	int i = list_408_lastN(a, 16);

}
void test_408_remove_duplicate()
{
	LinkList a = list_init();
	int nums[] = { -1,1,1,7,8,9,10 ,-10,20,30,-40,40,-40,2000 };
	for (int i = 0; i < sizeof nums / sizeof 0; i++)
		list_append(a, nums[i]);
	list_print(a);
	list_408_remove_duplicate(a, 20000);
	list_print(a);
}
void test_main()
{
	test_408_remove_duplicate();
}