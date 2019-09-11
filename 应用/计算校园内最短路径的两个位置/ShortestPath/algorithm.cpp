//
// Created by george on 19/8/9.
//
#include "include/graph.h"
#include<stack>

/*使用Dijkstra算法其中--暂时最短路径的点(已经访问过的不再访问)*/
int minVertex(Graphm*G,int*D) {
    int i, v = -1;
    for (i = 0; i < G->n(); i++) {
        if (G->getMark(i) == 0) {
            v = i;
            break;
        }
    }
    for (i++; i < G->n(); i++) {
        if ((G->getMark(i)==0) &&(D[i] < D[v]))
            v = i;
    }
    return v;
}
//参数为图,距离数组，源点，终点，路径数组
void Dijkstra(Graphm*G, int*D, int s,int d,int root[]) {
    //初始化路径,所有点的父节点设置为-1，即不可到达
    for (int i = 0; i < G->n(); i++)
        root[i] = -1;
    //初始化距离，使s到自身的距离为0，其余为MAX
    //int vertexNum = G->getNumVertex();
    for (int i = 0; i < G->n(); i++) {
        D[i] = MAX;
    }
    D[s] = 0;
    int v, w;
    //int dis_temp = D[d];
    for (int i = 0; i < G->n(); i++) {
        //dis_temp = D[d];
        v = minVertex(G, D);
        if (D[v] == MAX) return;//Unreachable vertices
        G->setMark(v, 1);
        for (w = G->first(v); w < G->n(); w = G->next(v,w)) {
            if (D[w] > D[v] + G->weight(v, w)) {
                D[w] = D[v] + G->weight(v, w);
                root[w] = v;
            }
        }
    }
}
void printRoot(int root[],int s,int d) {
    //root为路径数组，s为源点，d为路径终点
    stack<int> stack;
    //把终点压入栈中
    stack.push(d);
    //压入沿途中的点
    for (int elem = root[d]; (elem != s) && (elem!= -1);elem=root[elem]) {
        stack.push(elem);
    }
    //压入起点
    stack.push(s);
    if (root[d] == -1)
        cout << "No Way From " << s << " to " << d << endl;
    else {
        cout << "From " << s << " to " << d << " the shortest path is: " << endl;
        while (!stack.empty()) {
            if (stack.top() != d)
                cout << stack.top() << "-->";
            else
                cout << stack.top();
            stack.pop();
        }
        cout << endl;
    }

}
