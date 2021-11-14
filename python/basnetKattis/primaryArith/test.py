import unittest
from primaryArithmetic import work(x)



class TestCold(unittest.TestCase):
    def test_1(self):
        self.assertEqual(work(x),'No carry operation')