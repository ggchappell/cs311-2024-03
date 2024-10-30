// rpneval.cpp
// Glenn G. Chappell
// Updated: 2024-10-30
// Started: 2024-10-29
//
// For CS 311 Fall 2024
// Source for rpnEval: Reverse Polish Notation evaluation
// Example application of a Stack

#include "rpneval.hpp"
#include <string>
// For std::string
// For std::stoi
#include <stack>
// For std::stack
#include <cctype>
// For std::isdigit
#include <stdexcept>
// For std::domain_error
// For std::out_of_range
// For std::overflow_error


// isInteger
// Given a string, returns true if it represents an integer, that is, if
// it consists of one or more ASCII digits preceded by an optional sign
// ('+', '-').
// No-Throw Guarantee
bool isInteger(const std::string & str) noexcept
{
    if (str.empty())
        return false;
    char c = str.front();
    if (!std::isdigit(c) && c != '+' && c != '-')
        return false;

    for (size_t i = 1; i < str.size(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }

    // Now either we have an integer, or we have "+" or "-"
    return std::isdigit(str.back());
}


// isBinop
// Given a string, returns true if it consists of a single arithmetic
// binary-operation character ('+', '-', '*', '/').
// No-Throw Guarantee
bool isBinop(const std::string & str) noexcept
{
    if (str.size() != 1)
        return false;
    char c = str.front();
    return c == '+' || c == '-' || c == '*' || c == '/';
}


// rpnEval
// (See header for docs.)
void rpnEval(std::stack<int> & s,
             const std::string & command)
{
    if (command == "c" || command == "C")
    {
        std::stack<int>().swap(s);  // Clear stack
        return;
    }

    if (isInteger(command))
    {
        s.push(std::stoi(command));
        return;
    }

    if (!isBinop(command))
    {
        throw std::domain_error("Unknown command: \"" + command + "\"");
    }

    // We have a binary arithmetic operator: +, -, *, /

    if (s.size() < 2)
    {
        throw std::out_of_range("Stack underflow in \"" + command
                              + "\" operation");
    }

    int b = s.top();
    s.pop();
    int a = s.top();
    s.pop();

    if (command == "+")
        s.push(a + b);
    else if (command == "-")
        s.push(a - b);
    else if (command == "*")
        s.push(a * b);
    else  // command == "/"
    {
        if (b == 0)
            throw std::overflow_error("Division by zero");
        else
            s.push(a / b);
    }
}

