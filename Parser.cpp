#include "Parser.h"

// This parser is designed to convert an infix mathematical expression into postfix notation using
// the Shunting Yard algorithm

// 15
// 2 3
//2 - -3
//15 + 5 8
//15 5 /

std::string Parser::infixToPostfix(const std::string& expression)
{
    std::string token; // variable to store the current token
    bool expectOperand = true; // flag to track if an operand is expected

    for (char c : expression)
    {
        if (std::isspace(c)) // if it is a space, process the current token
        {
            if (!token.empty())
            {
                if (expectOperand) // checking if we're expecting an operand
                {
                    if (std::isdigit(token[0]))
                    {
                        outputQueue.enqueue(token); // add the number to the output queue
                        expectOperand = false;
                    }
                    else
                    {
                        throw std::runtime_error("Invalid token in the expression: " + token);
                    }
                }
                else
                {
                    throw std::runtime_error("Invalid token in the expression: " + token);
                }
                token.clear(); // clear the current token
            }
            continue;
        }

        if (std::isdigit(c))
        {
            token += c; // append the digit to the current token
        }
        else if (isOperator(c))
        {
            if (!token.empty())
            {
                if (expectOperand)
                {
                    if (std::isdigit(token[0]))
                    {
                        outputQueue.enqueue(token); // add the number to the output queue
                        expectOperand = false;
                    }
                    else
                    {
                        throw std::runtime_error("Invalid token in the expression: " + token);
                    }
                }
                else
                {
                    throw std::runtime_error("Invalid token in the expression: " + token);
                }
                token.clear(); // clear the current token
            }

            while (!operatorStack.empty() && operatorStack.top() != '(' && getPrecedence(operatorStack.top()) >= getPrecedence(c))
            {
                outputQueue.enqueue(std::string(1, operatorStack.top())); // add operators from the stack
                operatorStack.pop();
            }

            operatorStack.push(c); // add the current operator to the stack
            expectOperand = true;
        }
        else if (c == '(') // if it is an opening parenthesis, add it to the stack
        {
            if (!token.empty())
            {
                throw std::runtime_error("Invalid token in the expression: " + token);
            }
            operatorStack.push(c);
            expectOperand = true;
        }
        else if (c == ')')
        {
            if (!token.empty())
            {
                if (expectOperand)
                {
                    if (std::isdigit(token[0]))
                    {
                        outputQueue.enqueue(token); // add the number to the output queue
                        expectOperand = false;
                    }
                    else
                    {
                        throw std::runtime_error("Invalid token in the expression: " + token);
                    }
                }
                else
                {
                    throw std::runtime_error("Invalid token in the expression: " + token);
                }
                token.clear(); // clear the current token
            }

            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                outputQueue.enqueue(std::string(1, operatorStack.top())); // add operators from the stack
                operatorStack.pop();
            }

            if (operatorStack.empty()) // if there is no corresponding opening parenthesis
            {
                throw std::runtime_error("Mismatched parentheses");
            }

            operatorStack.pop(); // remove the opening parenthesis from the stack
            expectOperand = false;
        }
        else
        {
            throw std::runtime_error("Invalid character in the expression: " + std::string(1, c));
        }
    }

    if (!token.empty())
    {
        if (expectOperand)
        {
            if (std::isdigit(token[0]))
            {
                outputQueue.enqueue(token); // add the number to the output queue
            }
            else
            {
                throw std::runtime_error("Invalid token in the expression: " + token);
            }
        }
        else
        {
            throw std::runtime_error("Invalid token in the expression: " + token);
        }
        token.clear(); // clear the current token
    }

    while (!operatorStack.empty())
    {
        if (operatorStack.top() == '(')
        {
            throw std::runtime_error("Mismatched parentheses");
        }

        outputQueue.enqueue(std::string(1, operatorStack.top())); // add the remaining operators from the stack to the output queue
        operatorStack.pop();
    }

    if (expectOperand && !outputQueue.empty() && outputQueue.size() < 2) // if the overall expression consists of only one number
    {
        throw std::runtime_error("Incomplete expression: " + expression);
    }

    while (!outputQueue.empty())
    {
        postfix << outputQueue.dequeue() << " "; // extract elements from the output queue and add them to the postfix string
    }

    return postfix.str();
}

bool Parser::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Assigns a precedence value to each operator.
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
