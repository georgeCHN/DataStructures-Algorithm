//
// Created by george on 19/8/31.
//

#ifndef BST_BST_H
#define BST_BST_H

#include <stdbool.h>
#include "bt/binaryTree.h"

// a binary tree is a BST or not
bool bst_judge(BiTree root);
//判断元素的深度
int bst_ele_level(BiTree root,char x);
//判断bst树是否平衡
int  bst_is_balance(BiTree root,bool* flag);
//获取bst的最小值与最大值
void bst_min_max(BiTree root,BiNode* min,BiNode* max);
//从大到小输出二叉搜索树中所有值不小于k的关键字
void bst_from_max2min(BiTree root,char x);
//求用孩子兄弟表示法存储的森林的叶子节点数
int tree_leaf_count(BiTree root);
//求用孩子兄弟表示法存储的树的深度
int tree_depth(BiTree root);
#endif //BST_BST_H