// fsarray.cpp  HAND-OFF
// VERSION 6
// Glenn G. Chappell
// Started: 2024-10-15
// Updated: 2024-10-23
//
// For CS 311 Fall 2024
// Source for class FSArray
// Frightfully smart array of int
// Preliminary to Assignment 5


#include "fsarray.hpp"  // For class FSArray definition
#include <algorithm>
using std::copy;


// *********************************************************************
// class FSArray - Member function definitions
// *********************************************************************


// Copy ctor
// See header for info.
FSArray::FSArray(const FSArray & other)
    :_capacity(other._capacity),
     _size(other.size()),
     _data(other._capacity == 0 ? nullptr
                                : new value_type[other._capacity])
{
    copy(other.begin(), other.end(), begin());
    // The above call to std::copy does not throw, since it copies int
    // values. But if value_type is changed, then the call may throw, in
    // which case this copy ctor may need to be rewritten.
}


// Move ctor
// See header for info.
FSArray::FSArray(FSArray && other) noexcept
    :_capacity(other._capacity),
     _size(other._size),
     _data(other._data)
{
    other._capacity = 0;
    other._size = 0;
    other._data = nullptr;
}


// Copy assignment operator
// See header for info.
FSArray & FSArray::operator=(const FSArray & other)
{
    // TODO: WRITE THIS!!!
    return *this; // DUMMY
}


// Move assignment operator
// See header for info.
FSArray & FSArray::operator=(FSArray && other) noexcept
{
    // TODO: WRITE THIS!!!
    return *this; // DUMMY
}


// resize
// See header for info.
void FSArray::resize(FSArray::size_type newsize)
{
    // TODO: WRITE THIS!!!
}


// insert
// See header for info.
FSArray::iterator FSArray::insert(FSArray::iterator pos,
                                  FSArray::value_type item)
{
    // TODO: WRITE THIS!!!
    return begin();  // DUMMY
}


// erase
// See header for info.
FSArray::iterator FSArray::erase(FSArray::iterator pos)
{
    // TODO: WRITE THIS!!!
    return begin();  // DUMMY
}


// swap
// See header for info.
void FSArray::swap(FSArray & other) noexcept
{
    // TODO: WRITE THIS!!!
}

