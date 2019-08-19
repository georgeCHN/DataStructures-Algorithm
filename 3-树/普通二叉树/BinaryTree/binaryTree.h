//
// Created by george on 19/8/17.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H
typedef struct binNode{
    char data;
    struct binNode* left;
    struct binNode* right;
}* BiTree,BiNode;
BiTree bt_init(const char* str);
//树的节点数
int bt_count_node(BiTree root);
//树的高度
int bt_count_depth(BiTree root);
/**
 * traverse method
 */
//pre order traverse
void bt_preOrder(BiTree root);
//post traverse
void bt_postOrder(BiTree root);
//in order traverse
void bt_inOrder(BiTree root);
//print as a tree
void bt_print(BiTree root);
//level traverse
void bt_level_traversal(BiTree root);
#endif //BINARYTREE_BINARYTREE_H
