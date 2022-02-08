#Program information : 
#
# This program accepts inputs for 3 sides of a triangle and outputs perimeter and area.
#
# First the program asks for values, and stores them as independent variables.
# The mathematical calculation is done for perimeter and then printed.
# Then the mathematical operation using Herons formula is used, and outputted as area.
# .

import math

side1 = float(input("Please enter the first side's length "))

side2 = float(input("Please enter the second side's length "))

side3 = float(input("Please enter the length of the hypotenuse "))

perimeter = (side1 + side2 + side3)

print("This is the perimeter of the triangle", perimeter)

s = (side1 + side2 + side3)/2

a = (math.sqrt(s*(s-side1)*(s-side2)*(s-side3)))

print("this is the area of the triangle", a)
eps = 0.000000000001
if (side1 + side2 <= side3) or (side1 +side3 <= side2) or (side2 + side3 <= side1) :
    print("This is an invalid triangle")
else: 
        print("this is a valid triangle")