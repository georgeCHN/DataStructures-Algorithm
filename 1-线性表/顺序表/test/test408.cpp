#include"pch.h"
#include"list.h"
#include "listTest.h"

void test_408(void)
{
	int nums[] = { 1,2,3,4,5,6,7,8 };
	int len = 8;
	circulatShift(nums, len, 3);
	for (int i = 0; i < len; i++)
		printf("%d ", nums[i]);
}
void test_mid()
{
	int nums1[] = { 11,13,15,17,19 };
	int nums2[] = { 2,6,8,20 };
	int len1 = 5;
	int len2 = 4;
	printNums(nums1, len1);
	printNums(nums2, len2);
	int p=findMidNum(nums1, len1, nums2, len2);
	printf("find num is: %d\n", p);
}
void test_minPositive()
{
	int nums1[] = { 1,2,3 };
	int nums2[] = { -5,3,2,3 };
	int min1=minNumber(nums1, sizeof nums1 / sizeof 0);
	int min2 = minNumber(nums2, sizeof nums2 / sizeof 0);
	printNums(nums1, sizeof nums1 / sizeof 0);
	printf("min value is:%d\n", min1);
	printNums(nums2, sizeof nums1 / sizeof 0);
	printf("min value is:%d\n", min2);
}
void test_majorityElement()
{
	int nums[] = { 0,5,5,3,5,7,5,5 };
	int m1=majorityElement(nums, sizeof nums / sizeof 0);
	int nums2[] = { 0,5,5,3,5,1,5,7 };
	int m2=majorityElement(nums2, sizeof nums2 / sizeof 0);
	printf("m1=%d\tm2=%d\n", m1, m2);
}