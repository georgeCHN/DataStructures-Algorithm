/**
* Huffman算法核心是，用一个结构体数组，其中结构体包含权值和字符
* 每个节点默认的parent指针是-1
* 每次从数组中取出两个权值最小的数据，令其归并，并修改parent指针
* parent==-1作为是否归并过的标志
* 依次进行归并，归并到最后时，从1--leafCount，依次追朔其parent指针，并打印出来
* 可以把路径存在栈中，便于正序打出来
*
*
*/
#include "huffman.h"
int main() {


    //huffman h1(R"(C:\Users\geoge\Desktop\new.txt)");
    huffman h1(R"(C:\Users\geoge\Desktop\new1.txt)");
    h1.show_char_weight();//显示字符和对应的权值
    h1.createTree();
    h1.display();
    h1.encodeInfo();
    return 0;
}
