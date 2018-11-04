#pragma once
#include<iostream>
using namespace std;
template<typename E>
class Link {
public:
	E element;
	Link* next;
	Link(E elemVal, Link* nextVal = NULL) {
		element = elemVal;
		next = nextVal;
	}
	Link(Link*nextVal = NULL) {
		next = nextVal;
	}
};
template<typename E>
class Stack {
private:
	Link<E>* top;
	int cnt;
public:
	Stack() {
		top = new Link<E>;
		cnt = 0;
	}
	void push(E it) {
		top = new Link<E>(it, top);
		cnt++;
	}
	E pop() {
		if (isEmpty())
			return NULL;

		Link<E>* temp = top;
		top = top->next;
		E it = temp->element;
		delete temp;
		cnt--;
		return it;
	}
	bool isEmpty() {
		if (cnt <= 0)
			return true;
		else
			return false;
	}

};