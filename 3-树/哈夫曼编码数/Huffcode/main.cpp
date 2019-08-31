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
