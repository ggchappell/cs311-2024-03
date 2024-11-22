// reverser.hpp
// Glenn G. Chappell
// 2024-11-21
//
// For CS 311 Fall 2024
// Header for class Reverser
// There is no associated source file.
// For Assignment 8, Exercise B

#ifndef FILE_REVERSER_HPP_INCLUDED
#define FILE_REVERSER_HPP_INCLUDED

#include <algorithm>
// For std::reverse


// class Reverser
// Class for function objects that reverse the order of the items in a
// range. Object of type Reverser is a function object that takes two
// bidirectional iterators.
// Usage:
//     Reverser r;
//     r(first, last);  // first, last are iterators defining a range
// Class invariants: None.
class Reverser {

public:
    // operator()
    // Given a range specified by two bidirectional iterators. Reverses
    // the order of the values in the range.
    // Pre:
    //     [first, last) must be a valid range.
    // Basic guarantee
    // Exception neutral. Throws what & when a value type operation
    // throws.
    template<typename BDIter>
    void operator()(BDIter first,
                    BDIter last) const
    {
        std::reverse(first, last);
    }

    // We use automatically generated default ctor & Big 5.
    Reverser() = default;
    ~Reverser() = default;
    Reverser(const Reverser &) = default;
    Reverser(Reverser &&) = default;
    Reverser & operator=(const Reverser &) = default;
    Reverser & operator=(Reverser &&) = default;

};  // End class Reverser


#endif //#ifndef FILE_REVERSER_HPP_INCLUDED

