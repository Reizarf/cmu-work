#This program takes two inputs and does several mathematical calculations. 
#Two numbers are given by the user and the inputs are (added, multiplied, divided
#subtracted, divided with a remainder, multiplied exponentially, and the first number
#being square (rooted?)).


import math

def addTwoNumbers(a,b):
    return a+b
def multiplyTwoNumbers(a,b):
    return a*b

def divideTwoNumbers(a,b):
    return a/b

def subtractTwoNumbers(a,b):
    return a-b

def remainder(a,b):
    return a%b

def exponent(a,b):
    return a**b

def squareroot(a):
    return math.sqrt(a)

def largerNumber(a,b):
    if(a>b):
        return(a)
    elif(b>=a):
        return(b)


print("Enter two numbers")
a = int(input())
b = int(input())

print("This added the two numbers",addTwoNumbers(a,b))
print("This is both numbers multiplied together",multiplyTwoNumbers(a,b))
print("This is the quotient",divideTwoNumbers(a,b))
print("Total of numbers subtracted",subtractTwoNumbers(a,b))
print("Total of numbers divided with a remainder",remainder(a,b))
print("Exponent: ",exponent(a,b))
print("Square root:",squareroot(a))
print("The larger number is",largerNumber(a,b))