//
// Created by george on 19/8/18.
//
#include "binaryTree.h"
#include "../queue/my_queue.h"
#include <stdlib.h>
#include<stdio.h>
#include<string.h>

void bt_preOrder(BiTree root)
{
    if(root==NULL)return;
    printf("%c",root->data);
    bt_preOrder(root->left);
    bt_preOrder(root->right);
}
void bt_inOrder(BiTree root)
{
    if(root==NULL) return;
    bt_inOrder(root->left);
    printf("%c",root->data);
    bt_inOrder(root->right);
}
void bt_postOrder(BiTree root)
{
    if(root==NULL) return;
    bt_postOrder(root->left);
    bt_postOrder(root->right);
    printf("%c",root->data);
}
//层次遍历
void bt_level_traversal(BiTree root)
{
    my_queue *queue = queue_init(100);
    queue_enqueue(queue,*root);
    BiNode node;
    while(!queue_empty(queue)){
        queue_dequeue(queue,&node);
        printf("%c",node.data);
        if(node.left)
            queue_enqueue(queue,*(node.left));
        if(node.right)
            queue_enqueue(queue,*(node.right));
    }
}
//按照树的"右中左"的顺序打印，并把打印结果复制到buff中
// 之后将buff中存储的内容进行旋转即能得到正序的树
/**
 * 树的结构                  打印出来的结果，可以看出打印出来的树是左旋转的树
 *       a                   | |c| |
 *     /   \                 | | |e|
 *    b     c                |a| | |
 *    \    /                 | | |d|
 *    d   e                  | |b| |
 */
void bt_print_core(BiTree root,char* buff)
{
    static int height=0;
    height++;
    if(!root){
        height--;
        return;
    }else{
        bt_print_core(root->right,buff);
        for(int i=1;i<height;i++){
            strcat(buff,"\t");
        }
        char tmp[3];
        tmp[0]=root->data;
        tmp[1]='\n';
        tmp[2]='\0';
        strcat(buff,tmp);
        bt_print_core(root->left,buff);
        height--;
    }
}
void bt_print(BiTree root)
{
    int row=bt_count_depth(root);
    int col=bt_count_node(root);
    if(row==0||col==0)   return;
    //row=row*2-1;
    //分配一个row*col的二维数组用来存储将要打印的树型
    char** matrix=(char**)malloc(sizeof(char*)*row);
    for(int i=0;i<row;i++){
        matrix[i]=(char*)malloc(sizeof(char)*col);
        memset(matrix[i],' ',sizeof(char)*col);
    }
    char buff[2048]="";
    bt_print_core(root,buff);
    //将纵向的树，旋转成为横向的树
    for(int k=0,j=col-1;buff[k]!='\0'&&j>=0;j--){
        int i=0;
        while(buff[k]!='\n'){
            if(buff[k]=='\t')
                matrix[i][j]=' ';
            else
                matrix[i][j]=buff[k];
            i++;
            k++;
        }
        k++;
    }
    printf("\n--------------------\n");
    //将matrix存储的树的结构遍历打印出来
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf(" ");
            printf("%c",matrix[i][j]);
            printf(" ");
        }
        printf("\n\n");
    }
    printf("--------------------\n");
}
