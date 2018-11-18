#pragma once
#include<iostream>
using namespace std;
class ParPtrTree {
private:
	int* array;
	int size;
public:
	ParPtrTree(int n) {
		array = new int[n];
		size = n;
		//初始化所有节点的父指针的下标为-1
		for (int i = 0; i < n; i++)
			array[i] = -1;
	}
	ParPtrTree() { delete[]array; }
	//from---to
	void UNION(int from, int to) {
		//在根部归并
		while (array[to] != -1)
			to = array[to];
		while (array[from] != -1)
			from= array[from];

		int bigger = from > to ? from : to;
		int smaller = from < to ? from : to;
		array[bigger] = smaller;
	}
	bool differ(int i, int j) {

		while (array[i]!=-1) {
			i = array[i];
		}
		while (array[j] != -1)
			j = array[j];
		if (i == j)
			return false;
		else
			return true;
	}
	void print() {
		//打印出数组中每个元素存放的父指针
		for (int i = 0; i < size; i++)
			cout << array[i] << " ";
			cout << endl;
	}
};