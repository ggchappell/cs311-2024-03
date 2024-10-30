// rpneval.hpp  UNFINISHED
// Glenn G. Chappell
// 2024-10-29
//
// For CS 311 Fall 2024
// Header for rpnEval: Reverse Polish Notation evaluation
// Example application of a Stack

#ifndef FILE_RPNEVAL_HPP_INCLUDED
#define FILE_RPNEVAL_HPP_INCLUDED

#include <string>
// For std::string
#include <stack>
// For std::stack


// rpnEval
// Do a single step in RPN expression evaluation.
// Given a stack<int> and a string, interpret the string as a command,
// and use it to operate on the stack.
//   c, C: clear stack.
//   <integer>: push value on stack.
//   +, -, *, /: binary arithmetic operator.
//     Operands taken from top 2 stack items; stack underflow throws.
//     "/" is integer division; x/0 throws.
//     Result is left in top item on stack.
//   Unknown command: throws.
// May throw std::bad_alloc on out-of-memory, std::domain_error on
// unknown command, std::out_of_range on stack underflow,
// std::overflow_error on division by zero, and the exception thrown by
// std::stoi (std::out_of_range or std::invalid_argument) on bad
// string-to-number conversion.
// Basic Guarantee
void rpnEval(std::stack<int> & s,
             const std::string & command);


#endif  //#ifndef FILE_RPNEVAL_HPP_INCLUDED

