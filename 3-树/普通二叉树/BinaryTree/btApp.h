//
// Created by george on 19/8/18.
//

#ifndef BINARYTREE_BTAPP_H
#define BINARYTREE_BTAPP_H
#include <stdbool.h>
#include "binaryTree.h"
//APP
void bt_post_traverse_non_recur(BiTree root);
int bt_height(BiTree root);
BiTree bt_create_by_traverse(const char* pre, const char* in);
void bt_level_traversal_inverse(BiTree root);
//Is binary tree  complete bt
bool bt_is_complete_bt(BiTree root);
//get count of node that have left and right son
int bt_count_dualNode(BiTree root);
//swap left and right node
void bt_swap_leftRight_node(BiTree root);
//k-th node that is visited in preOrder
char bt_preOrder_kth(BiTree root,int k);
//remove subtree that value as x
BiNode* bt_removeX(BiTree root,char x);
//find it's ancestor path node value as ch
void bt_ancestor_path(BiTree root,char ch);
//find common ancestor of p and q
void bt_ancestor(BiTree root,char p,char q);
//get the max of width of tree
int bt_width(BiTree root);
//create a full binary tree by preOrder traverse sequence
BiTree bt_create_fullBT(const char * str);
//connect all leaf node to be a linklist from left to right, leaf node right pointer store next pointer
BiNode* bt_connect_leafNode(BiTree root);
//带权路径长度
int bt_WPL(BiTree root,int depth);
//将计算树转换为中序表达式
void bt2infixExpression(BiTree root,int tag);
#endif //BINARYTREE_BTAPP_H
