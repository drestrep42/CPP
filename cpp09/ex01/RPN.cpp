#include "RPN.hpp"
#include <cstdlib>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

void RPN::evaluate(const std::string& expression)
{
    std::istringstream input(expression);
    std::string token;

    int i = 0;
    while (input >> token) {
        if (token.size() == 1 && (token[0] == '+' || token[0] == '-' 
            || token[0] == '*' || token[0] == '/'))
        {
            if (_stack.size() < 2) {
                throw std::runtime_error("Invalid expression");
            }
            int rhs = _stack.top();
            _stack.pop();
            int lhs = _stack.top();
            _stack.pop();
            int result = 0;

            if (token[0] == '+')
                result = lhs + rhs;
            else if (token[0] == '-')
                result = lhs - rhs;
            else if (token[0] == '*')
                result = lhs * rhs;
            else {
                if (rhs == 0) {
                    throw std::runtime_error("Division by zero");
                }
                result = lhs / rhs;
            }
            _stack.push(result);
        }
        else
        {
            char *end = 0;
            int value = std::strtol(token.c_str(), &end, 10);

            if (value < 0 || value > 10) {
                throw std::runtime_error("Invalid number");
            }
            if (*end != '\0') {
                throw std::runtime_error("Invalid token");
            }

            _stack.push(static_cast<int>(value));
        }
        i++;
    }

    if (_stack.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }
}

int RPN::top() const
{
    return _stack.top();
}
