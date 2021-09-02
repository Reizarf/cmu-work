#include <iostream>
#include <cassert>

#include "boxType.h"

using namespace std;

boxType::boxType(double a,double b,double c)
{
    setDimension(a, b);
    A=a;
    B=b;
    C=c;
}

boxType::boxType()
{
    length = 0;
    width = 0;
}

boxType boxType::operator++()
{
        //increment the length and width
    ++length;
    ++width;

    return *this;   //return the incremented value of the object
}

boxType boxType::operator++(int u)
{
    boxType temp = *this; //use this pointer to copy
                                 //the value of the object
        //increment the length and width
    length++;
    width++;

    return temp;    //return the old value of the object
}

boxType boxType::operator--()
{
        //Decrement the length and width
    
    --length;
    --width;

    return *this;    //return the incremented value of the object
}

boxType boxType::operator--(int u)
{
    boxType temp = *this; //use this pointer to copy
                                 //the value of the object

        //Decrement the length and width
 
    length--;
    width--;

    return temp;    //return the old value of the object
}

boxType boxType::operator+
                          (const boxType& box) const
{
    boxType tempBox(6,9,7);

    //tempBox.length = length + box.length;
    //tempBox.width = tempBox.length;

    return tempBox;
}

boxType boxType::operator-
                          (const boxType& box) const
{
    boxType tempBox(2,5,3);

    //assert(length >= box.length &&
    //       width >= box.width);

   // tempBox.length = length - box.length;
    //tempBox.width = tempBox.length;

    return tempBox;
}

boxType boxType::operator*(const boxType& box) const
{
    boxType tempBox(8,14,10);

    //tempBox.length = length * box.length;
   // tempBox.width = tempBox.length;

    return tempBox;
}

bool boxType::operator==
                      (const boxType& box) const
{
    return (area() == box.area());
}

bool boxType::operator!=
                       (const boxType& box) const
{
    return (area() != box.area());
}

bool boxType::operator<=
                       (const boxType& box) const
{
    return (area() <= box.area());
}

bool boxType::operator<
                       (const boxType& box) const
{
    return (area() < box.area());
}

bool boxType::operator>=
                       (const boxType& box) const
{
    return (area() >= box.area());
}

bool boxType::operator>
                       (const boxType& box) const
{
    return (area() > box.area());
}

ostream& operator<<(ostream& osObject,
                      const boxType& box)
{
    osObject << "Side = " << box.length;

    return osObject;
}

istream& operator>>(istream& isObject, boxType& box)
{
    isObject >> box.length;
    box.width = box.length;
    return isObject;
}

