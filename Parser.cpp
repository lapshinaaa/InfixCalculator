#include "Parser.h"

//This parser is designed to convert an infix mathematical expression into postfix notation using
// the Shunting Yard algorithm (a.k.a. Алгоритм Сортировочной Станции)
std::string Parser::infixToPostfix(const std::string& expression)
{
    // traversing the expression
    for (char c : expression)
    {
        if (std::isspace(c)) // if it's a whitespace character, skip it
        {
            continue;
        }
        else if (std::isdigit(c))
        {
            currentNumber += c; //appending a digit to the current number
        }
        else if (isOperator(c))
        {
            if (!currentNumber.empty()) // we have encountered the end of a number, so the number is added to the output queue
            {
                outputQueue.enqueue(currentNumber);
                currentNumber.clear(); // clearing the variable
            }

            while (!operatorStack.empty() && operatorStack.top() != '(' && getPrecedence(operatorStack.top()) >= getPrecedence(c))
            {
                outputQueue.enqueue(std::string(1, operatorStack.top())); // adding operators from the stack
                operatorStack.pop();
            }

            operatorStack.push(c); // pushing the current operator
        }
        else if (c == '(') // pushing onto the stack if it's an opening parenthesis
        {
            operatorStack.push(c);
        }
        else if (c == ')')
        {
            if (!currentNumber.empty())
            {
                outputQueue.enqueue(currentNumber); // adding the number to the queue
                currentNumber.clear();
            }

            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                outputQueue.enqueue(std::string(1, operatorStack.top())); // adding operators from the stack
                operatorStack.pop();
            }

            if (operatorStack.empty()) // if there's no matching parenthesis (an opening bracket)
            {
                throw std::runtime_error("Mismatched parentheses");
            }

            operatorStack.pop(); // popping the opening parenthesis from the stack
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

        // the remaining operators in the operator stack are added to the output queue
        outputQueue.enqueue(std::string(1, operatorStack.top()));
        operatorStack.pop();
    }

    while (!outputQueue.empty())
    {
        //  deque elements from the output queue and append them to the postfix string stream
        postfix << outputQueue.dequeue() << " ";
    }

    return postfix.str();
}


bool Parser::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// assigns a precedence value to each operator.
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

//void Parser::clear()
//{
//    outputQueue.clear();
//    operatorStack.clear();
//}
//
