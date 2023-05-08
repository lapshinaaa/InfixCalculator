#include <iostream>
#include "PostfixCalculator.h"

int main()
{
    PostfixCalculator calculator;
    std::string expression;
    int result;

    std::cout<<"Enter the problem to solve with spaces in a postfix form: "<<std::endl;
    std::getline(std::cin, expression); // reading the user input

    while (expression != "exit")
    {
        try {
            result = calculator.calculate(expression);
            std::cout << "Result: " << result << std::endl;
        }
        catch (std::runtime_error &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        std::cout << "To exit the program, enter 'exit' or enter another expression: " << std::endl;
        std::getline(std::cin, expression); // reading the user input
    }

    return 0;
}
