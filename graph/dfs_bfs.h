#pragma once
#include"pch.h"
#include"graphm.h"
#include<iostream>
#include<queue>
using namespace std;
/*depth first search,DFS*/
void DFS(Graph* G, int v) {
	cout << v << " ";
	G->setMark(v, 1);
	for (int w = G->first(v); w < G->n(); w = G->next(v, w)) {
		if (G->getMark(w) == 0)//unvisited
			DFS(G, w);
	}
}
/*breadth-fist search,BFS*/
void BFS(Graph* G, int start, queue<int>* q) {
	G->setMark(start, 1);
	q->push(start);
	while (q->size() != 0) {
		int temp = q->front();
		q->pop();
		cout << temp << " ";
		for (int i = G->first(temp); i < G->n(); i = G->next(temp, i)) {
			if (G->getMark(i) == 0) {
				q->push(i);
				G->setMark(i, 1);
			}
		}
	}
}