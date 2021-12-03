import unittest
from softpasswords import problem

class Test_password(unittest.TestCase):
    def test1_pass(self):
        S = "A$AP"
        P = "R0CKY"
        #print("func call",problem(S,P))
        problem(S,P)
        answer = 'No'
        self.assertEqual(answer,problem(S,P),"broken test case 1")
    def test2_pass(self):
        S = "passc0de"
        P = "passW04D!"
        problem(S,P)
        answer = 'No'
        self.assertEqual(answer,problem(S,P),"broken")
    def test3_pass(self):
        S = "KATTIS"
        P = "Pr0bl3ms!"
        problem(S,P)
        answer = 'No'
        self.assertEqual(answer,problem(S,P),"broken!")

    
if __name__ == "__main__":
    unittest.main(verbosity=2)
    