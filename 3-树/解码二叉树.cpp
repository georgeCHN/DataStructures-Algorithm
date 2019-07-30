
#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
class Link {
public:
	Link* left;
	Link* right;
	char element;
	Link(char elemVal, Link* leftVal = NULL,Link* rightVal=NULL) {
		left= leftVal;
		right = rightVal;
		element = elemVal;
	}
};
class BinaryTree {
private:
	Link* root;
public:
	void print(Link* root) {
		if (root == NULL)
			return;
		/*打印叶子节点*/
			cout << root->element << " ";
			print(root->left);
			print(root->right);

    }
	Link* createTree(string& str) {
		char tempChar = str[0];
		str = str.substr(1, str.length() - 1);
		if (tempChar == '/')
			return NULL;
		Link* root = new Link(tempChar);
		root->left = createTree(str);
		root->right = createTree(str);

		return root;
		
	}
};
int main()
{
	string str1 = "AB/D//CEG///FH//I//";
	BinaryTree b1;
	Link* root=b1.createTree(str1);
	b1.print(root);
}

