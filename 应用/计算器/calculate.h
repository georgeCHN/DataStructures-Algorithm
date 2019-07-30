#pragma once
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

template<class E>
/*用数组实现栈*/
class Lstack {
private:
	E array[100];
	int top;
	int max;
public:
	Lstack() {
		top = 0;
		max = 99;
	}
	void push(E it) {
		if (top == max) {
			cout << "stack is full!" << endl;
			return;
		}
		else {
			
			//cout << "push " << it << endl;
			array[top++] = it;
		}
	}
	E pop() {
		if (top == 0)
			return NULL;
		else {
			/*int num = top;
			cout << "pop" << array[--num] << endl;*/
		
			return array[--top];

		}
	}
	E topElem() {
		if (top == 0)
			return NULL;
		else
			return array[top - 1];
	}
	bool isEmpty() {
		if (top == 0)
			return true;
		else
			return false;
	}
};
class calculate {
public:
	int isp(char ch);
	int osp(char ch);
	bool isdigit(char ch) {
		if ('0' <= ch &&  ch<='9') {
			return true;
		}
		else
			return false;
	}
	bool isOperator(char ch) {
		char oper[10] = { '=','+','-','*','/','%','(',')','^','&' };
		for (int i = 0; i < 10; i++) {
			if (ch == oper[i])
				return true;
		}
		return false;
	}
	template<class E>
	bool get_two_operands(Lstack<E>& opnd, double&x, double&y);
	void getNextChar(char& ch) {
		cin >> ch;
	}
	bool cal(char op, double x, double y, double& r);
};
bool calculate::cal(char op, double x, double y, double&r) {
	switch (op) {
		case '+':
			r = x + y;
			return true;
		case '-':
			r = x - y;
			return true;
		case '*':
			r = x * y;
			return true;
		case '/':
			if (y == 0)
				return false;
			else {
				r = x / y;
				return true;
			}
		case '%':
			if (y == 0)
				return false;
			else {
				r = (int)x%(int)y;
				return true;
			}
		case '^':
			r = pow(x, y);
			return true;
		case '&':
			if (y == 0)
				return false;
			r = pow(x, 1.0/ y);
			return true;
		default:
			return false;
	}
}
template<class E>
bool calculate::get_two_operands(Lstack<E>& opnd, double&x, double&y) {
	/*每次取数时确定是否堆栈为空*/
	if (opnd.isEmpty())
		return false;
	y = opnd.pop();
	if (opnd.isEmpty())
		return false;
	x = opnd.pop();
	return true;
	
}
int calculate::isp(char ch) {
	switch (ch) {
	case '=':
		return 0;
	case '+':
		return 3;
	case '-':
		return 3;
	case '*':
		return 5;
	case '/':
		return 5;
	case '%':
		return 5;
	case '(':
		return 1;
	case ')':
		return 8;
	case '^':
		return 7;
	case '&':
		return 7;
	}
}
int calculate::osp(char ch) {
	switch (ch) {
	case '=':
		return 0;
	case '+':
		return 2;
	case '-':
		return 2;
	case '*':
		return 4;
	case '/':
		return 4;
	case '%':
		return 4;
	case '(':
		return 8;
	case ')':
		return 1;
	case '^':
		return 6;
	case '&':
		return 6;
	}
}