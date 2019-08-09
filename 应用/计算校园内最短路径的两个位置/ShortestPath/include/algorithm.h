//
// Created by george on 19/8/9.
//

#ifndef SHORTESTPATH_ALGORITHM_H
#define SHORTESTPATH_ALGORITHM_H

#include "graph.h"
//dijkstra内用函数
extern int minVertex(Graphm*G, int*D);
//参数为图,距离数组，源点，终点，路径数组
extern void Dijkstra(Graphm*G, int*D, int s,int d,int root[]);
//打印起点和终点的路径
extern void printRoot(int root[],int s,int d);
#endif //SHORTESTPATH_ALGORITHM_H
