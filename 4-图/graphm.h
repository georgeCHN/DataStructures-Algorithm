#pragma once
#include "Graph.h"
class Graphm :public Graph {
private:
	int numVertex, numEdge;
	int** matrix;//pointer to adjacency mmatrix
	int* mark;
public:
	Graphm(int numVert) {
		Init(numVert);
	}
	~Graphm() {
		delete[]mark;
		for (int i = 0; i < numVertex; i++) 
			delete[]matrix[i];
		delete[]matrix;
		
	}
	void Init(int n) {
		numVertex = n;
		numEdge = 0;
		mark = new int[n];
		for (int i = 0; i < numVertex; i++)
			mark[i] = 0;//UNVISITED
		matrix = (int**)new int*[numVertex];
		for (int i = 0; i < numVertex; i++)
			matrix[i] = new int[numVertex];
		for (int i = 0; i < numVertex; i++)
			for (int j = 0; j < numVertex; j++)
				matrix[i][j] = 0;
	}
	void print() {
		for (int i = 0; i < numVertex; i++) {
			for (int j = 0; j < numVertex; j++)
				cout << matrix[i][j] << " ";
			cout << "\n";
		}
	}
	int n() { return numVertex; }
	int e() { return numEdge; }
	int first(int v) {
		for (int i = 0; i < numVertex; i++)
			if (matrix[v][i] != 0)
				return i;
		return numVertex;//return n if none
	}
	int next(int v, int w) {
		for (int i = w + 1; i < numVertex; i++)
			if (matrix[v][i] != 0)
				return i;
		return numVertex;//return n if none
	}
	void setEdge(int v1, int v2, int wt) {
		if (wt <= 0) {
			cout << "illegal weight value!" << endl;
			return;
		}
		if (matrix[v1][v2] == 0) numEdge++;
		matrix[v1][v2] = wt;
	}
	void delEdge(int v1, int v2) {
		if (matrix[v1][v2] != 0)
			numVertex--;
		matrix[v1][v2] = 0;
	}
	bool isEdge(int i, int j) {
		return matrix[i][j] != 0;
	}
	int weight(int v1, int v2) {
		return matrix[v1][v2];
	}
	int getMark(int v) {
		return mark[v];
	}
	void setMark(int v, int val) {
		mark[v] = val;
	}
};