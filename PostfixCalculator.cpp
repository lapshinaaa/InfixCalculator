#include "Stack.h"
#include <cctype>
#include <stdexcept>

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

Calculator::Calculator()
{
}

// ФУНКЦИЯ ДЛЯ ОЦЕНКИ ЗНАЧЕНИЯ ВВЕДЕННОГО ВЫРАЖЕНИЯ
int Calculator::evaluatePostfixExpression(const std::string& expression)
{
    int number = 0; // временная переменная для сбора чисел (если число состоит из более, чем одной цифры)

    for (char c : expression)
    {
        if (isdigit(c))
        {
            number = number * 10 + (c - '0'); // Собираем число из отдельных цифр
        }
        else if (c == ' ')
        {
            if (number != 0)
            {
                stack.push(number);
                number = 0; // Сбрасываем временную переменную, где хранился операнд
            }
        }
        else if (isOperator(c))
        {
            if (stack.size() < 2)
            {
                // Недостаточно операндов для выполнения операции
                throw std::runtime_error("Invalid expression");
            }

            int operand2 = stack.pop();
            int operand1 = stack.pop();
            int result = performOperation(c, operand1, operand2);
            stack.push(result);
        }
        else
        {
            // Некорректный символ в выражении
            throw std::runtime_error("Invalid expression");
        }
    }

    if (number != 0)
    {
        stack.push(number);
    }

    if (stack.size() != 1)
    {
        // В конце выражения осталось больше одного значения в стеке
        throw std::runtime_error("Invalid expression");
    }

    return stack.top();
}

bool Calculator::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int Calculator::performOperation(char operation, int operand1, int operand2)
{
    switch (operation)
    {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0)
            {
                // Деление на ноль
                throw std::runtime_error("Invalid expression");
            }
            return operand1 / operand2;
        default:
            // Некорректная операция
            throw std::runtime_error("Invalid expression");
    }
}
