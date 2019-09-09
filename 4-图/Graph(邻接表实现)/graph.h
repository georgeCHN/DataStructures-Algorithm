//
// Created by george on 19/9/9.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
typedef struct arc{
    int wt; //权重
    int adjVex; //弧相连接的另一个端点的下标
    struct arc* next;//下一条弧
}arc;
typedef struct vnode{
    char data;//数据域
    int i;//索引
    arc* firstArc;//第一条弧
}vertex;
typedef struct graph{
    vertex* vertex;//节点数组
    int vCount;//节点数
    int eCount;//边数
}graph;

graph* graph_init(char nodes[],int nodeCnt);
void graph_addEdge(graph*g,int i,int j,int wt);
void graph_print(graph* g);

//traversal
int graph_first(graph* g,int i);
int graph_next(graph*g,int i,int curr);
//DFS
void DFS_traversal(graph* g);

#endif //GRAPH_GRAPH_H
