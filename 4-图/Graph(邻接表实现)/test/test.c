//
// Created by george on 19/9/9.
//
#include <stdio.h>
#include "test.h"
#include "../graphApp.h"
#include "../graph.h"
void test_graph_addEdge(graph* g)
{

    graph_addEdge(g,0,1,1);
    graph_addEdge(g,0,3,1);
    //重复数据插入测试
    graph_addEdge(g,0,3,1);
    //异常数据插入测试
    graph_addEdge(g,0,5,1);
    graph_addEdge(g,1,4,1);
    graph_addEdge(g,2,3,1);
    graph_print(g);
}
void test_graph_first_next(graph* g)
{
    //测试fist和next函数
    int first=graph_first(g,3);
    int next = graph_next(g, 1, 4);
    int four = graph_next(g, 1, 4);
    printf("%d-->%d",next,four);
}
void test_graph_isTree(graph* g)
{
    graph_addEdge(g,0,1,1);
    graph_addEdge(g,0,2,1);
    graph_addEdge(g,1,0,1);
    graph_addEdge(g,1,3,1);
    graph_addEdge(g,1,4,1);
    graph_addEdge(g,2,0,1);
    graph_addEdge(g,3,1,1);
    graph_addEdge(g,4,1,1);
    graph_print(g);
    //test_graph_first_next(g);
    bool b =  graph_is_tree(g);
    printf("is a tree:%d\n",b);
    graph_addEdge(g,4,2,1);
    graph_addEdge(g,2,4,1);
    b =  graph_is_tree(g);
    printf("is a tree:%d\n",b);
}
void test_DFS(graph* g)
{
    printf("DFS:\n");
    DFS_traversal(g);
    printf("DFS non recur:\n");
    DFS_non_recur(g);
}
void test_exist_ijPath(graph* g,int i,int j)
{
    printf("exist=%d between %d and %d\n",graph_existPath_ij(g,i,j),i,j);
}
void test_ijPath(graph* g)
{
    test_exist_ijPath(g,0,3);
    test_exist_ijPath(g,2,4);
    test_exist_ijPath(g,2,5);
    test_exist_ijPath(g,0,5);
}
void test_all_path(graph* g)
{
    graph_find_all_path(g,0,4);
}
void test_main()
{
    char alpha[]={'a','b','c','d','e','f'};
    graph *g = graph_init(alpha, sizeof(alpha) / sizeof(char));
    //test_graph_isTree(g);
    graph_addEdge(g,0,1,1);
    graph_addEdge(g,0,2,1);
    graph_addEdge(g,1,0,1);
    graph_addEdge(g,1,2,1);
    graph_addEdge(g,1,3,1);
    graph_addEdge(g,1,4,1);
    graph_addEdge(g,2,0,1);
    graph_addEdge(g,2,1,1);
    graph_addEdge(g,2,4,1);
    graph_addEdge(g,3,1,1);
    graph_addEdge(g,4,1,1);
    graph_addEdge(g,4,2,1);
    graph_print(g);
    //test_DFS(g);
    //test_ijPath(g);
    test_all_path(g);
}
