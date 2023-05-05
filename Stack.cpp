#include "LinkedList.cpp"

template <typename T>
class Stack
{
public:
    // constructor and destructor
    Stack();
    ~Stack();

    // prototypes of all the necessary functions:
    void push (T data);
    T pop();
    T top() const;
    bool empty() const;

private:
    List<T> list;
};


template<typename T>
Stack<T>::Stack()
= default;

template<typename T>
Stack<T>::~Stack()
= default;


// PUSHING THE ELEMENTS ON TOP
template<typename T>
void Stack<T>::push(T data)
{
    list.push_front(data);
}

// EXTRACTING THE TOP ELEMENT FROM THE STACK
template<typename T>
T Stack<T>::pop()
{
    T data = list[0]; // getting the top element
    list.pop_front(); // removing the element from the stack
    return data;
}


// GETTING THE TOP ELEMENT FROM THE STACK
template<typename T>
T Stack<T>::top() const
{
    return list[0];
}

// CHECKING IF STACK IS CURRENTLY EMPTY
template<typename T>
bool Stack<T>::empty() const
{
    return list.get_size() == 0;
}
