#ifndef PARSER_H
#define PARSER_H

#include "Stack.h"
#include "Queue.h"
#include <string>
#include <sstream>

class Parser {
public:
    std::stringstream postfix;
    std::string currentNumber; // for multiple-digit numbers
    Queue<std::string> outputQueue;
    Stack<char> operatorStack;

    std::string infixToPostfix(const std::string& expression);
   // void clear();

private:
    bool isOperator(char c) const;
    int getPrecedence(char c) const;
};

#endif // PARSER_H
