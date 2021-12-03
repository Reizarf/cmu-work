import unittest
from softpasswords import problem

class Test_password(unittest.TestCase):
    def test1_pass(self):
        S = "123"
        P = "123a"
        #print("func call",problem(S,P))
        problem(S,P)
        answer = 'No'
        self.assertEqual(answer,problem(S,P),"broken test case 1")
    def test2_pass(self):
        S = "pass"
        P = "password"
        problem(S,P)
        answer = 'No'
        self.assertEqual(answer,problem(S,P),"broken")
    #def test 3
    
if __name__ == "__main__":
    unittest.main(verbosity=2)
    