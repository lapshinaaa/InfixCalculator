#ifndef STACK_H
#define STACK_H

#include "LinkedList.cpp"

class Stack {
public:
    // constructor and destructor
    Stack();
    void push(int value);
    int pop();
    int size() const;
    int top() const;
    bool empty() const;

private:
    LinkedList<int> list;
};

#endif //STACK_H
