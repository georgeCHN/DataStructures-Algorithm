#pragma once
#include "pch.h"
#include<iostream>
using namespace std;
template<typename E>
class Link {
public:
	E element;
	Link<E>* next;
	Link(E elemVal, Link<E>* nextVal = NULL) {
		element = elemVal;
		next = nextVal;
	}
	Link(Link<E>*nextVal = NULL) {
		next = nextVal;
	}
};
template<typename E>
class LQueue {
private:
	Link<E>* front;
	Link<E>* rear;
	int size;
public:
	LQueue() {
		front = rear = new Link<E>;
		size = 0;
	}
	~LQueue(){
		clear();
		delete front;
	}
	void clear() {
		while (front->next != NULL) {
			rear = front;
			front = front->next;
			delete rear;
		}
		rear = front;
		size = 0;
	}
	void enqueue(const E&it) {
		rear->next = new Link<E>(it);
		rear = rear->next;
		size++;
	}
	E dequeue() {
		if (size == 0) {
			cout << "queue is empty!\n";
			return NULL;
		}
		else {
			E it = front->next->element;
			Link<E>* temp = front->next;
			front->next = front->next->next;

			if (temp == rear)
				rear = front;
			delete temp;
			size--;
			return it;
		}
	}
	const E& frontValue()const {
		return front->next->element;
	}
	int length()const {
		return size;
	}
};