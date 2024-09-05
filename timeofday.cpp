// timeofday.cpp
// Glenn G. Chappell
// 2024-08-30
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
    assert(0 <= _secs && _secs < s_in_d);

    ss = _secs % s_in_m;
    mm = (_secs / s_in_m) % m_in_h;
    hh = _secs / (m_in_h*s_in_m);
}

// TimeOfDay::setTime
void TimeOfDay::setTime(int hh,
                        int mm,
                        int ss)
{
    assert(0 <= hh && hh < h_in_d);
    assert(0 <= mm && mm < m_in_h);
    assert(0 <= ss && ss < s_in_m);

    _secs = hh*(m_in_h*s_in_m) + mm*m_in_h + ss;
}


// *********************************************************************
// class TimeOfDay - Definitions of associated global operators
// *********************************************************************


// operator<< (ostream,TimeOfDay)
ostream & operator<<(ostream & str,
                     const TimeOfDay & obj)
{
    assert(0 <= obj._secs && obj._secs < TimeOfDay::s_in_d);

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

