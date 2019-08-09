#pragma once
#ifndef GRAPH_H_
#define GRAPH_H_
#include <iostream>
#include<string>
using namespace std;
const int MAX = 100000;//×î´ó¾àÀë
class Node {
public:
	string name;
	string profile;
	int sequenceNumber;
	Node(int no = 0,string name= "ÎÞ",string profile="ÔÝÎÞ") {
		this->name = name;
		this->profile = profile;
		sequenceNumber = no;
	}
	void print() {
        cout << "---------------------------------" << endl;
		cout << "ÐòºÅ: " << sequenceNumber << endl;
		cout<<"Ãû³Æ: "<<name << endl;
		cout << "¼ò½é: " << profile << endl;
		cout << "---------------------------------" << endl;
	}
};

class Graphm{
private:
	int numVertex, numEdge;
	int** matrix;//pointer to adjacency matrix
	int* mark;
public:
	Graphm(int numVert);
	~Graphm();
    int getNumVertex();
	void Init(int n) ;
	void print() ;
	int n() ;
	int e() ;
	int first(int v);
	int next(int v, int w);
	void setEdge(int v1, int v2, int wt) ;
	void delEdge(int v1, int v2) ;
	bool isEdge(int i, int j) ;
	int weight(int v1, int v2) ;
	int getMark(int v) ;
	void setMark(int v, int val);
};

#endif