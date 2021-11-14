#https://open.kattis.com/problems/tajna

import math
import unittest
s = input()
def tajna(s):
    
    # s = input()
    n = len(s)
    c = int(math.sqrt(n))
    r = c
    while n%r != 0:
        r -= 1
    c = n // r
    a = []
    for i in range(r):
        row = ""
        for j in range(c):
            row += s[i+j*r]
        a.append(row)
    print(''.join(a))


tajna(s)
x = 'bomb'
#print(tajna(x))

class Test_tajna(unittest.TestCase):
    def test1_tajna(self):
        x = "bomb"
        ans = tajna(x)#answer
        act = "bmob"#actual/expected
        self.assertEqual(ans,act,"broken")
    def test2_tajna(self):
        x = "koalified"
        ans = tajna(x)
        act = ("klioieafd")
        self.assertEqual(ans,act,"broken")

if __name__ == "__main__":
    unittest.main(verbosity=2)
