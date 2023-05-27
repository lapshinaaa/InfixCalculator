#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Stack.h"
#include <string>
#include <stdexcept> // для обработки исключений

class Calculator
{
public:
    Calculator();
    int evaluatePostfixExpression(const std::string& expression);

private:
    Stack stack;

    bool isOperator(char c);
    int performOperation(char operation, int operand1, int operand2);
};

#endif
