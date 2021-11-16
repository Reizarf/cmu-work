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
