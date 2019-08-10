//
// Created by george on 19/8/9.
//

#include "stack_test.h"
#include "../include/my_stack.h"
#include "../include/shared_stack.h"
#include <stdio.h>
void test_stack()
{
    my_stack_t *stack = stack_init(10);
    int nums[]={1,2,3,4,5,6,7,8,9,10,11};
    for(unsigned int i=0;i<sizeof(nums)/sizeof(int);i++){
        stack_push(stack,nums[i]);
    }
    while(!stack_is_empty(stack)){
        int data;
        stack_pop(stack,&data);
        printf("pop num is:%d\n",data);
    }

}
void test_oper()
{
    int* p;
    int nums[]={1,0,1,1,0,1,0,0};
    bool res=is_regular(nums,8);
    printf("res: %d\n",res);
    int nums2[]={1,0,0,1,0,1,1,0};
    res=is_regular(nums2,8);
    printf("res: %d\n",res);
    int nums3[]={1,1,1,0,1,0,1,0};
    res=is_regular(nums3,8);
    printf("res: %d\n",res);
    int nums4[]={1,1,1,0,0,1,0,0};
    res=is_regular(nums4,8);
    printf("res: %d\n",res);
}
void test_isSymmetry()
{
    int nums[]={1,2,3,4,3,2,1};
    LinkList list = list_init();
    for(unsigned i=0;i<sizeof(nums)/sizeof(int);i++)
        list_append(list,nums[i]);
    bool symmetryRes = is_symmetry_list(list);
    printf("is symmetry: %d",symmetryRes);
}
void test_shared_stack()
{
    shared_stack_t *stack = shared_stack_init(10);
    int nums1[]={1,2,3,4,6,7};
    for(unsigned i=0;i<sizeof(nums1)/ sizeof(int);i++){
        shared_stack_push(stack,LEFT_ORIENT,nums1[i]);
    }
    int nums2[]={8,9,10};
    for(unsigned i=0;i<sizeof(nums2)/ sizeof(int);i++){
        shared_stack_push(stack,RIGHT_ORIENT,nums2[i]);
    }
    int t;
    while (!shared_stack_empty(stack,LEFT_ORIENT)){
        shared_stack_pop(stack,LEFT_ORIENT,&t);
        printf("left:%d\n",t);
    }
    while (!shared_stack_empty(stack,RIGHT_ORIENT)){
        shared_stack_pop(stack,RIGHT_ORIENT,&t);
        printf("right:%d\n",t);
    }
}
void test_main()
{
    //test_stack();
    //test_oper();
    //test_isSymmetry();
    test_shared_stack();
}