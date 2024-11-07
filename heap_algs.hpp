// heap_algs.hpp  UNFINISHED
// Glenn G. Chappell
// 2024-11-07
//
// For CS 311 Fall 2024
// Header for Heap Algorithms
// There is no associated source file.

#ifndef FILE_HEAP_ALGS_HPP_INCLUDED
#define FILE_HEAP_ALGS_HPP_INCLUDED

#include <cstddef>
// For std::size_t


// heapTest
// Determines whether given random-access range is a Heap.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <.
// Pre:
//     [first, last) is a valid range.
// Exception neutral. Throws what & when a value-type operation throws.
// Strong guarantee.
// If operator< does not throw, then No-Throw Guarantee.
template<typename RAIter>
bool heapTest(RAIter first, RAIter last)
{
    std::size_t size = last-first;

    // Compare each non-root item with its parent
    for (std::size_t index = 1; index < size; ++index)
    {
        if (first[(index-1)/2] < first[index])
            return false;
    }
    return true;
}


// heapInsert
// Heap insert operation on a random-access range.
// Inserts *(last-1) into Heap [first, last-1).
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid nonempty range.
//     [first, last-1) forms a Heap.
// Exception neutral. Throws what & when a value-type operation throws.
// Basic guarantee.
// If operator< and swap do not throw, then No-Throw Guarantee.
template<typename RAIter>
void heapInsert(RAIter first, RAIter last)
{
    // TODO: WRITE THIS!!!
}


// heapDelete
// Heap delete operation on a random-access range.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid nonempty range.
//     [first, last) forms a Heap.
// Exception neutral. Throws what & when a value-type operation throws.
// Basic guarantee.
// If operator< and swap do not throw, then No-Throw Guarantee.
template<typename RAIter>
void heapDelete(RAIter first, RAIter last)
{
    // TODO: WRITE THIS!!!
}


// heapMake
// Turns the given random-access range into a Heap using a linear number
// of compare & swap operations.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid range.
// Exception neutral. Throws what & when a value-type operation throws.
// Basic guarantee.
// If operator< and swap do not throw, then No-Throw Guarantee.
template<typename RAIter>
void heapMake(RAIter first, RAIter last)
{
    // TODO: WRITE THIS!!!
}


// heapToSorted
// Given a Heap, sorts it by "<", ascending. Not stable.
// Sorts the given Heap.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid range.
//     [first, last) is a Heap.
// Exception neutral. Throws what & when a value-type operation throws.
// Basic guarantee.
// If operator< and swap do not throw, then No-Throw Guarantee.
template<typename RAIter>
void heapToSorted(RAIter first, RAIter last)
{
    // TODO: WRITE THIS!!!
}


#endif //#ifndef FILE_HEAP_ALGS_HPP_INCLUDED

