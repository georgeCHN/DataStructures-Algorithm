//
// Created by george on 19/9/9.
//
#ifndef GRAPH_GRAPHAPP_H
#define GRAPH_GRAPHAPP_H
#include <stdbool.h>
#include "graph.h"
//判断一张图是否是一棵树
bool graph_is_tree(graph* g);
//非递归方式实现DFS
void DFS_non_recur(graph* g);
//判断ij是否存在路径
bool graph_existPath_ij(graph* g,int i,int j);
//求i与j的全部简单路径
void graph_find_all_path(graph* g,int u,int v);
#endif //GRAPH_GRAPHAPP_H
