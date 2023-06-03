#include <iostream>
#include "InfixCalculator.h"

// Шаблонный Лист
// Шаблонный стэк
// Реализована шаблонная очередь для парсера
// парсер на основе алгоритма шантинг ярда
// инфиксный калькулятор
// учет всех ошибок


int main()
{
    InfixCalculator infixCalculator;
    std::string expression;
    int result;

    std::cout<<"Enter the problem to solve with spaces or without in an Infix form: "<<std::endl;
    std::getline(std::cin, expression); // reading the user input

    try
    {
        result = infixCalculator.calculate(expression);
        std::cout << "Result: " << result << std::endl;
    }
    catch (std::runtime_error &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }



    return 0;
}