import unittest
from threedprinted import days

class Test_printers(unittest.TestCase):
    def test1_printer(self):
        # ans = find_min(1,0,0,num_statues=5)
        ans = days(num_of_statues=5)
        actual = 4
        self.assertEqual(ans,actual,"broken")
    def test2_printer(self):
        ans = days(num_of_statues=12)
        actual = 5
        self.assertEqual(ans,actual,"broken")
    def test3_printer(self):
        ans = days(num_of_statues=21)
        actual = 6
        self.assertEqual(ans,actual,"broken")
    
if __name__ == "__main__":
    unittest.main(verbosity=2)
