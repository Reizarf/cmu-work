import unittest
from moscowDream import moscowDream

class Test_dream(unittest.TestCase):
    def test1_dream(self):
        A = 12
        B = 9
        C = 8
        N = 7
        ans = "YES"
        actual = moscowDream(A,B,C,N)
        self.assertEqual(ans,actual)
    def test2_dream(self):
        A = 92
        B = 26
        C = 88
        N = 2
        ans = "NO"
        actual = moscowDream(A,B,C,N)
        self.assertEqual(ans,actual)
    def test3_dream(self):
        A = 101
        B = 202
        C = 303
        N = 1
        ans = "NO"
        actual = moscowDream(A,B,C,N)
        self.assertEqual(ans,actual)

if __name__ == "__main__":
    unittest.main(verbosity=2)
        