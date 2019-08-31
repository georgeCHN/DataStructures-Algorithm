//
// Created by george on 19/8/26.
//
#include "huffman.h"
#include<algorithm>
#include<map>
#include <iostream>
#include <fstream>

using namespace std;
map<char,int> symtab;

huffman::huffman(string filePath)//类中成员的初始化
{
    readTxt(filePath);
    HT=new HuffmanNode[totalCnt];
    auto iter=symtab.begin();
    //leaf node init
    for(int i=0;iter!=symtab.end();iter++,i++){
        HT[i].data = iter->first;
        HT[i].weight = iter->second;
    }
    //all node init
    for (int i = 0; i<totalCnt; i++){
        HT[i].parent = HT[i].lchild = HT[i].rchild = -1;
        if(i>=leafCnt)
            HT[i].data = '$';
    }
}
//统计不同的字符和各自的权值的函数
void huffman::init(char* buff,int file_len)
{
    char tmp=buff[0];
    int cnt=1;
    leafCnt=1;
    for(int i=1;i<file_len;i++){
        if(buff[i]==tmp)
            cnt++;
        else{
            symtab.insert(make_pair(tmp,cnt));
            tmp=buff[i];
            cnt=1;
            leafCnt++;
        }
    }
    //防止将最后一个元素漏掉
    symtab.insert(make_pair(tmp,cnt));
    totalCnt=leafCnt*2-1;
    HT=new HuffmanNode[totalCnt];
}
//显示每个字符和对应的权值
void huffman::show_char_weight()
{
    cout<<"char-weight:{";
    //遍历cpp的map
    auto iter=symtab.begin();
    for(;iter!=symtab.end();iter++){
        cout<<iter->first<<":"<<iter->second<<",";
    }
    cout<<"}\n";
}
void huffman::readTxt(string file)
{
    ifstream infile;
    //将文件流对象与文件连接起来
    infile.open(file);
    bool of = infile.is_open();
    if(!of){
        cout<<"open file:'"<<file<<"'failure"<<endl;
        exit(-1);
    }
    char c;
    int cnt=0;
    while (!infile.eof()){
        infile>>c;
        cnt++;
    }
    //cout << "cnt="<<cnt<<endl;
    //清除eof标志
    infile.clear();
    //重新读取文件
    infile.seekg(0,ios::beg);
    //buff存放文件中的字符
    char* buff=new char[cnt];
    int file_len=0;
    //用i控制循环次数，因为eof的标志会导致最后一个字符多读一遍
    for(int i=1;!infile.eof()&&i<cnt;i++){
        infile>>c;
        buff[file_len++] = c;
    }
    infile.close();
    cout<<"file_len:"<<file_len<<endl;
    //对数组排序
    sort(buff,buff+file_len);
    init(buff,file_len);
}
void huffman::display()
{
    for (int i = 0; i<totalCnt; i++){
        cout << i << "\tdata:" << HT[i].data <<
             "\tweight:" << HT[i].weight <<
             "\tparent:" << HT[i].parent <<
             "\tleft:" << HT[i].lchild <<
             "\tright:" << HT[i].rchild << endl;
    }
}