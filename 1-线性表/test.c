#include "dLoopLinkList.h"
#include "dLoopLinkListApp.h"
#include "test.h"
/*
#include"sLoopLinkList.h"
void test_single_loop_list()
{
	SLoopList list = single_loop_list_init();
	int nums[] = { 0 };
	for (int i = 0; i < (sizeof nums) / (sizeof 0); i++)
		single_loop_list_append(list, nums[i]);
	single_loop_list_print(list);
	single_loop_list_removeMin(list);
}
*/
void test_dlinklist()
{
	int nums[] = { 1,2,3,4,5,6 };
	DLoopLinkList list = dloop_list_init();
	for (int i = 0; i < (sizeof nums) / (sizeof 0); i++)
		dloop_list_append(list, nums[i]);
	dloop_list_print(list);
}
void test_is_symmetry()
{
	int nums[] = {0,0,0};
	DLoopLinkList a = dloop_list_init();
	for (int i = 0; i < (sizeof nums) / (sizeof 0); i++)
		dloop_list_append(a, nums[i]);
	dloop_list_print(a);
	bool is=dloop_list_is_symmetry(a);
	if (is)
		printf("is symmetry\n");
	else
		printf("isn't symmetry\n");

}
void test_list_joint()
{

	int nums[] = { 11,3,4,6,19};
	DLoopLinkList a = dloop_list_init();
	for (int i = 0; i < (sizeof nums) / (sizeof 0); i++)
		dloop_list_append(a, nums[i]);
	
	int nums2[] = {1,2,3};
	DLoopLinkList b = dloop_list_init();
	for (int i = 0; i < (sizeof nums2) / (sizeof 0); i++)
		dloop_list_append(b, nums2[i]);
	dloop_list_print(a);
	dloop_list_print(b);
	dloop_list_joint(a, b);
	dloop_list_print(a);
}
void test_main() 
{
	//test_dlinklist();
	//test_is_symmetry();
	test_list_joint();
}