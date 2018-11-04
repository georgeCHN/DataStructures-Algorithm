#pragma once

#include "pch.h"
#include <iostream>
using namespace std;
template<typename E>
class List {
private:
	List(const List&){}
public:
	List(){}
	virtual ~List(){}
	virtual void clear() = 0;
	virtual void insert(const E&item) = 0;
	virtual void append(const E&item) = 0;
	virtual E remove() = 0;
	virtual void moveToStart() = 0;
	virtual void moveToEnd() = 0;
	virtual void prev() = 0;
	virtual void next() = 0;
	virtual int length()const = 0;
	virtual int currPos()const = 0;
	virtual void moveToPos(int pos) = 0;
	virtual const E& getValue()const = 0;

};
template<typename E>class Link {
public:
	E element;
	Link* next;
	Link(const E&elemval, Link*nextval = NULL) {
		element = elemval;
		next = nextval;
	}
	Link(Link* nextval = NULL) {
		next = nextval;
	}
};
template<typename E>
class LList :public List<E> {
private:
	Link<E>*head;
	Link<E>*tail;
	Link<E>*curr;
	int cnt;
	void init() {
		curr = tail = head = new Link<E>;
		cnt = 0;
	}
	void removeall() {
		while (head != NULL) {
			curr = head;
			head = head->next;
			delete curr;
		}
	}
public:
	LList(int size=0) {
		init();
	}
	
	void clear() {
		removeall();
		init();
	}
	void insert(const E& it) {
		curr->next = new Link<E>(it, curr->next);
	}
	void append(const E&it) {
		tail = tail->next = new Link<E>(it, NULL);
		cnt++;
	}
	//Remove and return current element
	E remove() {
		if (curr->next == NULL) {
			cout << "No element\n";
			return NULL;
		}
		E it = curr->next->element;
		Link<E>* temp = curr->next;
		curr->next = curr->next->next;
		delete temp;
		cnt--;
		return it;
	}
	void moveToStart() {
		curr = head;
	}
	void moveToEnd() {
		curr = tail;
	}
	void prev() {
		if (curr == head)return;
		Link<E>* temp = head;
		/*从链表头开始遍历*/
		while (temp->next != curr)
			temp = temp->next;
		curr = temp;
	}
	void next() {
		if (curr != tail)
			curr = curr->next;
	}
	int length()const {
		return cnt;
	}
	int currPos()const {
		Link<E>* temp = head;
		int i = 0;
		while (temp != curr) {
			temp = temp->next;
			i++;
		}
		return i;
	}
	void moveToPos(int pos) {
		if ((pos < 0) || (pos > cnt)) {
			cout << "out of range\n";
			return;
		}
		curr = head;
		for (int i = 0; i < pos; i++)
			curr = curr->next;
	}
	const E& getValue()const {
		return curr->next->element;
	}
	void show()const {
		Link<E>*temp = head->next
			;
		while (temp != NULL) {
			cout << temp->element << "  ";
			temp = temp->next;
		}
		cout << "\n";
	}
};
