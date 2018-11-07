#pragma once
#include "pch.h"
#include <iostream>
using namespace std;
template<typename E>
class Queue {
private:
	int maxSize;
	int front;
	int rear;
	E* listArray;/* Array holding queue elements */
public:
	Queue(int size = 10) {
		maxSize = size;
		/* rear+1==front represent queue is empty */
		rear = 0;
		front = 1;
		listArray = new E[maxSize];
	}
	~Queue() {
		delete[]listArray;
	}
	void clear() {
		/* Reinitialize */
		rear = 0;
		front = 1;
	}
	const E& frontValue()const {
		if (length() != 0)
			return listArray[front];
		else
			return NULL;
	}
	int length()const {
		return ((rear + maxSize) - front + 1) % maxSize;
	}
	void enqueue(const E&it) {
		if ((rear + 2) % maxSize != front) {
			rear = (rear + 1) % maxSize;
			listArray[rear] = it;
			cout << "enquene " << it << endl;
		}
		else {
			cout << "queue is full!\n";
		}
	}
	E dequeue() {
		if (length()!=0) {
			E it = listArray[front];
			front = (front + 1) % maxSize;
			
			return it;
		}
		else {
			cout << "queue is empty!\n";
			return NULL;
		}	

	}

};