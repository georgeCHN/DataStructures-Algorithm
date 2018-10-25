// ConsoleApplication44.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool balance1(string str) {

	stack<char>mystack;
	for (int i = 0, len = str.length(); i<len; i++) {
		if (str[i] == '(')	mystack.push('(');
		else if (str[i] == ')') {
			if (mystack.empty())
				return false;
			mystack.pop();
		}
	}
	if (!mystack.empty())
		return false;
	else
		return true;
}
int balance2(string str) {
	stack<char>mystack;
	for (int i = 0, len = str.length(); i<len; i++) {
		if (str[i] == '(') {
			//把'('和所在的位置push到栈中
			mystack.push(i);
			mystack.push('('); 
		}
		else if (str[i] == ')') {
			if (mystack.empty())
				return i;
			mystack.pop();
			mystack.pop();
		}
	}
	if (!mystack.empty()) {
		mystack.pop();
		return mystack.top();
	}
	else
		return -1;

}
int main()
{
	
	int flag;
	string s = "()()(";
	flag= balance2(s);
	cout << flag;
    return 0;
}

