#include <iostream>
#include"traversal.h"
int main()
{
    Graphm g1(7);
    g1.setEdge(1, 3,1);
    g1.setEdge(1, 5, 1);
    g1.setEdge(2, 3, 1);
    g1.setEdge(2, 6, 1);
    g1.setEdge(3, 1, 1);
    g1.setEdge(3, 2, 1);
    g1.setEdge(3, 4, 1);
    g1.setEdge(3, 6, 1);
    g1.setEdge(4, 3, 1);
    g1.setEdge(4, 6, 1);
    g1.setEdge(5, 1, 1);
    g1.setEdge(5, 6, 1);
    g1.setEdge(6, 2, 1);
    g1.setEdge(6, 3, 1);
    g1.setEdge(6, 4, 1);
    g1.setEdge(6, 5, 1);
    g1.print();
    std::cout << "DFS traversal:" << std::endl;
    DFS(&g1, 1);
    //mark矩阵的初始化
    for (int i = 0; i < 7; i++)
        g1.setMark(i, 0);
    std::cout << "\nBFS traversal:" << std::endl;
    BFS(&g1, 1);
    return 0;
}