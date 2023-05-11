#include <iostream>
#include <string>
#include "Stack.h"


class PostfixCalculator
{
public:
    PostfixCalculator();
    int calculate(std::string expression);

private:
    Stack stack;
};

PostfixCalculator::PostfixCalculator()
= default;;

int PostfixCalculator::calculate(std::string expression)
{
    Stack stack; // initializing a stack object to store operands (digits)

    // traversing the string, getting all the characters:
    std::string temp; // creating a temporary value
    for (char& c : expression)
    {
        if (std::isdigit(c))
        {
            temp += c;
        }
        else if (c == ' ')
        {
            if (!temp.empty())
            {
                int operand = std::stoi(temp); // converting string to int
                stack.push(operand); // pushing the operand onto the stack
                temp.clear();  // clearing the temporary value
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
    if (!temp.empty())
    {
        int operand = std::stoi(temp);
        stack.push(operand);
    }

    if (stack.size() != 1) // if there's more than one char in the stack
    {
        throw std::runtime_error("Invalid expression. Try again.");
    }

    return stack.top(); // returning the resulting value

}


