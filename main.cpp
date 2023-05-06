#include <iostream>
#include "PostfixCalculator.h"

int main()
{
    PostfixCalculator calculator;

    std::string expression = "4 5 7 * 2 + -";
    int result;

    try {
        result = calculator.calculate(expression);
        std::cout << "Result: " << result <<  std::endl;
    }
    catch ( std::runtime_error& e)
    {
        std::cout << "Error: " << e.what() <<  std::endl;
    }

    return 0;
}
