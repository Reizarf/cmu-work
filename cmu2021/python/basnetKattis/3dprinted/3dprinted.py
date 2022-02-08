__author__ = "Sullivan Frazier"
__license__ = "MIT"
__copyright__ = "Copyright 2021"
#https://open.kattis.com/problems/3dprinter

import sys
import unittest
def find_min(num_printers,printed_statues,curr_days, num_statues):
    global curr_min
    if (curr_days+1) >= curr_min:
        return
    if (num_printers+printed_statues) >= num_statues:
        curr_min = curr_days+1
        return
    find_min(num_printers+num_printers,printed_statues,curr_days+1,num_statues)
    find_min(num_printers,printed_statues+num_printers,curr_days+1,num_statues)

num_statues = int(sys.stdin.readline().rstrip())
#num_statues = 5
curr_min = num_statues


find_min(1,0,0, num_statues)
print(curr_min)

class Test_printers(unittest.TestCase):
    def test1_printer(self):
        # ans = find_min(1,0,0,num_statues=5)
        ans = curr_min
        actual = 4
        self.assertEqual(ans,actual,"broken")
    def test2_printer(self):
        ans = curr_min
        actual = 4
        self.assertEqual(ans,actual,"broken")
    def test3_printer(self):
        ans = curr_min
        actual = 4
        self.assertEqual(ans,actual,"broken")
    
    

if __name__ == "__main__":
    unittest.main(verbosity=2)
