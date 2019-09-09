//
// Created by george on 19/8/9.
//
#include "calculate.h"
#include <map>
bool calculate::inner_larger(ListStack<double>&OPERATOR_NUMBER,ListStack<char>&OPERATOR_SYMBOL)
{
    double x, y;
    //暂存操作符
    char operator_temp;
    bool get_operator_num=get_two_operands(OPERATOR_NUMBER, x, y);
    if (get_operator_num) {
        operator_temp = OPERATOR_SYMBOL.pop();
        double cal_result;
        bool cal_correct_flag=cal(operator_temp, x, y, cal_result);
        if (cal_correct_flag)
            OPERATOR_NUMBER.push(cal_result);
        //继续处理当前字符
        return true;
    }
    else {
        cout << "语法错误" << endl;
        return false;
    }
}
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
bool calculate::get_two_operands(ListStack<double>& opnd, double&x, double&y) {
    //每次取数时确定是否堆栈为空
    if (opnd.isEmpty())
        return false;
    y = opnd.pop();
    if (opnd.isEmpty())
        return false;
    x = opnd.pop();
    return true;
}

/*运算符优先级
 * = 0 ; + 3 ; - 3 ; * 5 ; / 5 ; % 5;  ( 1;  ) 8;  ^ 7; & 7
  */
int calculate::isp(char ch) {
    map<char,int> map;
    map.insert(pair<char,int>('=',0));
    map.insert(pair<char,int>('+',3));
    map.insert(pair<char,int>('-',3));
    map.insert(pair<char,int>('*',5));
    map.insert(pair<char,int>('/',5));
    map.insert(pair<char,int>('%',5));
    map.insert(pair<char,int>('(',1));
    map.insert(pair<char,int>(')',8));
    map.insert(pair<char,int>('^',7));
    map.insert(pair<char,int>('&',7));
    return map[ch];
}

int calculate::osp(char ch) {
    map<char,int> map;
    map.insert(pair<char,int>('=',0));
    map.insert(pair<char,int>('+',2));
    map.insert(pair<char,int>('-',2));
    map.insert(pair<char,int>('*',4));
    map.insert(pair<char,int>('/',4));
    map.insert(pair<char,int>('%',4));
    map.insert(pair<char,int>('(',8));
    map.insert(pair<char,int>(')',1));
    map.insert(pair<char,int>('^',6));
    map.insert(pair<char,int>('&',6));
    return map[ch];
}
