#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <sstream>
#include <cctype>
#include "Stack.h"
#include "Queue.h"

class Parser
{
public:
    std::string infixToPostfix(const std::string& expression);
    bool isOperator(char c) const;
    int getPrecedence(char c) const;
    void clear();

private:
    Stack<char> operatorStack;
    Queue<char> outputQueue;
};

#endif // PARSER_H
