#ifndef PARSER_H
#define PARSER_H

#include "Stack.h"
#include "Queue.h"
#include <string>
#include <sstream>

class Parser {
public:
    std::string infixToPostfix(const std::string& expression);

private:
    bool isOperator(char c) const;
    int getPrecedence(char c) const;
};

#endif // PARSER_H
