#include "InfixCalculator.h"

int InfixCalculator::calculate(const std::string& expression) // passing the parameter by reference (not its copy)
{
    std::string postfix = parser.infixToPostfix(expression); // converting to postfix form (RVP)
    result = postfixCalculator.calculate(postfix);
  //  parser.clear();
    return result; // returning the result of calculations
}


