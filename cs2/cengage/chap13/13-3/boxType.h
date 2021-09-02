#ifndef H_boxType
#define H_boxType

#include <iostream>
#include "rectangleType.h"
using namespace std;

class boxType : public rectangleType
{
    //Overload the stream insertion and extraction operators
    friend ostream& operator<<(ostream&, const boxType &);
    friend istream& operator>>(istream&, boxType &);

public:

    //Overload the arithmetic operators
    boxType operator + (const boxType &) const;
    boxType operator - (const boxType &) const;
    boxType operator * (const boxType&) const;

    //Overload the increment and decrement operators
    boxType operator ++ ();          //pre-increment
    boxType operator ++ (int);       //post-increment
    boxType operator -- ();          //pre-decrement
    boxType operator -- (int);       //post-decrement

    //Overload the relational operators
    bool operator == (const boxType&) const;
    bool operator != (const boxType&) const;
    bool operator <= (const boxType&) const;
    bool operator < (const boxType&) const;
    bool operator >= (const boxType&) const;
    bool operator > (const boxType&) const;

    //constructors
    boxType();
    boxType(double a,double b,double c);
    double A,B,C;
};

#endif

