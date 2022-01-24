#! /usr/bin/env python3

"""
unittest for fizzbuzz2 program
"""

__author__ = "Jacob Hansen"
__copyright__ = "Copyright 2021"
__license__ = "MIT"

import unittest
from fizzbuzz2 import fizzBuzz, check, compare 

class Test_fizzbuzz2(unittest.TestCase):
    def test1_fizzBuzz(self):
        ans = fizzBuzz(15)
        actual = "1 2 fizz 4 buzz fizz 7 8 fizz buzz 11 fizz 13 14 fizzbuzz "
        self.assertEqual(ans, actual, "broken")

    def test2_fizzBuzz(self):
        ans = fizzBuzz(20)
        actual = "1 2 fizz 4 buzz fizz 7 8 fizz buzz 11 fizz 13 14 fizzbuzz 16 17 fizz 19 buzz "
        self.assertEqual(ans, actual, "broken")

    def test3_fizzBuzz(self):
        ans = fizzBuzz(5)
        actual = "1 2 fizz 4 buzz "
        self.assertEqual(ans, actual, "broken")

    def test1_check(self):
        ans = check("1 2 fizz 4 buzz fizz 7 8 fizz buzz 11 fizz 13 14 fizzbuzz ", "fizzbuzz 1 2 fizz 4 buzz fizz 7 8 fizz buzz 11 fizz 13 14 ")
        actual = 0
        self.assertEqual(ans, actual, "broken")

    def test2_check(self):
        ans = check("1 2 fizz 4 buzz fizz 7 8 fizz buzz 11 fizz 13 14 fizzbuzz 16 17 fizz 19 buzz ", "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ")
        actual = 11
        self.assertEqual(ans, actual, "broken")

    def test3_check(self):
        ans = check("1 2 fizz 4 buzz ", "1 2 fizz 4 buzz ")
        actual = 5
        self.assertEqual(ans, actual, "broken")

    def test1_compare(self):
        responses = ["1 2 fizz 4 5 fizz 7 8 fizz 10 11 fizz 13 14 fizz", "1 2 3 4 buzz 6 7 8 9 buzz 11 12 13 14 buzz", "1 2 fizz 4 buzz fizz 7 8 fizz buzz 11 fizz 13 14 fizzbuzz"]
        ans = compare(15, responses) + 1
        actual = 3
        self.assertEqual(ans, actual, "broken")
    
    def test2_compare(self):
        responses = ["fizz fizz fizz fizz buzz fizz", "2 fizz 4 buzz fizz 7", "1 2 3 4 5 6"]
        ans = compare(6, responses) + 1
        actual = 1
        self.assertEqual(ans, actual, "broken")

    def test3_compare(self):
        responses = ["01 is fizz lizzy of norway", "nr 2 is really buzz lightyear"]
        ans = compare(6, responses) + 1
        actual = 2
        self.assertEqual(ans, actual, "broken")

if __name__ == "__main__":
  unittest.main(verbosity=2)