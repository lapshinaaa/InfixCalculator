#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

class Stack {
public:
    // constructor and destructor
    Stack();
    ~Stack();

    // prototypes of all the necessary functions:
    void push(int data);
    int pop();
    int size() const;
    int top() const;
    bool empty() const;

private:
    List<int> list;
};

#endif //STACK_H