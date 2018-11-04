// ConsoleApplication52.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"pch.h"
#include"linklist.h"
int main()
{
	LList<char> list;
	char array[] = { 'a','b','c','d','e','f','g' };
	for(int i=0;i<7;i++)
	list.append(array[i]);
	list.show();
	cout << "curr position " << list.currPos() << endl;
	cout << "position curr element is " << list.getValue() << endl;
	cout << "link list length is " << list.length() << endl;
	cout << "curr element is " << list.remove() << endl;
	cout << "after removing curr element link list is ";
	list.show();
	list.clear();
	cout << "clear link list is ";
	list.show();
}

