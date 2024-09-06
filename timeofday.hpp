// timeofday.hpp
// Glenn G. Chappell
// Started: 2024-08-30
// Updated: 2024-09-04
//
// For CS 311 Fall 2024
// Header for class TimeOfDay
// Time of day: hours, minutes, seconds

#ifndef FILE_TIMEOFDAY_HPP_INCLUDED
#define FILE_TIMEOFDAY_HPP_INCLUDED

#include <ostream>
// For std::ostream
#include <cassert>
// For assert


// *********************************************************************
// class TimeOfDay - Class definition
// *********************************************************************


// Class TimeOfDay
// Time of day: hours, minutes, seconds.
class TimeOfDay {

// ***** TimeOfDay: Friend declarations *****

    friend
    std::ostream & operator<<(std::ostream & str,
                              const TimeOfDay & obj);

// ***** TimeOfDay: Internal-use constants *****
private:

    enum {
        S_IN_M = 60,  // Seconds in a minute
        M_IN_H = 60,  // Minutes in an hour
        H_IN_D = 24,  // Hours in a day
        S_IN_D = H_IN_D * M_IN_H * S_IN_M
                      // Seconds in a day
    };

// ***** TimeOfDay: Ctors *****
public:

    // Default ctor
    // Set time to midnight.
    TimeOfDay()
    {
        setTime(0, 0, 0);
    }

    // Ctor from hours, minutes, seconds
    // Set time to given # of hours, minutes, seconds past midnight.
    TimeOfDay(int hh,
              int mm,
              int ss)
    {
        assert(0 <= hh && hh < H_IN_D);
        assert(0 <= mm && mm < M_IN_H);
        assert(0 <= ss && ss < S_IN_M);

        setTime(hh, mm, ss);
    }

// ***** TimeOfDay: General public operators *****
public:

    // op++ [pre]
    // Move time one second forward.
    TimeOfDay & operator++()
    {
        assert(0 <= _secs && _secs < S_IN_D);

        ++_secs;
        if (_secs >= S_IN_D)
           _secs = 0;
        return *this;
    }

    // op++ [post]
    // Move time one second forward.
    TimeOfDay operator++([[maybe_unused]] int dummy)
    {
        assert(0 <= _secs && _secs < S_IN_D);

        auto save = *this;
        ++(*this);
        return save;
    }

    // op-- [pre]
    // Move time one second backward.
    TimeOfDay & operator--()
    {
        assert(0 <= _secs && _secs < S_IN_D);

        --_secs;
        if (_secs < 0)
            _secs = S_IN_D-1;
        return *this;
    }

    // op-- [post]
    // Move time one second backward.
    TimeOfDay operator--([[maybe_unused]] int dummy)
    {
        assert(0 <= _secs && _secs < S_IN_D);

        auto save = *this;
        --(*this);
        return save;
    }

// ***** TimeOfDay: General public functions *****
public:

    // getTime
    // Return hours, minutes, seconds in reference parameters.
    // Function defined in source file.
    void getTime(int & hh,
                 int & mm,
                 int & ss) const;

    // setTime
    // Set time to given # of hours, minutes, seconds past midnight.
    // Function defined in source file.
    void setTime(int hh,
                 int mm,
                 int ss);

// ***** TimeOfDay: Data members *****
private:

    int _secs;  // Seconds past midnight (0 .. #seconds_in_a_day-1)

};  // End class TimeOfDay


// *********************************************************************
// class TimeOfDay - Declarations of associated global operators
// *********************************************************************


// operator<< (ostream,TimeOfDay)
// Prints given TimeOfDay object as "hh:mm:ss", with hh padded on the
// left with blanks, and mm, ss padded on the left with zeroes.
// Function defined in source file.
std::ostream & operator<<(std::ostream & str,
                          const TimeOfDay & obj);


#endif  //#ifndef FILE_TIMEOFDAY_HPP_INCLUDED

