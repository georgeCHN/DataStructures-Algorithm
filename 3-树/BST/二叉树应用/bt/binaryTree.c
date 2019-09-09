//
// Created by george on 19/8/17.
//
#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include "binaryTree.h"


//按照前序遍历来构造树,遇到'/'表示为空结点
BiNode* bt_init_core(const char*str,int* i,int len)
{
    if(*i>len)
        return NULL;
    if(str[*i]=='/')return NULL;
    BiNode* root=(BiNode*)malloc(sizeof(BiNode));
    root->data=str[*i];
    *i +=1;
    root->left=bt_init_core(str,i,len);
    *i +=1;
    root->right=bt_init_core(str,i,len);
    return root;
}
//follow a string to build a binary tree
BiTree bt_init(const char* str)
{
    if(str==NULL||strlen(str)==0)   return NULL;
    int n=0;
    return bt_init_core(str, &n, (int) strlen(str));

}
int bt_count_node(BiTree root)
{
    if(root==NULL) return 0;
    return 1+bt_count_node(root->left)+bt_count_node(root->right);
}
int bt_count_depth(BiTree root)
{
    if(root==NULL) return 0;
    int left=bt_count_depth(root->left);
    int right=bt_count_depth(root->right);
    int len=left>right?left:right;
    return len+1;
}