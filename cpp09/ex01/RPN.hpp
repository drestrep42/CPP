#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN {
private:
    std::stack<int> _stack;

public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    void evaluate(const std::string& expression);
    void push(int value);
    int pop();
    int top();
};

#endif
