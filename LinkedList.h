#ifndef LISTCLASS_LINKEDLIST_H
#define LISTCLASS_LINKEDLIST_H

#include "LinkedList.h"

class List {
public:
    List();
    ~List();
    void insert(int value, int index);
    void remove (int data);
    void removeAt(int index);
    void pop_back();
    void print();
    void push_front(int data);
    void push_back(int data);
    void pop_front();
    void clear();
    int search(int data);
    int get_size() const { return size; }
    int& operator[] (const int index);
private:
    class Node
            {
    public:
        // constructor (just written differently: The initializer list approach)
        Node(int data = 0, Node* ptrNextNode = nullptr) : data(data), ptrNextNode(ptrNextNode) {}
        Node* ptrNextNode;
        int data;
    };

    Node* head;
    int size;

};

#endif //LISTCLASS_LINKEDLIST_H