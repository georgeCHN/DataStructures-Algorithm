//
// Created by george on 19/8/25.
//

#include "huffman.h"
#include <iostream>
#include<stack>
using namespace std;
void huffman::createTree()
{
    //p1记最小的数的位置，p2记次小的树
    int  p1,p2, min1, min2;
    for (int i = leafCnt; i<totalCnt; i++){
        min1 = min2 = INT32_MAX;
        p1=p2=-1;
        for (int j = 0; j<i; j++){
            if (HT[j].parent == -1){
                //如果该数小于两个最小值，则刷新小的节点
                if (HT[j].weight<min1){
                    p2 = p1;
                    min2 = min1;
                    p1 = j;
                    min1 = HT[j].weight;
                }else if (HT[j].weight<min2){
                    //如果仅小于次小值，则刷新次小值即可
                    p2 = j;
                    min2 = HT[j].weight;
                }
            }
        }
        //最后只有一个中间节点的情况
        if(p2==-1){
            HT[p1].parent=-1;
            break;
        }
        HT[i].lchild = p1; HT[i].rchild = p2;
        HT[i].weight = HT[p1].weight + HT[p2].weight;
        HT[p1].parent = HT[p2].parent = i;
    }
}
void huffman::encodeInfo()
{
	cout << "*****************code list*******************" << endl;
    //只用对前面leafCnt个叶子节点需要编码
	for (int i = 0; i<leafCnt; i++){
		int tmp = i;
		cout << HT[tmp].data << ":";
		stack<char> code;
		//用堆栈来逆序存储编码信息
		while (HT[tmp].parent != -1){
			//叶子节点的位置
			if (HT[HT[tmp].parent].lchild == tmp)
			    code.push('0');
			else if (HT[HT[tmp].parent].rchild == tmp)
				code.push('1');
            tmp = HT[tmp].parent;
		}
		while(!code.empty()){
            char top = code.top();
            cout<<top;
            code.pop();
		}
		cout << endl;
	}
}
