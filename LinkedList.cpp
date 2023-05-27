#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
class LinkedList {
public:
    LinkedList();
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

template <typename T>
LinkedList<T>::LinkedList() {
    size = 0;
    head = nullptr;
}

template <typename T>
void LinkedList<T>::pushBack(T data) {
    if (head == nullptr) {
        head = new Node(data);
    } else {
        Node* currNode = head;
        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }
        currNode->next = new Node(data);
    }
    size++;
}

template <typename T>
T& LinkedList<T>::operator[](const int index) const {
    int counter = 0;
    Node* currNode = head;
    while (currNode != nullptr) {
        if (counter == index)
            return currNode->data;
        currNode = currNode->next;
        counter++;
    }
    throw std::out_of_range("Index out of range");
}

template <typename T>
void LinkedList<T>::popFront() {
    if (head == nullptr)
        return;
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
}

template <typename T>
void LinkedList<T>::pushFront(T data) {
    head = new Node(data, head);
    size++;
}

template <typename T>
void LinkedList<T>::insertAt(T data, int index) {
    try {
        if (index == 0) {
            pushFront(data);
        } else {
            Node* previousNode = head;
            for (int i = 0; i < index - 1; ++i) {
                if (previousNode == nullptr)
                    throw std::out_of_range("Index out of range");
                previousNode = previousNode->next;
            }
            if (previousNode == nullptr)
                throw std::out_of_range("Index out of range");
            Node* newNode = new Node(data, previousNode->next);
            previousNode->next = newNode;
            size++;
        }
    } catch (std::out_of_range& e) {
        std::cout << "Error occurred while inserting an element: " << e.what() << std::endl;
    }
}

template <typename T>
void LinkedList<T>::print() const {
    Node* currNode = head;
    std::cout << "List: ";
    while (currNode != nullptr) {
        std::cout << currNode->data << " ";
        currNode = currNode->next;
    }
    std::cout << std::endl;
}

template <typename T>
void LinkedList<T>::removeAt(int index) {
    try {
        if (index == 0) {
            popFront();
        } else {
            Node* previousNode = head;
            for (int i = 0; i < index - 1; ++i) {
                previousNode = previousNode->next;
            }
            Node* toDelete = previousNode->next;
            previousNode->next = toDelete->next;
            delete toDelete;
            size--;
        }
    } catch (std::exception& e) {
        std::cout << "Error occurred while removing an element at index. Index out of range." << e.what() << std::endl;
    }
}

template <typename T>
void LinkedList<T>::popBack() {
    if (head == nullptr) {
        return;
    }
    removeAt(size - 1);
}

template <typename T>
void LinkedList<T>::removeValue(T data) {
    Node* currNode = head;
    Node* previousNode = nullptr;
    while (currNode != nullptr) {
        if (currNode->data == data) {
            if (previousNode == nullptr) {
                popFront();
            } else {
                previousNode->next = currNode->next;
                delete currNode;
                size--;
            }
            return;
        }
        previousNode = currNode;
        currNode = currNode->next;
    }
}

template <typename T>
int LinkedList<T>::search(T data) const {
    Node* currNode = head;
    int index = 0;
    while (currNode != nullptr) {
        if (currNode->data == data) {
            return index;
        }
        currNode = currNode->next;
        index++;
    }
    return -1;
}

template <typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) {
        popFront();
    }
}

#endif // LINKEDLIST_H
