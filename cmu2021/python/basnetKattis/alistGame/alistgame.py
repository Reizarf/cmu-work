__author__ = "Sullivan Frazier"
__license__ = "MIT"
__copyright__ = "Copyright 2021"
#https://open.kattis.com/problems/listgame
import unittest

def factors(n):
    factors = 0
    factor = 2
    while factor**2 <= n:
        if n%factor == 0:
            n/=factor
            factors+=1
        else:
            factor+=1
    return factors+1

n = int(input())
print(factors(n))

class Test_alistgame(unittest.TestCase):
    def test_1(self):
        ans = factors(65536)
        actual = 16
        self.assertEqual(ans,actual,"broken")
    def test_2(self):
        ans = factors(20006)
        actual = 3
        self.assertEqual(ans,actual,"broken")
    def test_3(self):
        ans = factors(65206)
        actual = 2
        self.assertEqual(ans,actual,"broken")

if __name__ == "__main__":
    unittest.main(verbosity=2)