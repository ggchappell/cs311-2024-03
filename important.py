#!/usr/bin/env python3
# important.py
# Glenn G. Chappell
# 2024-09-26
#
# For CS 311 Fall 2024
"""Print the sum from Analysis of Algorithms slides.
Illustrates the most important part of a formula."""


import math  # for .log
import sys   # for .exit


def print_results(n):
    """Given an integer n, print the terms in the sum from the Analysis
    of Algorithms slides, along with the sum itself, each on a separate
    line, rounded to the nearest integer.

    """
    # Terms in sum
    a = round(n * math.log(n, 10))
    b = 72 * n
    c = 3 * n**2
    d = 936

    # The sum itself
    total = a+b+c+d

    # For right-aligning all numbers
    field_width = len(str(total))

    # Print all values
    fmtstr = "{:>" + str(field_width) + "}"
    print(("n log_10(n) " + fmtstr).format(a))
    print(("72 n        " + fmtstr).format(b))
    print(("3 n^2       " + fmtstr).format(c))
    print(("936         " + fmtstr).format(d))
    print(("SUM         " + fmtstr).format(total))


# main
def main():
    while True:
        print()
        print("Given n, I print the values of the terms in the sum")
        print("from the Analysis of Algorithms slides, along with the")
        print("sum itself. Values are rounded to the nearest integer.")
        print()
        try:
            line = input("Type n [blank line to exit]: ")
            if line == "": break
            n = int(line)
            if n <= 0: raise Exception()
        except (KeyboardInterrupt, AssertionError):
            raise
        except:
            print()
            print("Please type a positive integer")
        else:
            print()
            print_results(n)
        print()
        print("-" * 60)
    print()

    return 0  # Success


# Main program
# If this module is executed as a program (instead of being imported):
# input n, print numbers in nice format, repeat until blank line input.
if __name__ == "__main__":
    sys.exit(main())

