// timeofday.cpp
// Glenn G. Chappell
// Started: 2024-08-30
// Updated: 2024-09-04
//
// For CS 311 Fall 2024
// Source for class TimeOfDay
// Time of day: hours, minutes, seconds

#include "timeofday.hpp"
// For class TimeOfDay
#include <ostream>
using std::ostream;
#include <cassert>
// For assert


// *********************************************************************
// class TimeOfDay - Definitions of member functions
// *********************************************************************


// TimeOfDay::getTime
void TimeOfDay::getTime(int & hh,
                        int & mm,
                        int & ss) const
{
    assert(0 <= _secs && _secs < S_IN_D);

    ss = _secs % S_IN_M;
    mm = (_secs / S_IN_M) % M_IN_H;
    hh = _secs / (M_IN_H*S_IN_M);
}

// TimeOfDay::setTime
void TimeOfDay::setTime(int hh,
                        int mm,
                        int ss)
{
    assert(0 <= hh && hh < H_IN_D);
    assert(0 <= mm && mm < M_IN_H);
    assert(0 <= ss && ss < S_IN_M);

    _secs = hh*(M_IN_H*S_IN_M) + mm*M_IN_H + ss;
}


// *********************************************************************
// class TimeOfDay - Definitions of associated global operators
// *********************************************************************


// operator<< (ostream,TimeOfDay)
ostream & operator<<(ostream & str,
                     const TimeOfDay & obj)
{
    assert(0 <= obj._secs && obj._secs < TimeOfDay::S_IN_D);

    int hh, mm, ss;
    obj.getTime(hh, mm, ss);

    if (hh < 10)  // Left-pad with blank
        str << " ";

    str << hh << ":";

    if (mm < 10)  // Left-pad with zero
        str << "0";

    str << mm << ":";

    if (ss < 10)  // Left-pad with zero
        str << "0";
    str << ss;

    return str;
}

