#include "LinkedList.h"
#include <iostream>

int main() {

    List list;
    int method = 0;
    int data, index;

    std::cout<<"Choose the operation upon your linked list: "<<std::endl;
    std::cout<<"1 -> Add element to the front"<<"\n";
    std::cout<<"2 -> Add element to the back"<<"\n";
    std::cout<<"3 -> Add element at index"<<"\n";
    std::cout<<"4 -> Remove value"<<"\n";
    std::cout<<"5 -> Remove at index"<<"\n";
    std::cout<<"6 -> Remove from the front"<<"\n";
    std::cout<<"7 -> Remove from the end"<<"\n";
    std::cout<<"8 -> Find value"<<"\n";
    std::cout<<"9 -> Find element at index"<<"\n";
    std::cout<<"10 -> Print out all the elements"<<"\n";
    std::cout<<"11 -> Exit the program"<<"\n";

    while(method != 11)
    {
        // entering the number of method:
        std::cin>>method;

        switch(method)
        {
            case 1:
                std::cout<<"Enter the element to add to the front: ";
                std::cin>>data;
                list.push_front(data);
                break;


            case 2:
                std::cout<<"Enter the element to add to the back: ";
                std::cin>>data;
                list.push_back(data);
                break;

            case 3:
                std::cout<<"Enter the element and index to be added at: ";
                std::cin>>data;
                std::cin>>index;
                list.insert(data, index);
                break;

            case 4:
                std::cout<<"Enter the element to remove from the list (first occurrence): ";
                std::cin>>data;
                list.remove(data);
                break;

            case 5:
                std::cout<<"Enter the index of the element you wish to remove: ";
                std::cin>>index;
                list.removeAt(index);
                break;

            case 6:
                std::cout<<"The 'head' element was removed";
                list.pop_front();
                break;

            case 7:
                std::cout<<"The 'tail' element was removed";
                list.pop_back();
                break;

            case 8:
                std::cout<<"Enter the element you want to find: ";
                std::cin>>data;
                index = list.search(data);
                std::cout<<"The first occurrence of the entered element happens at index: "<<index<<std::endl;
                break;

            case 9:
                std::cout<<"Enter the index: ";
                std::cin>>index;
                data = list[index];
                std::cout<<"The element at the given index is: "<<data<<std::endl;
                break;

            case 10:
                std::cout<<"Here's your linked list: ";
                list.print();
                break;

            case 11:
                std::cout<<"The program successfully exited.";
                break;

            default:
                std::cout<<"The operation entered is invalid.";
                break;

        }

    }

    return 0;
}
