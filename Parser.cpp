#include "Parser.h"

std::string Parser::infixToPostfix(const std::string& expression)
{
    std::stringstream postfix;
    std::string currentNumber;
    Queue<std::string> outputQueue;
    Stack<char> operatorStack;

    for (char c : expression)
    {
        if (std::isspace(c))
        {
            continue;
        }
        else if (std::isdigit(c))
        {
            currentNumber += c;
        }
        else if (isOperator(c))
        {
            if (!currentNumber.empty())
            {
                outputQueue.enqueue(currentNumber);
                currentNumber.clear();
            }

            while (!operatorStack.empty() && operatorStack.top() != '(' && getPrecedence(operatorStack.top()) >= getPrecedence(c))
            {
                outputQueue.enqueue(std::string(1, operatorStack.top()));
                operatorStack.pop();
            }

            operatorStack.push(c);
        }
        else if (c == '(')
        {
            operatorStack.push(c);
        }
        else if (c == ')')
        {
            if (!currentNumber.empty())
            {
                outputQueue.enqueue(currentNumber);
                currentNumber.clear();
            }

            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                outputQueue.enqueue(std::string(1, operatorStack.top()));
                operatorStack.pop();
            }

            if (operatorStack.empty())
            {
                throw std::runtime_error("Mismatched parentheses");
            }

            operatorStack.pop();
        }
        else
        {
            throw std::runtime_error("Invalid character in the expression");
        }
    }

    if (!currentNumber.empty())
    {
        outputQueue.enqueue(currentNumber);
        currentNumber.clear();
    }

    while (!operatorStack.empty())
    {
        if (operatorStack.top() == '(')
        {
            throw std::runtime_error("Mismatched parentheses");
        }

        outputQueue.enqueue(std::string(1, operatorStack.top()));
        operatorStack.pop();
    }

    while (!outputQueue.empty())
    {
        postfix << outputQueue.dequeue() << " ";
    }

    return postfix.str();
}


bool Parser::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int Parser::getPrecedence(char c) const
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    return 0;
}
