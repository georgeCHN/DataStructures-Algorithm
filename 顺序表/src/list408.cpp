#include"pch.h"
#include"list.h"
void swap(int nums[], int i, int j)
{
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
}
//循环移位，自己实现
void circulatingShift(int nums[], int len, int p)
{
	if (nums == NULL) return;
	if (p < 1 || p >= len) return;
	int posi = p - 1;
	for (; posi >= 0; posi--) {
		int posiD = posi;
		int last = nums[posi];
		do {
			int next = (posi + len - p) % len;
			int v = nums[next];
			nums[next] = last;
			posi = next;
			last = v;

		} while (posi != posiD);
		if (len%p != 0) break;
	}
}
/*
cyclic shift
*/
void reverse(int nums[], int i,int j)
{
	if (nums == NULL || j<i)return;
	if (i < 0 || j < 0)return;
	while(i<j) {
		swap(nums, i++, j--);
	}
}

void circulatShift(int nums[], int len, int p)
{
	reverse(nums, 0,p-1);
	reverse(nums, p, len-1);
	reverse(nums, 0, len - 1);
}
//find midian num in two sorted array
//the solving way use merge thought
int findMidNum(int a[], int len1, int b[], int len2)
{
	if (a == NULL || b == NULL) return NULL; 
	if (len1 == 0) return b[len2 / 2];
	if (len2 == 0) return a[len1 / 2];
	int mid = (len1 + len2-1) / 2;
	int i = 0, j = 0;
	while (i < len1&&j < len2){
		if (i + j == mid) 
			return a[i] < b[j] ? a[i] : b[j];
		if (a[i] < b[j])
			i++;
		else
			j++;
	}
	if (i >= len1) return b[mid - i];
	else if (j >= len2)
		return a[mid - j];
}

//majority number
//if n which count(n)>len/2, then return n
//else return -1
int majorityElement(int nums[], int len)
{
	int tmp = nums[0];
	int count = 1;
	for (int i = 1; i < len; i++) {
		if (nums[i] == tmp)
			count++;
		else {
			count--;
			if (count == 0) {
				tmp = nums[i];
				count = 1;
			}
		}
	}
	count = 0;
	for (int i = 0; i < len; i++) {
		if (nums[i] == tmp)
			count++;
	}
	if (count > len / 2) return tmp;
	return -1;
}
//min positive number not exist in array
int minNumber(int nums[], int len)
{
	for (int i = 0; i < len; i++) {
		if (nums[i] > 0 && nums[i] <= len && nums[i] != nums[nums[i] - 1]) {
			swap(nums, i, nums[i] - 1);
		}
	}
	for (int i = 0; i < len; i++)
		if (nums[i] != i + 1)
			return i + 1;
	return len + 1;
}