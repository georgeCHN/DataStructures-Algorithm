//
// Created by george on 19/8/9.
//

#include "include/graph.h"
Graphm::Graphm(int numVert) {
    Init(numVert);
}
Graphm::~Graphm() {
    delete[]mark;
    for (int i = 0; i < numVertex; i++)
        delete[]matrix[i];
    delete[]matrix;
}
int Graphm::getNumVertex() {
    return numVertex;
}
void Graphm::Init(int n) {
    numVertex = n;
    numEdge = 0;
    mark = new int[n];
    for (int i = 0; i < numVertex; i++)
        mark[i] = 0;//UNVISITED
    matrix = (int**)new int*[numVertex];
    for (int i = 0; i < numVertex; i++)
        matrix[i] = new int[numVertex];
    for (int i = 0; i < numVertex; i++) {
        for (int j = 0; j < numVertex; j++) {
            if (i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = MAX;
        }
    }

}
void Graphm::print() {
    for (int i = 0; i < numVertex; i++) {
        for (int j = 0; j < numVertex; j++)
            cout << matrix[i][j] << "\t";
        cout << "\n";
    }
}
int Graphm::n() { return numVertex; }
int Graphm::e() { return numEdge; }
int Graphm::first(int v) {
    for (int i = 0; i < numVertex; i++)
        if (matrix[v][i] != 0)
            return i;
    return numVertex;//return n if none
}
int Graphm::next(int v, int w) {
    for (int i = w + 1; i < numVertex; i++)
        if (matrix[v][i] != 0)
            return i;
    return numVertex;//return n if none
}
void Graphm::setEdge(int v1, int v2, int wt) {
    if (wt <= 0) {
        cout << "illegal weight value!" << endl;
        return;
    }
    if (matrix[v1][v2] == 0) numEdge++;
    matrix[v1][v2] = wt;
}
void Graphm::delEdge(int v1, int v2) {
    if (matrix[v1][v2] != 0)
        numVertex--;
    matrix[v1][v2] = 0;
}
bool Graphm::isEdge(int i, int j) {
    return matrix[i][j] != 0;
}
int Graphm::weight(int v1, int v2) {
    return matrix[v1][v2];
}
int Graphm::getMark(int v) {
    return mark[v];
}
void Graphm::setMark(int v, int val) {
    mark[v] = val;
}
