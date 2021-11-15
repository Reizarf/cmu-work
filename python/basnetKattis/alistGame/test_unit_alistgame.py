from alistgame import factors
import unittest


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
