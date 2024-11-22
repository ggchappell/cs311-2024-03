// reverser_test.cpp  SKELETON
// Glenn G. Chappell
// 2024-11-21
//
// For CS 311 Fall 2024
// Test program for class Reverser
// For Assignment 8, Exercise B
// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, reverser.hpp

// Includes for code to be tested
#include "reverser.hpp"      // For class Reverser
#include "reverser.hpp"      // Double-inclusion check, for testing only

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
                             // doctest writes main for us
#include "doctest.h"         // For doctest framework

#include <deque>
using std::deque;
#include <iterator>
using std::begin;
using std::end;


// *********************************************************************
// Test Cases
// *********************************************************************


TEST_CASE("Reverser: ranges of size 2")
{
    Reverser rr;
    deque<double> dd { 1.2, 5.2 };
    deque<double> dd_rev { 5.2, 1.2 };
    rr(begin(dd), end(dd));
    INFO("Reversing deque of size 2");
    REQUIRE(dd == dd_rev);
}

