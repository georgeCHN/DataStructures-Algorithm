#include<iostream>
#include "calculate.h"
int main()
{

    string tips = "***********************  欢迎使用 calculator1.0  ***********************\n\
        \t\t\t使用说明:\n表达式可包含:\n1. 加(+)、减(-)、乘(*)、除(/)、求模(%)、开方(&)、乘方(^)运算符\n2.括号\n\
        请输入表达式<以等号'='结束>\n";
    bool ErrorFlag=false;
    cout << tips;
    char flag = 'Y';
    while (flag == 'Y' || flag == 'y') {
        ListStack<double> OPERATOR_NUMBER;
        ListStack<char> OPERATOR_SYMBOL;
        calculate myCalculate;
        OPERATOR_SYMBOL.push('=');
        //正在处理的前一个字符
        char priorChar = '=';
        char ch;
        cin >> ch;
        while (ch != '=' || OPERATOR_SYMBOL.topElem() != '=') {
            //对于数字做处理
            if (calculate::isdigit(ch) || ch == '.') {
                double number;
                cin.putback(ch);
                cin >> number;
                OPERATOR_NUMBER.push(number);
                calculate::getNextChar(ch);
                priorChar = '0';
            }
            //对于操作符做处理
            else if(calculate::isOperator(ch)){
                /*
                *对于表达式首个数的符号为负值,如-2+3=
                *或者中途有负值，但需要用括号括起来,如2+（-3）=
                */
                if ((priorChar == '=' || priorChar == '(') && (ch == '+' || ch == '-'))
                    OPERATOR_NUMBER.push(0);
                priorChar = ch;
                char last_operator = OPERATOR_SYMBOL.topElem();
                bool outer_larger=myCalculate.isp(last_operator) < myCalculate.osp(ch);
                bool inner_larger=myCalculate.isp(last_operator) > myCalculate.osp(ch);
                if (outer_larger) {
                    OPERATOR_SYMBOL.push(ch);
                    calculate::getNextChar(ch);
                }
                else if (inner_larger) {
                    bool process_flag = myCalculate.inner_larger(OPERATOR_NUMBER, OPERATOR_SYMBOL);
                    if(!process_flag) break;
                }
                //如果运算符相等，从运算符堆栈中弹出数据，所以在程序开始时，要压入一个'='号
                else{
                    OPERATOR_SYMBOL.pop();
                    calculate::getNextChar(ch);
                }
            }
            else{
                cout << "表达式中出现非法字符!" << endl;
                ErrorFlag = true;
                break;
            }
        }
        if(!ErrorFlag)
            cout << "answer is " << OPERATOR_NUMBER.topElem() << endl;
        cout << "是否继续<Y/N>?";
        cin >> flag;
    }
    return 0;
}


