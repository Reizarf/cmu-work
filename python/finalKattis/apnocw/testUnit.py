import unittest
from main import aPrize

class Test_prize(unittest.TestCase):
    def test1_prize(self):
        noodle = 5
        xylo = 7
        ans = aPrize(noodle,xylo)
        print("ans=",ans)
        actual = 3
        # print(ans)
        #self.assertEqual(aPrize(ans),actual,"broken")


if __name__ == "__main__":
    unittest.main(verbosity=2)
