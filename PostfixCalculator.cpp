#include <iostream>
#include <string>
#include "PostfixCalculator.h"


// removing the declaration (it's only located in header)
PostfixCalculator::PostfixCalculator() = default;

int PostfixCalculator::calculate(std::string expression)
{
    Stack stack; // initializing a stack object to store operands (digits)

    // traversing the string, getting all the characters:
    for (char& c : expression)
    {
        if (std::isdigit(c)) // if the current char is an operand (digit), push it onto the stack
        {
            stack.push(c - '0'); // converting into integer (from ASCII into int)
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
