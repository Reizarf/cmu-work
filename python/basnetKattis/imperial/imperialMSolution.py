import unittest

def to_index(unit):
    if unit == "thou" or unit == "th":
        return 0
    if unit == "inch" or unit == "in":
        return 1
    if unit == "foot" or unit == "ft":
        return 2
    if unit == "yard" or unit == "yd":
        return 3
    if unit == "chain" or unit == "ch":
        return 4
    if unit == "furlong" or unit == "fur":
        return 5
    if unit == "mile" or unit == "mi":
        return 6
    if unit == "league" or unit == "lea":
        return 7

class TestCold(unittest.TestCase):
    def test_1(self):
        ans = v
        actual = 504
        self.assertEqual(v,504,"broken")
    def test_2(self):
        ans = v
        actual = 2200
        self.assertEqual(v,2200,"broken")
    def test_3(self):
        ans = v
        actual = 576
        self.assertEqual(v,576,"broken")




ip = input().split()
v = int(ip[0])
want = to_index(ip[3])
u = to_index(ip[1])
units = ["th", "in", "ft", "yd", "ch", "fur", "mi", "lea"]
def unit(u,v):
    while want != u:
        # go up,divide
        if u < want:
            if units[u] == "th":
                v /= 1000
            elif units[u] == "in":
                v /= 12
            elif units[u] == "ft":
                v /= 3
            elif units[u] == "yd":
                v /= 22
            elif units[u] == "ch":
                v /= 10
            elif units[u] == "fur":
                v /= 8
            elif units[u] == "mi":
                v /= 3
            u += 1

    # go down, multiply
    else:
        if units[u] == "lea":
            v *= 3
        elif units[u] == "in":
            v *= 1000
        elif units[u] == "ft":
            v *= 12
        elif units[u] == "yd":
            v *= 3
        elif units[u] == "ch":
            v *= 22
        elif units[u] == "fur":
            v *= 10
        elif units[u] == "mi":
            v *= 8
        u -= 1

print(v)
# to_index(unit)
# unit(u,v)





class TestCold(unittest.TestCase):
    def test_1(self):
        ans = v
        actual = 504
        self.assertEqual(v,actual,"broken")
    def test_2(self):
        ans = '10 furlong in yard'
        actual = 2200
        self.assertEqual(ans,actual,"broken")
    def test_3(self):
        ans = '1 chain in feet'
        actual = 576
        self.assertEqual(ans,actual,"broken")

if __name__ == "__main__":
    unittest.main(verbosity=2)


