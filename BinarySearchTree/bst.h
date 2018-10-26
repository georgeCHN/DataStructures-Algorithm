#pragma once
#include "pch.h"
#include<iostream>
using namespace std;
template<typename E>
class BSTNode {
public:
	E it;
	BSTNode* left;
	BSTNode* right;
	BSTNode(E v,BSTNode<E>* l=NULL,BSTNode<E>* r=NULL) {
		it = v;
		left = l;
		right = r;
	}
};
template<typename E>
class BST {
private:
	BSTNode<E>* root;
	int nodecount;
	void clearhelp(BSTNode<E>*);
	BSTNode<E>* inserthelp(BSTNode<E>*, const E&);
	BSTNode<E>* deletemin(BSTNode<E>*);
	BSTNode<E>* getmin(BSTNode<E>*);
	BSTNode<E>* removehelp(BSTNode<E>*root,const E&it);
	E findhelp(BSTNode<E>*,const E& it)const;
	void printhelp(BSTNode<E>*, int)const;
public:
	BST() { root = NULL; nodecount = 0; }
	~BST() { clearhelp(root); }
	void clear() {
		/*reinitialize tree*/
		clearhelp(root);
		root = NULL;
		nodecount = 0;
	}
	void insert(const E&e) {
		root = inserthelp(root, e);
		nodecount++;
	}
	E remove(const E&e) {
		E temp = findhelp(root, e);
		if (temp != NULL) {
			root = removehelp(root, e);
			nodecount--;
		}
		return temp;
	}
	E find(const E&e)const { return findhelp(root, e); }
	int size() { return nodecount; }
	void print()const {
		if (root == NULL) cout << "The BST is empty.\n";
		else printhelp(root, 0);
	}
};
template<typename E>
BSTNode<E>* BST<E>::getmin(BSTNode<E>*root) {
	if (root->left == NULL)return root;
	else 
		return getmin(root->left);
	
}
template<typename E>
E BST<E>::findhelp(BSTNode<E>*root, const E&it)const {
	if (root == NULL)return NULL;
	if (it < root->it)
		return findhelp(root->left, it);
	else if (it > root->it)
		return findhelp(root->right, it);
	else
		return root->it;
}
template<typename E>
BSTNode<E>* BST<E>::inserthelp(BSTNode<E>*root, const E&it) {
	if (root == NULL)
		return new BSTNode<E>(it);
	if (it < root->it)
		root->left = inserthelp(root->left, it);
	else
		root->right = inserthelp(root->right, it);
	return root;
}
template<typename E>
void BST<E>::printhelp(BSTNode<E>*root, int level)const {
	/*节点深度用缩进空格表示*/
	if (root == NULL)return;
	printhelp(root->left, level + 1);
	for (int i = 0; i < level; i++) {
		cout << " ";
	}
	cout << root->it << "\n";
	printhelp(root->right, level + 1);
}
template<typename E>
BSTNode<E>* BST<E>::deletemin(BSTNode<E>* root) {
	if (root->left == NULL)
		return root->right;
	else {
		root->left = deletemin(root->left);
		return root;
	}
}
template<typename E>
BSTNode<E>* BST<E>::removehelp(BSTNode<E>*root,const E& it) {
	if (root == NULL)return NULL;
	else if (it < root->it)
		root->left = removehelp(root->left, it);
	else if (it > root->it)
		root->right = removehelp(root->right, it);
	else {
		BSTNode<E>*temp = root;
		if (root->left == NULL) {//仅仅有有右子节点
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			root = root->left;
			delete temp;
		}
		else {//左右节点都存在
			BSTNode<E>*temp = getmin(root->right);
			root->it = temp->it;
			root->right = deletemin(root->right);
		}
	}
	return root;
}
template<typename E>
void BST<E>::clearhelp(BSTNode<E>*root) {
	if (root == NULL)return;
	clearhelp(root->left);
	clearhelp(root->right);
	delete root;
}