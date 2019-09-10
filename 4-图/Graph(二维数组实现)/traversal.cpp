//
// Created by geoge on 19/9/10.
//
#include "traversal.h"
#include<iostream>
#include<queue>
//depth first search,DFS
void DFS(Graphm* G, int v) {
    std::cout << v << " ";
    G->setMark(v, 1);
    for (int w = G->first(v); w < G->n(); w = G->next(v, w)) {
        //unvisited
        if (G->getMark(w) == 0)
            DFS(G, w);
    }
}
//breadth-fist search,BFS
void BFS(Graphm* G, int start) {
    std::queue<int> q;
    G->setMark(start, 1);
    q.push(start);
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        std::cout << temp << " ";
        for (int i = G->first(temp); i < G->n(); i = G->next(temp, i)) {
            if (G->getMark(i) == 0){
                q.push(i);
                G->setMark(i, 1);
            }
        }
    }
}

