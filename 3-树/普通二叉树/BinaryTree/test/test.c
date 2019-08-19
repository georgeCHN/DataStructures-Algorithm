//
// Created by george on 19/8/18.
//
#include "../binaryTree.h"
#include"../btApp.h"
#include <stdio.h>
#include<string.h>
void test_level(BiTree root)
{
    printf("level traversal: ");
    bt_level_traversal(root);
}
int tree_height(BiTree root)
{
    if(root==NULL) return 0;

    return 1+(tree_height(root->left)>tree_height(root->right)?tree_height(root->left):tree_height(root->right));
}
void test_height(BiTree root)
{
    int height = bt_height(root);
    int height2=tree_height(root);
    printf("%d v %d\n",height,height2);
}
void test_create_tree()
{
    const char* pre="ABCEHFIJDGK";
    const char* in="AHECIFJBDKG";
    BiTree root = bt_create_by_traverse(pre, in);
    bt_print(root);
}
void test_complete_bt()
{

    const char* str1="1248//9//5//36F///7//";
    BiTree root1 = bt_init(str1);
    bt_print(root1);
    bool b = bt_is_complete_bt(root1);
    printf("%d\n",b);

    const char* str2="1248//9//5X///26//7//";
    BiTree root2 = bt_init(str2);
    bt_print(root2);

    bool r2 = bt_is_complete_bt(root2);
    printf("%d\n",r2);
}
void test_dualNode_count()
{
    const char* str1="1248//9//5//36F///7//";
    BiTree root1 = bt_init(str1);
    bt_print(root1);
    int b=bt_count_dualNode(root1);
    printf("%d\n",b);

    const char* str2="12//3//";
    BiTree root2 = bt_init(str2);
    bt_print(root2);

    int r2=bt_count_dualNode(root2);
    printf("%d\n",r2);
}
void test_swap_leftRight_node()
{
    const char* str1="1248//9//5//36F///7//";
    BiTree root1 = bt_init(str1);
    bt_print(root1);
    bt_swap_leftRight_node(root1);
    bt_print(root1);
}
void test_kth_node()
{
    const char* str1="1248//9//5//36F///7//";
    BiTree root1 = bt_init(str1);
    bt_print(root1);
    char i = bt_preOrder_kth(root1, 5);
    printf("%c",i);
}
void test_removeX()
{
    const char* str1="1248//9//5//36F///7//";
    BiTree root1 = bt_init(str1);
    bt_print(root1);
    BiNode *pNode = bt_removeX(root1, '2');
    bt_print(pNode);
    //bt_print(root1);
}
void test_grand_node()
{
    const char* str1="1248//9//5//36F///7//";
    BiTree root1 = bt_init(str1);
    bt_print(root1);
    bt_ancestor_path(root1,'9');
}
void test_common_ancestor()
{
    const char* str1="1248//9//5//36F///7//";
    BiTree root1 = bt_init(str1);
    bt_print(root1);
    bt_ancestor(root1,'6','9');
}
void test_width()
{
    const char* str1="12480///9//5o//p//36F///7//";
    BiTree root1 = bt_init(str1);
    bt_print(root1);
    int w1 = bt_width(root1);
    printf("width=%d\n",w1);
}
void test_create_fullBT()
{
    const char* str1="abcdefghijklmnohijklmnohijklmno";
    printf("len=%d\n",strlen(str1));
    BiTree pNode = bt_create_fullBT(str1);
    bt_print(pNode);
    bt_preOrder(pNode);
}
void test_connect_linklist()
{
    const char* str1="12480///9//5o//p//36F///7//";
    BiTree root1 = bt_init(str1);
    bt_print(root1);
    BiNode *pNode = bt_connect_leafNode(root1);
    pNode=pNode->right;
    while(pNode){
        printf("%c-->",pNode->data);
        pNode=pNode->right;
    }

}
void test_wpl()
{
    const char* str1="124///3//";
    BiTree root1 = bt_init(str1);
    bt_print(root1);
    int n=bt_WPL(root1,0);
    printf("wpl =%d\n",n);
    const char* str2="1248///5//362///7//";
    BiTree root2 = bt_init(str2);
    bt_print(root2);
    int n2=bt_WPL(root2,0);
    printf("wpl2 =%d\n",n2);
}
void test_infix()
{
    const char* str1="*+a//b//*c//-/d//";
    BiTree  root=bt_init(str1);
    bt_print(root);
    bt2infixExpression(root,0);
    const char* str2="+*a//b//-/-c//d//";
    BiTree  root2=bt_init(str2);
    bt_print(root2);
    bt2infixExpression(root2,0);

}
void test_main()
{
    test_infix();
    //test_wpl();
    //test_connect_linklist();
    //test_create_fullBT();
    //test_width();
    //test_common_ancestor();
    //test_grand_node();
    //test_removeX();
    //test_kth_node();
    //test_swap_leftRight_node();
    //test_dualNode_count();
    //test_complete_bt();
    //test_create_tree();
    //test_level(root);
    //test_height(root);
}
