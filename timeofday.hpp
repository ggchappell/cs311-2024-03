// timeofday.hpp  UNFINISHED
// Glenn G. Chappell
// 2024-08-30
//
// For CS 311 Fall 2024
// Header for class TimeOfDay
// Time of day: hours, minutes, seconds

#ifndef FILE_TIMEOFDAY_HPP_INCLUDED
#define FILE_TIMEOFDAY_HPP_INCLUDED

#include <ostream>
// For std::ostream


// *********************************************************************
// class TimeOfDay - Class definition
// *********************************************************************


// Class TimeOfDay
// Time of day: hours, minutes, seconds.
class TimeOfDay {
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
        setTime(hh, mm, ss);
    }

// ***** TimeOfDay: General public operators *****
public:

    // op++ [pre]
    // Move time one second forward.
    TimeOfDay & operator++()
    {
        // TODO: WRITE THIS!!!
    }

    // op++ [post]
    // Move time one second forward.
    TimeOfDay operator++(int dummy)
    {
        // TODO: WRITE THIS!!!
    }

    // op-- [pre]
    // Move time one second backward.
    TimeOfDay & operator--()
    {
        // TODO: WRITE THIS!!!
    }

    // op-- [post]
    // Move time one second backward.
    TimeOfDay operator--(int dummy)
    {
        // TODO: WRITE THIS!!!
    }

// ***** TimeOfDay: General public functions *****
public:

    // getTime
    // Return hours, minutes, seconds in reference parameters.
    void getTime(int & hh,
                 int & mm,
                 int & ss) const
    {
        ss = _secs % 60;
        mm = (_secs / 60) % 60;
        hh = (_secs / 60 / 60) % 24;
    }

    // setTime
    // Set time to given # of hours, minutes, seconds past midnight.
    void setTime(int hh,
                 int mm,
                 int ss)
    {
        _secs = hh*60*60 + mm*60 + ss;
    }

// ***** TimeOfDay: Data members *****
private:

    int _secs;  // Seconds past midnight (range 0 .. 24*60*60-1)

};  // End class TimeOfDay


// *********************************************************************
// class TimeOfDay - Declarations of associated global operators
// *********************************************************************


std::ostream & operator<<(std::ostream & out,
                          const TimeOfDay & t);


#endif  //#ifndef FILE_TIMEOFDAY_HPP_INCLUDED

