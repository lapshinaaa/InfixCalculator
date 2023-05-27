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

private:
    LinkedList<T> list;
};

#endif // QUEUE_H
