// treesort.hpp  SKELETON
// Glenn G. Chappell
// 2024-11-11
//
// For CS 311 Fall 2024
// Header for function template treesort
// There is no associated source file.

#ifndef FILE_TREESORT_HPP_INCLUDED
#define FILE_TREESORT_HPP_INCLUDED

#include <iterator>
// For std::iterator_traits

// *******************************************************
// * YOU MIGHT WANT TO GET RID OF THE FOLLOWING INCLUDES *
// *******************************************************

#include <algorithm>
// For std::stable_sort, std::move
#include <vector>
// For std::vector
#include <iterator>
// For std::distance


// treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Exception safety guarantee:
//     ???
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // Value is the type that FDIter points to
    using Value = typename std::iterator_traits<FDIter>::value_type;

    // THE FOLLOWING IS DUMMY CODE. IT WILL PASS ALL TESTS, BUT IT DOES
    // NOT MEET THE REQUIREMENTS OF THE ASSIGNMENT.
    std::vector<Value> buff(std::distance(first, last));
    std::move(first, last, buff.begin());
    std::stable_sort(buff.begin(), buff.end());
    std::move(buff.begin(), buff.end(), first);
}


#endif //#ifndef FILE_TREESORT_HPP_INCLUDED

