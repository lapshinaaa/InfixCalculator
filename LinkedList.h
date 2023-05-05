#ifndef LISTCLASS_LINKEDLIST_H
#define LISTCLASS_LINKEDLIST_H

#pragma once

#include <iostream>

template <typename T>
class List
{
public:
    List<T>();
    ~List<T>();

    // prototypes of all the necessary functions
    void insert(T data, int index);
    void removeAt(int index);
    void remove(T data);
    void pop_back();
    void print() const;
    void push_front(T data);
    void push_back(T data);
    void pop_front();
    void clear();
    int search(T data) const;
    int get_size() const {return size;}
    T& operator[] (int index);

private:
    template <typename U>
    class Node
    {
    public:
        Node<U> *ptrNextNode; // pointer to the next node (address)
        U data;

        Node (U data = 0, Node<U> *ptrNextNode = nullptr)
        {
            this->data = data;
            this->ptrNextNode = ptrNextNode;
        }
    };

    Node<T> *head;
    int size;
};


#endif //LISTCLASS_LINKEDLIST_H