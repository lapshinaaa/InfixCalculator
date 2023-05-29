#include <iostream>
#include <string>
#include "PostfixCalculator.h"

// removing the declaration (it's only located in header)
PostfixCalculator::PostfixCalculator() = default;

int PostfixCalculator::calculate(std::string expression)
{
    int number = 0; // variable for an int (including multiple-digit ones)

    for (char& c : expression)
    {
        if (std::isdigit(c))
        {
            number = number * 10 + (c - '0'); // adding digits to the current number
        }
        else if (c == ' ')
        {
            if (number != 0) // if the number has been formed
            {
                stack.push(number);
                number = 0; // resetting the number variable
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') // if the current char is an operation char
        {
            int operand_2 = stack.pop();
            int operand_1 = stack.pop();
            int result = 0;

            switch (c)
            {
                case '+':
                    result = operand_1 + operand_2;
                    break;

                case '-':
                    result = operand_1 - operand_2;
                    break;

                case '*':
                    result = operand_1 * operand_2;
                    break;

                case '/':
                    if (operand_2 == 0)
                    {
                        throw std::runtime_error("Division by zero!");
                    }
                    result = operand_1 / operand_2;
                    break;
            }
            stack.push(result);
        }
        else if (c == ' ') // if we're encountering a space, ignore it
        {

        }
        else
        {
            throw std::runtime_error("Invalid expression. Try again.");
        }
    }

    if (stack.size() != 1) // if there's more than one char in the stack
    {
        throw std::runtime_error("Invalid expression. Try again.");
    }

    return stack.top(); // returning the resulting value
}