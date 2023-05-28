#include "Parser.h"

// takes an infix expression as input and returns its postfix representation as a string
std::string Parser::infixToPostfix(const std::string& expression)
{
    std::stringstream postfix;

    for (char c : expression)
    {
        if (std::isspace(c))
        {
            continue; // skip whitespace
        }
        else if (std::isdigit(c)) // if it's a digit -> add it to the output queue
        {
            outputQueue.enqueue(c);
        }
        else if (isOperator(c)) // if it's an operator -> enter the loop
        {
            while (!operatorStack.empty() && operatorStack.top() != '(' && getPrecedence(operatorStack.top()) >= getPrecedence(c))
            {
                // In each iteration, an operator is popped from the operatorStack and added to the outputQueue
                outputQueue.enqueue(operatorStack.pop());
            }
            operatorStack.push(c);
        }
        else if (c == '(')
        {
            operatorStack.push(c); // pushing the char onto the stack
        }
        else if (c == ')')
        {
            // if the current symbol is ')' -> enter the loop
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                outputQueue.enqueue(operatorStack.pop());
            }

            if (!operatorStack.empty() && operatorStack.top() == '(')
            {
                operatorStack.pop(); // discard '('
            }

            // If the operatorStack becomes empty before finding an opening parenthesis,
            // it means there are mismatched parentheses in the expression
            else
            {
                throw std::runtime_error("Mismatched parentheses"); // Throw an exception for mismatched parentheses
            }
        }
        else
        {
            throw std::runtime_error("Invalid character in the expression"); // Throw an exception for invalid characters
        }
    }

    while (!operatorStack.empty())
    {
        if (operatorStack.top() == '(')
        {
            throw std::runtime_error("Mismatched parentheses"); // Throw an exception for mismatched parentheses
        }
        outputQueue.enqueue(operatorStack.pop());
    }

    while (!outputQueue.empty())
    {
        // here 'postfix' is a stringstream object
        postfix << outputQueue.dequeue() << " "; // Separate symbols with spaces
    }

    // converting a stringstream object back to its string format and returning it
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

void Parser::clear()
{
    operatorStack.clear();
    outputQueue.clear();
}