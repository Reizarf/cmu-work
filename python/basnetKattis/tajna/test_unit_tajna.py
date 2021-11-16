import unittest
from tajna import tajna

class Test_tajna(unittest.TestCase):
    def test1_tajna(self):
        s = "bomb"
        ans = tajna(s)#answer
        act = "bmob"#actual/expected
        self.assertEqual(ans,act,"broken")
    def test2_tajna(self):
        x = "koalified"
        ans = tajna(x)
        act = ("klioieafd")
        self.assertEqual(ans,act,"broken")
    def test3_tajna(self):
        x = "bombshell"
        ans = tajna(x)
        act = (" ")
        self.assertEqual(ans,act,"broken")
        

if __name__ == "__main__":
    unittest.main(verbosity=2)