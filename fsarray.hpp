// fsarray.hpp  UNFINISHED
// VERSION 3
// Glenn G. Chappell
// Started: 2024-10-15
// Updated: 2024-10-18
//
// For CS 311 Fall 2024
// Header for class FSArray
// Frightfully smart array of int
// Preliminary to Assignment 5

// History:
// - v1:
//   - Bare-bones only, does not compile. Header & source files,
//     #ifndef, #include, empty class definition.
// - v2:
//   - Add member types value_type, size_type, iterator, const_iterator.
//   - Add dummy versions (at least) of all member functions, including
//     dummy return statements for non-void functions. Package compiles.
//   - Add data members.
//   - Add class invariants.
//   - Write (untested versions of) the following member functions:
//     default ctor, ctor from size (these two are single func), dctor,
//     op[], size, empty, begin, end, push_back, pop_back.
// - v3:
//   - Document exception-safety guarantees for most functions.
//   - Write copy ctor.

#ifndef FILE_FSARRAY_HPP_INCLUDED
#define FILE_FSARRAY_HPP_INCLUDED

#include <cstddef>
// For std::size_t
#include <algorithm>
// For std::copy


// *********************************************************************
// class FSArray - Class definition
// *********************************************************************


// class FSArray
// Frightfully Smart Array of int.
// Resizable, copyable/movable, exception-safe.
// Invariants:
//     _size >= 0.
//     _data points to an array of value_type, allocated with new [],
//      owned by *this, holding _size value_type values.
class FSArray {

// ***** FSArray: types *****
public:

    // value_type: type of data items
    using value_type = int;

    // size_type: type of sizes & indices
    using size_type = std::size_t;

    // iterator, const_iterator: random-access iterator types
    using iterator = value_type *;
    using const_iterator = const value_type *;

// ***** FSArray: ctors, op=, dctor *****
public:

    // Default ctor & ctor from size
    // Strong Guarantee
    explicit FSArray(size_type thesize=0)
        :_size(thesize),
         _data(new value_type[thesize])
    {}

    // Copy ctor
    // Strong Guarantee
    FSArray(const FSArray & other)
        :_size(other.size()),
         _data(new value_type[other.size()])
    {
        std::copy(other.begin(), other.end(), begin());
        // The above call to std::copy does not throw, since it copies
        // int values. But if value_type is changed, then the call may
        // throw, in which case this copy ctor may need to be rewritten.
    }

    // Move ctor
    // No-Throw Guarantee
    FSArray(FSArray && other) noexcept
    {
        // TODO: WRITE THIS!!!
    }

    // Copy assignment operator
    // ??? Guarantee
    FSArray & operator=(const FSArray & other)
    {
        // TODO: WRITE THIS!!!
        return *this; // DUMMY
    }

    // Move assignment operator
    // No-Throw Guarantee
    FSArray & operator=(FSArray && other) noexcept
    {
        // TODO: WRITE THIS!!!
        return *this; // DUMMY
    }

    // Dctor
    // No-Throw Guarantee
    ~FSArray()
    {
        delete [] _data;
    }

// ***** FSArray: general public operators *****
public:

    // operator[] - non-const & const
    // No-Throw Guarantee
    value_type & operator[](size_type index)
    {
        return _data[index];
    }
    const value_type & operator[](size_type index) const
    {
        return _data[index];
    }

// ***** FSArray: general public functions *****
public:

    // size
    // No-Throw Guarantee
    size_type size() const
    {
        return _size;
    }

    // empty
    // No-Throw Guarantee
    bool empty() const
    {
        return size() == 0;
    }

    // begin - non-const & const
    // No-Throw Guarantee
    iterator begin()
    {
        return _data;
    }
    const_iterator begin() const
    {
        return _data;
    }

    // end - non-const & const
    // No-Throw Guarantee
    iterator end()
    {
        return begin() + size();
    }
    const_iterator end() const
    {
        return begin() + size();
    }

    // resize
    // ??? Guarantee
    void resize(size_type newsize)
    {
        // TODO: WRITE THIS!!!
    }

    // insert
    // ??? Guarantee
    iterator insert(iterator pos,
                    value_type item)
        // Above, passing by value is appropriate, since our value type
        // is int. However, if the value type is changed, then a
        // different parameter-passing method may need to be used.
    {
        // TODO: WRITE THIS!!!
        return begin();  // DUMMY
    }

    // erase
    // ??? Guarantee
    iterator erase(iterator pos)
    {
        // TODO: WRITE THIS!!!
        return begin();  // DUMMY
    }

    // push_back
    // ??? Guarantee
    void push_back(value_type item)
        // Above, passing by value is appropriate, since our value type
        // is int. However, if the value type is changed, then a
        // different parameter-passing method may need to be used.
    {
        insert(end(), item);
    }

    // pop_back
    // ??? Guarantee
    void pop_back()
    {
        erase(end()-1);
    }

    // swap
    // No-Throw Guarantee
    void swap(FSArray & other) noexcept
    {
        // TODO: WRITE THIS!!!
    }

// ***** FSArray: data members *****
private:

    size_type    _size;  // Size of our array
    value_type * _data;  // Pointer to our array

};  // End class FSArray


#endif  //#ifndef FILE_FSARRAY_HPP_INCLUDED

