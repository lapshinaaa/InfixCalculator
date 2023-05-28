#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

// *** It is not possible to write the implementation of a template class in a separate cpp file and compile.
// All the ways to do so, if anyone claims, are workarounds to mimic the usage of separate cpp file but practically
// if you intend to write a template class library and distribute it with header and lib files to hide the implementation,
// it is simply not possible *** .

template <typename T>
class Stack {
public:
    Stack();
    ~Stack();

    void push(const T& data);
    T pop();
    T top() const;
    bool empty() const;
    int size() const;
    void clear();

private:
    List<T> list;
};

template <typename T>
Stack<T>::Stack() = default;

template <typename T>
Stack<T>::~Stack() = default;

template <typename T>
void Stack<T>::push(const T& data) {
    list.push_front(data);
}

template <typename T>
T Stack<T>::pop() {
    T data = list[0]; // getting the top element
    list.pop_front(); // removing the element from the stack
    return data;
}

template <typename T>
T Stack<T>::top() const {
    return list[0];
}

template <typename T>
bool Stack<T>::empty() const {
    return list.get_size() == 0;
}

template <typename T>
int Stack<T>::size() const {
    return list.get_size();
}

// CLEARING THE STACK
template<typename T>
void Stack<T>::clear()
{
    list.clear();
}

#endif // STACK_H
