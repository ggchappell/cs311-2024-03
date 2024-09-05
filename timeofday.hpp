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
        s_in_m = 60,  // Seconds in a minute
        m_in_h = 60,  // Minutes in an hour
        h_in_d = 24,  // Hours in a day
        s_in_d = h_in_d * m_in_h * s_in_m
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
        assert(0 <= hh && hh < h_in_d);
        assert(0 <= mm && mm < m_in_h);
        assert(0 <= ss && ss < s_in_m);

        setTime(hh, mm, ss);
    }

// ***** TimeOfDay: General public operators *****
public:

    // op++ [pre]
    // Move time one second forward.
    TimeOfDay & operator++()
    {
        assert(0 <= _secs && _secs < s_in_d);

        ++_secs;
        if (_secs >= s_in_d)
           _secs = 0;
        return *this;
    }

    // op++ [post]
    // Move time one second forward.
    TimeOfDay operator++([[maybe_unused]] int dummy)
    {
        assert(0 <= _secs && _secs < s_in_d);

        auto save = *this;
        ++(*this);
        return save;
    }

    // op-- [pre]
    // Move time one second backward.
    TimeOfDay & operator--()
    {
        assert(0 <= _secs && _secs < s_in_d);

        --_secs;
        if (_secs < 0)
            _secs = s_in_d-1;
        return *this;
    }

    // op-- [post]
    // Move time one second backward.
    TimeOfDay operator--([[maybe_unused]] int dummy)
    {
        assert(0 <= _secs && _secs < s_in_d);

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

