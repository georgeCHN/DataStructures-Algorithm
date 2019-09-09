//
// Created by george on 19/8/31.
//
#include"test.h"
#include"../bst.h"
#include"../bt/binaryTree.h"
#include<stdio.h>
void test_judge()
{
    const char* str="421//3//5//";
    BiTree root=bt_init(str);
    bt_print(root);
    bool flag=bst_judge(root);
    printf("%d",flag);
    BiTree root2=bt_init("12//3//");
    bt_print(root2);
    bool flag2=bst_judge(root2);
    printf("%d",flag2);

}
void test_ele_level()
{
    const char* str="421//3//5//";
    BiTree root=bt_init(str);
    bt_print(root);
    int i = bst_ele_level(root,'6');
    printf("i=%d\n",i);

}
void  test_balance()
{
    const char* str="42107/////1/2/3//";
    BiTree root=bt_init(str);
    bt_print(root);
    bool flag=true;
    bst_is_balance(root, &flag);
    printf("%d\n",flag);
    //
    const char* str2="421//3//5//";
    BiTree root2=bt_init(str2);
    bt_print(root2);
    flag=true;
    bst_is_balance(root2, &flag);
    printf("i=%d\n",flag);
}
void test_min_max()
{
    const char* str="421//3//5//";
    BiTree root=bt_init(str);
    bt_print(root);
    BiNode min,max;
    bst_min_max(root,&min,&max);
    printf("min:%c,,max:%c\n",min.data,max.data);
}
void test_count()
{
    const char* str="421//3//5//";
    BiTree root=bt_init(str);
    bt_print(root);
    int cnt = tree_leaf_count(root);
    printf("leaf count=%d\n",cnt);
}
void test_descend()
{
    const char* str2="421//3//5//";
    BiTree root2=bt_init(str2);
    bt_print(root2);
    bst_from_max2min(root2,'4');
}
void test_tree_height()
{
    const char* str2="421//3/4///";
    BiTree root2=bt_init(str2);
    bt_print(root2);
    int height = tree_depth(root2);
    printf("height is:%d\n",height);
}
void test_main()
{
    //test_judge();
    //test_ele_level();
    //test_balance();
    //test_min_max();
    //test_descend();
    //test_count();
    test_tree_height();
}
