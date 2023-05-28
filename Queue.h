#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template <typename T>
class Queue {
public:
    Queue();
    void enqueue(T data);
    T dequeue();
    T front() const;
    int size() const;
    bool empty() const;
    void clear();

private:
    List<T> list;
};

template <typename T>
Queue<T>::Queue() = default; // constructor for Queue

// ADDING ELEMENTS TO THE QUEUE
template <typename T>
void Queue<T>::enqueue(T data) {
    list.push_back(data);
}


// POPPING THE FIRST ELEMENT OF THE QUEUE
template <typename T>
T Queue<T>::dequeue() {
    T data = list[0]; // getting the element
    list.removeAt(0);  // removing it
    return data;
}

// GETTING THE FIRST ELEMENT OF THE QUEUE (NO DELETION)
template <typename T>
T Queue<T>::front() const {
    return list[0];
}

// GETTING THE SIZE OF THE QUEUE
template <typename T>
int Queue<T>::size() const {
    return list.get_size();
}


// CHECKING IF THE QUEUE IS EMPTY
template <typename T>
bool Queue<T>::empty() const {
    return list.get_size() == 0;
}

// CLEARING THE QUEUE
template<typename T>
void Queue<T>::clear()
{
    list.clear();
}

#endif // QUEUE_H
