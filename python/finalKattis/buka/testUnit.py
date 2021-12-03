import unittest
from buka import baka

class Test_math(unittest.TestCase):
    def test1_math(self):
        a = 100
        operator = "+"
        b = 10
        answer = 110
        self.assertEqual(baka(a,operator,b),answer)
    def test2_math(self):
        a = 10000
        operator = "+"
        b = 1
        answer = 10001
        self.assertEqual(baka(a,operator,b),answer,"broken")
    def test3_math(self):
        a = 10
        operator = "*"
        b = 100
        answer = 1000
        self.assertEqual(baka(a,operator,b),answer,"broken")
        
if __name__ == "__main__":
    unittest.main(verbosity=2)
    