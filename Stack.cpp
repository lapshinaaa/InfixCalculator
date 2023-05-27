#include "Stack.h"

Stack::Stack()
= default;

Stack::~Stack()
= default;


// PUSHING THE ELEMENTS ON TOP
void Stack::push(int data)
{
    list.push_front(data);
}

// EXTRACTING THE TOP ELEMENT FROM THE STACK
int Stack::pop()
{
    int data = list[0]; // getting the top element
    list.pop_front(); // removing the element from the stack
    return data;
}


// GETTING THE TOP ELEMENT FROM THE STACK
int Stack::top() const
{
    return list[0];
}


// CHECKING IF STACK IS CURRENTLY EMPTY
bool Stack::empty() const
{
    return list.get_size() == 0;
}

int Stack::size() const
{
    return list.get_size();
}