//
// Created by george on 19/8/31.
//
#include<math.h>
#include "bst.h"
#include "bt/binaryTree.h"
#include <stdio.h>
#include<stdlib.h>

//对每个节点都进行判断，或者根据中序是递增序列进行判断
bool bst_judge(BiTree root)
{
    if(!root) return true;
    bool lf=false;
    bool rf=false;
    if(root->left)
        lf=root->data > root->left->data;
    else
        lf=true;
    if(root->right)
        rf=root->right->data > root->data;
    else
        rf=true;
    return lf && rf && bst_judge(root->left) && bst_judge(root->right);
}
//某元素在BST中的层次
int bst_ele_level(BiTree root,char x)
{
    if(!root)return -1;
    int level=1;
    while(root){
        if(root->data==x)
            return level;
        else if(root->data>x)
            root=root->left;
        else if(root->data<x)
            root=root->right;
        level++;
    }
    return -1;
}
int bt_depth(BiTree root)
{
    if(root==NULL) return 0;
    int left=bt_depth(root->left);
    int right=bt_depth(root->right);
    int len=left>right?left:right;
    return len+1;
}
int abs(int t)
{
    return t>0?t:-t;
}
int  bst_is_balance(BiTree root,bool* flag)
{
    if(!root) return 0;
    int left=bst_is_balance(root->left,flag);
    int right=bst_is_balance(root->right,flag);
    int len=left>right?left:right;
    //printf("%d\n",n);
    *flag=*flag && abs(left-right)<2;
    return len+1;
}
void bst_min_max(BiTree root,BiNode* min,BiNode* max)
{
    if(!root){
        min=max=NULL;
        return ;
    }
    BiNode*  lt=root;
    while(lt->left){
        lt=lt->left;
    }
    BiNode* rt=root;
    while(rt->right)
        rt=rt->right;
    *min=*lt;
    *max=*rt;
}
void bst_from_max2min(BiTree root,char x)
{
    if(root==NULL) return;
    if(root->right&&root->right->data<=x)
        bst_from_max2min(root->right,x);
    if(root->data<=x)
        printf("%c>",root->data);
    bst_from_max2min(root->left,x);
}
//树的练习题
int tree_leaf_count(BiTree root)
{
    if(root==NULL) return 0;
    //左子树为空,则该节点必为叶子节点，右子节点是兄弟节点，不是它的子节点
    if(root->left==NULL)
        return 1+tree_leaf_count(root->right);
    else{
        //返回子树和兄弟树的节点之和
        return tree_leaf_count(root->left)+tree_leaf_count(root->right);
    }
}
//返回用孩子兄弟表示法表示的树的深度
int tree_depth(BiTree root)
{
    if(root==NULL)return 0;
    //左子树算上当前节点的高度，右子树不算当前高度
    int left=tree_depth(root->left)+1;
    int right=tree_depth(root->right);
    return left>right?left:right;
}