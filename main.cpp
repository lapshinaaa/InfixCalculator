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
//    PostfixCalculator calculator;
//    std::string expression;
//    std::getline(std::cin, expression);
//    expression = parser.infixToPostfix(expression);
//    std::cout<<calculator.calculate(expression);
    return 0;
}