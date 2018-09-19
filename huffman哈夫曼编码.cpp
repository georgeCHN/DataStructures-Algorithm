// ConsoleApplication34.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include<cassert>
#include<string>
using namespace std;
//开始做文本统计需要的结构体
struct word {
	char symbol;
	int weit;
};
int length = 0;//txt文本共有多少个节点
int length1 = 0;//sw数组中共有多少个不同的字符
word sw[128];//统计权值与字符
int databuff[1000];//原始统计
#define leafnumber 37
#define totalnumber leafnumber*2-1
#define maxValue 1000
typedef struct {
	char data;
	int weight;
	int lchild, rchild, parent;

}HuffmanNode;//叶子节点的声明
typedef struct {
	HuffmanNode elem[totalnumber];//静态链表，树结构的声明
	int n;/*当前外节点的个数*/
}HuffmanTree;
class huffman {
private:
	HuffmanTree HT;
public:
	huffman();
	void createhuffmantree();
	void display();//显示建好的Huffman树
	void coding();
};
huffman::huffman()//类中成员的初始化
{
	HT.n = leafnumber;
	for (int i = 0; i<leafnumber; i++)
	{
		HT.elem[i].weight = sw[i].weit;
		HT.elem[i].data = sw[i].symbol;
	}for (int i = 0; i<totalnumber; i++)
		HT.elem[i].parent = HT.elem[i].lchild = HT.elem[i].rchild = -1;
	for (int i = leafnumber; i<totalnumber; i++)
		HT.elem[i].data = '$';
}
void huffman::coding()
{
	cout << "coding list:" << endl << "************************************" << endl;
	for (int i = 0; i<leafnumber; i++)//只用对前面leafnumber个叶子节点需要编码
	{
		int temp = i;
		cout << "character:" << "\t" << HT.elem[temp].data << "\t";
		while (HT.elem[temp].parent != -1)
		{
			//叶子节点的位置

			if (HT.elem[HT.elem[temp].parent].lchild == temp)
			{
				cout << "0 "; temp = HT.elem[temp].parent; continue;
			}
			if (HT.elem[HT.elem[temp].parent].rchild == temp)
			{
				cout << "1 "; temp = HT.elem[temp].parent;
			}

		}
		cout << endl;

	}


}
void huffman::display()
{
	for (int i = 0; i<HT.n; i++)
		cout << i << '\t' << "data:" << HT.elem[i].data << '\t' << "weitght" << HT.elem[i].weight << "\t" << " parent:" << HT.elem[i].parent << " left:" << HT.elem[i].lchild << " right " << HT.elem[i].rchild << endl;

}
void huffman::createhuffmantree()
{
	int i, j, p1,p2, min1, min2;//p1记最小的数的位置，p2记次小的树。这里选择这种方法，而放弃选用堆的方法，因为。堆涉及到删除和插入的堆得重建，过程繁琐。且容易出错
	p1 = 0;
	for (i = leafnumber; i<totalnumber; i++)//在我建了堆后记录父节点不如用数组方便直观，且操作指针容易出错，故选用了经典的静态数组来存储
	{
		min1 = min2 = maxValue;
		for (j = 0; j<i; j++)
		{
			if (HT.elem[j].parent == -1)
				if (HT.elem[j].weight<min1)
				{
					p2 = p1;  min2 = min1;//如果该数小于两个最小值，则刷新小的节点
					p1 = j;   min1 = HT.elem[j].weight;
				}
				else if (HT.elem[j].weight<min2)//如果仅小于次小值，则刷新次小值即可
				{
					p2 = j; min2 = HT.elem[j].weight;
				}

		}
		HT.elem[i].lchild = p1; HT.elem[i].rchild = p2;
		HT.elem[i].weight = HT.elem[p1].weight + HT.elem[p2].weight;
		HT.elem[p1].parent = HT.elem[p2].parent = i;//子节点链接父节点
	}

	HT.n = totalnumber;
}

void statistical()//统计不同的字符和各自的权值的函数
{
	bool bools;
	int temp;
	word *ptr = sw;
	for (int i = 0; i<128; i++)
	{
		bools = 0;
		temp = 0;
		for (int j = 0; j<length; j++)
			if (databuff[j] == i)
			{
				bools = 1; temp++;
			}
		if (bools)
		{
			length1++;
			ptr->symbol = i;
			ptr->weit = temp;
			ptr = ptr + 1;
		}
	}

}
void show_char_weit()//显示每个字符和对应的权值
{
	word* temp = sw;
	cout << endl;
	for (int j = 0; j<length1; j++, temp++)
		cout << "symbol:" << temp->symbol << "      wit:" << temp->weit << endl;
}
void readTxt(string file)
{
	ifstream infile;
	infile.open("C:\\news.txt");   //将文件流对象与文件连接起来
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行
	char c;
	while (!infile.eof())
	{
		infile >> c;
		//cout<<c<<"\t";
		databuff[length++] = c;
	}
	cout << endl;
	infile.close();             //关闭文件输入流
}
int main(void)
{

	readTxt("C:\\new.txt");//读取文件的函数
	statistical();//根据字符的ASCII编码来统计，统计各个字符和对应的权值
	show_char_weit();//显示字符和对应的权值
	huffman h1;
	h1.createhuffmantree();//创建一个huffman树
	h1.display();//显示创建好的huffman树
	h1.coding();//huffman编码，并将其显示出来


}
