#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void insertAt(T data, int index);
    void removeAt(int index);
    void removeValue(T data);
    void popBack();
    void print() const;
    void pushFront(T data);
    void pushBack(T data);
    void popFront();
    void clear();
    int search(T data) const;
    int getSize() const { return size; }
    T& operator[](const int index) const;

private:
    class Node {
    public:
        Node* next;
        T data;

        Node(T value = T(), Node* nextNode = nullptr) : data(value), next(nextNode) {}
    };

    Node* head;
    int size;
};

#endif // LINKEDLIST_H
