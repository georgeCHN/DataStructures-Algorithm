//
// Created by george on 19/8/9.
//

#ifndef CALCULATE_LISTSTACK_H
#define CALCULATE_LISTSTACK_H
#include<iostream>
template<class E>
/*用数组实现栈*/
class ListStack {
private:
    E array[100];
    int top;
    int max;
public:
    ListStack() {
        top = -1;
        max = 99;
    }
    void push(E it) {
        if (top == max) {
            std::cout << "stack is full!" << std::endl;
            return;
        }
        else {
            array[++top] = it;
        }
    }
    E pop() {
        if (top == -1){
            exit(-1);
        }
        else {
            return array[top--];
        }
    }
    E topElem() {
        if (top == -1){
            exit(-1);
        }
        else
            return array[top];
    }
    bool isEmpty() {
        return top==-1;
    }
};
#endif //CALCULATE_LISTSTACK_H
