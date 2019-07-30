#pragma once
//Graph abstract class
#include "pch.h"
#include<iostream>
using namespace std;
class Graph {
public:
	Graph(){}
	virtual ~Graph(){}
	virtual void Init(int n) = 0;
	//return: the number of vertices and edges
	virtual int n() = 0;
	virtual int e() = 0;
	//return v's first neighbor
	virtual int first(int v) = 0;
	//return v's next neighbor
	virtual int next(int v, int w) = 0;
	//set the weight for an edge
	//i,j: The vertices
	//wgt:Edge weight
	virtual void setEdge(int v1, int v2, int wgt) = 0;
	//delete an edge
	virtual void delEdge(int v1, int v2) = 0;
	virtual bool isEdge(int i, int j) = 0;
	//return the weight of edge i,j or zero
	virtual int weight(int v1, int v2) = 0;
	//Get and set the mark value for a vertext
	virtual int getMark(int v) = 0;
	virtual void setMark(int v, int val) = 0;

};