#include <iostream>
#include "InfixCalculator.h"

int main()
{
    InfixCalculator infixCalculator;
    std::string expression;
    int result;

    std::cout<<"Enter the problem to solve with spaces or without in an Infix form: "<<std::endl;
    std::getline(std::cin, expression); // reading the user input

    while (expression != "exit")
    {
        try
        {
            result = infixCalculator.calculate(expression);
            std::cout<<"Result: "<<result<<std::endl;
        }
        catch (std::runtime_error &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }

        std::cout << "To exit the program, enter 'exit' or enter another expression: " << std::endl;
        std::getline(std::cin, expression); // reading the user input

    }

//    Parser parser;
//    InfixCalculator calculator;
//    std::string expression;
//    std::string postfix;
//    std::getline(std::cin, expression);
//    postfix = parser.infixToPostfix(expression);
//    std::cout<<postfix<<std::endl;
//    std::cout<<calculator.calculate(postfix);
    return 0;
}