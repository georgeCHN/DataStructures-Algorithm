#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include "ListStack.h"
using namespace std;
class calculate {
public:
	int isp(char ch);
	int osp(char ch);
    bool get_two_operands(ListStack<double>& opnd, double&x, double&y);
    bool cal(char op, double x, double y, double& r);
    bool inner_larger(ListStack<double>&OPERATOR_NUMBER,ListStack<char>&OPERATOR_SYMBOL);
	static bool isdigit(char ch)
	{
	    return '0' <= ch &&  ch<='9';
	}
	static bool isOperator(char ch)
	{
        char operators[10] = { '=','+','-','*','/','%','(',')','^','&' };
        for (int tmp:operators){
            if (ch == tmp)
                return true;
        }
        return false;
    }
    static void getNextChar(char& ch)
    {
        cin >> ch;
    }

};