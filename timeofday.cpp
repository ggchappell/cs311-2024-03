// timeofday.cpp  UNFINISHED
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


// *********************************************************************
// class TimeOfDay - Definitions of associated global operators
// *********************************************************************


// operator<< (ostream,TimeOfDay)
ostream & operator<<(ostream & out,
                     const TimeOfDay & t)
{
    int h, m, s;
    t.getTime(h, m, s);
    out << h << ":" << m << ":" << s;
}

