// fsarray_main2.cpp
// Glenn G. Chappell
// 2024-10-20
//
// For CS 311 Fall 2024
// Simple program using class FSArray
// Avoids resizing, swap, and assignment
// Requires fsarray.hpp, fsarray.cpp

#include "fsarray.hpp"  // For class FSArray
#include <iostream>
using std::cout;
using std::cin;
#include <iterator>
using std::begin;
using std::end;
#include <algorithm>
using std::sort;
#include <cassert>
// For assert


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// Main program
// Do some things with FSArray. Avoid moving, assigning, resizing,
// swapping of FSArray values.
int main()
{
    const FSArray::size_type ASIZE = 20;  // Size of our array

    // Print intro message
    cout << "Simple program using an FSArray object\n";
    cout << "Size of FSArray: " << ASIZE << "\n\n";

    // Create an FSArray and put some data in it.
    FSArray data(ASIZE);
    assert(data.size() == ASIZE);
    assert(!data.empty());
    for (FSArray::size_type i = 0; i < data.size(); ++i)
    {
        auto val = 2*i < ASIZE ? 20*((ASIZE-1)/2-i) : 20*(ASIZE-1-i)+10;
        data[i] = FSArray::value_type(val);
    }

    // Print initial data
    cout << "Initial data:\n";
    for (auto n : data)   // Range-based for-loop!
    {
        cout << n << " ";
    }
    cout << "\n\n";

    // Sort data
    sort(begin(data), end(data));  // STL algorithm!

    // Print sorted data
    cout << "Sorted data:\n";
    for (auto n : data)   // Another range-based for-loop!
    {
        cout << n << " ";
    }
    cout << "\n\n";

    // Make a copy of sorted data
    FSArray data2 = data;

    // Print copy of sorted data
    cout << "Copy of sorted data:\n";
    for (auto n : data2)  // Yet another range-based for-loop!
    {
        cout << n << " ";
    }
    cout << "\n\n";

    // Wait for user
    cout << "Press ENTER to quit ";
    userPause();
}

