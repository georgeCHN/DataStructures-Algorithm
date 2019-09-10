#include <iostream>

#include "graphm.h"
void Graphm::Init(int n) {
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
Graphm::~Graphm() {
    delete[]mark;
    for (int i = 0; i < numVertex; i++)
        delete[]matrix[i];
    delete[]matrix;
}
void Graphm::print() {
    for (int i = 0; i < numVertex; i++) {
        for (int j = 0; j < numVertex; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
}
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
        std::cout << "illegal weight value!" << std::endl;
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