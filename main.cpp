#include "LinkedList.h"
#include <iostream>

int main() {

    List list;

    list.push_back(5);
    list.push_front(7);
    list.push_back(10);
    list.push_back(15);
    list.push_back(5);
    list.print();
    list.remove(5);
    list.print();
    std::cout<<list.search(10);

    return 0;
}
