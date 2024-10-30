// rpneval.cpp  UNFINISHED
// Glenn G. Chappell
// 2024-10-29
//
// For CS 311 Fall 2024
// Source for rpnEval: Reverse Polish Notation evaluation
// Example application of a Stack

#include "rpneval.hpp"
#include <string>
// For std::string
#include <stack>
// For std::stack
#include <cctype>
// For std::isdigit


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
    // TODO: WRITE THIS!!!
}

