// ConsoleApplication39.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class binarySearch {
public:
	//函数传入三个参数，1.数组，2.数组的长度，3.要查询的数，返回该数在数组中的位置
	int binary(int arr[],int len,int num) {
		int l = -1;//左界设置为-1
		int r = len;//右界设为len，这样当l+1==r时，说明遍历完，却没有找到
		while(l +1!= r) {
			int curr = (l + r) / 2;
			if (arr[curr] == num)
				return curr;
			else if (arr[curr] < num)
				l = curr;
			else if (arr[curr] >num)
				r= curr;
		}
		return -1;//表示没有找到
	}
};
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,19,110 };
	binarySearch b1;
	cout<<"该数在数组中的位置是 "<<b1.binary(arr,10,1108)<<endl;
    return 0;
}











