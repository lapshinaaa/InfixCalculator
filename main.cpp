#include <iostream>
#include "PostfixCalculator.h"
#include "Queue.h"

int main()
{
    Queue<int> queue;
    queue.enqueue(5);
    std::cout<<"The first elem is: "<<queue.front();
    return 0;
}