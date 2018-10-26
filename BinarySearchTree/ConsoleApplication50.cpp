// ConsoleApplication50.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include"pch.h"
#include "bst.h"
int main()
{
	BST<int> b1;
	BST<int> test;
	int array[] = { 20,1,2,5,8,9,23,10};
	for (int i = 0; i < 8; i++)
		b1.insert(array[i]);
	cout << "插入20,1,2,5,8,9,23,10节点之后\n";
	b1.print();
	int num = 8;
	cout << "binary size is: "<<b1.size() << endl;
	b1.remove(num);
	cout << "remove(8)之后的BST:\n";
	b1.print();
	b1.clear();
	cout << "clear()之后的BST\n";
	b1.print();
	
}

