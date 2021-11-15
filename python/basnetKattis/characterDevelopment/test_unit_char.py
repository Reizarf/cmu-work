import unittest
from characterDevelopment import characters


characters(6)


class Test_characterDevelopment(unittest.TestCase):
    def test_1(self):
        ans = characters(14)
        actual = 16369
        self.assertEqual(ans,actual,"broken")
    def test_2(self):
        ans = characters(12)
        actual = 4083
        self.assertEqual(ans,actual,"broken")
    def test_3(self):
        ans = characters(15)
        actual = 32752
        self.assertEqual(ans,actual,"broken")

if __name__ == "__main__":
    unittest.main(verbosity=2)
