// ConsoleApplication47.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "calculate.h"


int main()
{

	string tips = "***********************  欢迎使用 calculator1.0  ***********************\n";
	tips += "\t\t\t使用说明:\n表达式可包含:\n1. 加(+)、减(-)、乘(*)、除(/)、求模(%)、开方(&)、乘方(^)运算符\n2.括号\n";
	tips += "请输入表达式<以等号'='结束>\n";
	bool ErrorFlag=false;
	cout << tips;
	char flag = 'Y';
	while (flag == 'Y' || flag == 'y') {
		Lstack<double> OPND;
		Lstack<char> OPTR;
		calculate myCalculate;
		OPTR.push('=');
		//OPND.push(0); 
		/*正在处理的前一个字符*/
		char priorChar = '=';
		char ch;
		cin >> ch;
		while (ch != '=' || OPTR.topElem() != '=') {
			/*对于数字做处理*/
			if (myCalculate.isdigit(ch) || ch == '.') {

				double number;
				cin.putback(ch);
				cin >> number;
				
				OPND.push(number);
				myCalculate.getNextChar(ch);
				priorChar = '0';
			}
			/*对于操作符做处理*/
			else if(myCalculate.isOperator(ch)){
			
				/*
				对于表达式首个数的符号为负值,如-2+3=
				或者中途有负值，但需要用括号括起来,如2+（-3）=
				*/
				if ((priorChar == '=' || priorChar == '(') && (ch == '+' || ch == '-'))
					OPND.push(0);
					priorChar = ch;
					char temp = OPTR.topElem();
					if (myCalculate.isp(temp) < myCalculate.osp(ch)) {
						OPTR.push(ch);
						myCalculate.getNextChar(ch);
					}
					else if (myCalculate.isp(temp) > myCalculate.osp(ch)) {
						double x, y;
						char operTemp;/*暂存操作符*/
						if (myCalculate.get_two_operands(OPND, x, y)) {
							operTemp = OPTR.pop();
							double resultTemp;
							if (myCalculate.cal(operTemp, x, y, resultTemp)) {
								OPND.push(resultTemp);
							}
							/*继续处理当前字符*/
						}
						else {
							cout << "语法错误" << endl;
							break;
						}
					}
					/*如果运算符相等，从运算符堆栈中弹出数据，所以在程序开始时，要压入一个'='号*/
					else{
						char temps = OPTR.pop();
						myCalculate.getNextChar(ch);
					}
				
				

			}
			else{
				cout << "表达式中出现非法字符!" << endl;
				ErrorFlag = true;
				break;
			}
			
		}
		if(!ErrorFlag)
		cout << "answear is "<<OPND.topElem() << endl;
		cout << "是否继续<Y/N>?";
		cin >> flag;
	}
	return 0;
}


