//
// Created by george on 19/8/25.
//

#ifndef HUFFCODE_HUFFMAN_H
#define HUFFCODE_HUFFMAN_H
#include <string>
using namespace std;
//declaration of tree node
typedef struct {
    char data;
    int weight;
    int lchild, rchild, parent;
}HuffmanNode;

class huffman {
private:
    //number of leaf
    int leafCnt=0;
    //number of total node
    int totalCnt=0;
    //an array of node
    HuffmanNode* HT;
    //from a txt file read raw char info
    void readTxt( string file);
    //calculate different char and weight to build huffman tree
    void init(char* buff,int file_len);
public:
    //param1 is a full file path
    explicit huffman(string filePath);
    //create huffman tree structure
    void createTree();
    //print huffman tree info
    void encodeInfo();
    //show huffman tree node info
    void display();
    //show text file char-weight info
    void show_char_weight();
};
#endif //HUFFCODE_HUFFMAN_H
