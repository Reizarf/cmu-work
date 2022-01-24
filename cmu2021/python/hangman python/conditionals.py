#This program will take the input of 5 different numbers and will output several different mathematical functions
#The numbers will be added, multiplied, averaged, and the max and min will be found - not using the built in functions.


import math

if __name__ == "__main__":

    def addNumbers(a,b,c,d,e,g):
        return a+b+c+d+e+g

    def multiplyNumbers(a,b,c,d,e,g):
        return a*b*c*d*e*g

    def averageNumbers(a,b,c,d,e,g):
        return ((a+b+c+d+e+g)/6)

    def topNumbers(a,b,c,d,e,g):
        top = a
        if b > top:
            top = b
        if c > top:
            top = c
        if d > top:
            top = d
        if e > top:
            top = e
        if g > top:
            top = g
        return top

    def minNumbers(a,b,c,d,e,g):
        bot = a
        if b < bot:
            bot = b
        if c < bot:
            bot = c
        if d < bot:
            bot = d
        if e < bot:
            bot = e
        if g < bot:
            bot = g
        return bot

print("Enter 5 numbers")

a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
g = int(input())

print("add",addNumbers(a,b,c,d,e,g))
print("multiply",multiplyNumbers(a,b,c,d,e,g))
print("average",averageNumbers(a,b,c,d,e,g))
print("maximum of input", topNumbers(a,b,c,d,e,g))
print("minimum of input",minNumbers(a,b,c,d,e,g))

assert addNumbers(2,3,4,5,6,7) == 27
assert addNumbers(3,5,7,9,11,12) == 47
assert multiplyNumbers(3,5,7,9,11,12) == 124740
assert multiplyNumbers(2,3,4,5,6,7) == 5040
assert averageNumbers(2,3,4,5,6,7) == 4.5
assert averageNumbers(3,5,7,9,11,13) == 8
assert minNumbers(2,3,4,5,6,7) == 2
assert minNumbers(3,5,7,9,11,12) == 3