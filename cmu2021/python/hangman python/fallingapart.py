#This file is the kattis fallingapart assignment in python
#Output a single line containing two integers, (cont.)
#the combined value of Alice’s pieces, and the combined value of Bob’s pieces.

#andrea flores

alice = 0
bob = 0

number = int(input())

a = [int(x) for x in input().split()]
alice = 0
bob = 0

while a:
    alice += max(a)
    a.remove(max(a))
    if a:
        bob += max(a)
        a.remove(max(a))

print (alice, bob)

test1 = [3,3,1,2]
test2 = [4,1,2,2,1]
test3 = [3,4]

assert[a(test1)] == [4,2]
assert(a(test2)) == [3,3]
assert(a(test3)) == [4,0]