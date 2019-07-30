#pragma once
#include"pch.h"
#include"Graph.h"
#include"link.h"
/*
利用邻接表来实现图
Edge对象只存储指向顶点的编号和边对应的权值
*/
class Edge {
	int vert, wt;
public:
	Edge() {
		vert = -1;
		wt = -1;
	}
	Edge(int v, int w) { vert = v; wt = w; }
	int vertex() { return vert; }
	int weight() { return wt; }
};
class Graphl :public Graph {
private:
	List<Edge>** vertex;
	int numVertex, numEdge;
	int *mark;
public:
	Graphl(int numVert) {
		Init(numVert);
	}
	~Graphl() {
		delete[]mark;
		for (int i = 0; i < numVertex; i++)
			delete[]vertex[i];
		delete[]vertex;
	}
	void Init(int n) {
		int i;
		numVertex = n;
		numEdge = 0;
		mark = new int[n];
		for (int i = 0; i < numVertex; i++)
			mark[i] = 0;//UNVISITED
		vertex = (List<Edge>**)new List<Edge>*[numVertex];
		for (int i = 0; i < numVertex; i++)
			vertex[i] = new LList<Edge>();
	}
	int n() { return numVertex; }
	int e() { return numEdge; }
	int first(int v) {
		if (vertex[v]->length() == 0)
			return numVertex;//Not Found
		vertex[v]->moveToStart();
		Edge it = vertex[v]->getValue();
		return it.vertex();
	}
	void delEdge(int i, int j) {
		if (isEdge(i,j)) {//By isEdge() function curr has move to adapt location
			vertex[i]->remove();
			numVertex--;
		}
	}
	bool isEdge(int i, int j) {
		Edge it;
		for (vertex[i]->moveToStart();vertex[i]->currPos() < vertex[i]->length();
			vertex[i]->next()) {
			Edge temp = vertex[i]->getValue();
			if (temp.vertex() == j)
				return true;
		}
		return false;
	}
	int next(int v, int w) {
		Edge it;
		if (isEdge(v, w)) {
			if (vertex[v]->currPos() + 1 < vertex[v]->length()) {
				vertex[v]->next();
				it = vertex[v]->getValue();
				return it.vertex();
			}
		}
		return n();//No neighbour
	}
	void setEdge(int i, int j, int wt) {
		if (wt <= 0) {
			cout << "Not set weight to 0 " << endl;
			return;
		}
		Edge currEdge(j, wt);
		if (isEdge(i, j)) {
			vertex[i]->remove();
			vertex[i]->insert(currEdge);
		}
		else {
			numEdge++;
			for (vertex[i]->moveToStart(); vertex[i]->currPos() < vertex[i]->length(); 
				vertex[i]->next()) {
				Edge temp = vertex[i]->getValue();
				if (temp.vertex() > j)//found, 各个节点按照大小排序
					break;
			}
			vertex[i]->insert(currEdge);
		}
	}
	int weight(int i, int j) {
		Edge curr;
		if (isEdge(i, j)) {
			curr = vertex[i]->getValue();
			return curr.weight();
		}
		else
			return 0;
	}
	int getMark(int v) {
		return mark[v];
	}
	void setMark(int v, int val) {
		mark[v] = val;
	}

};