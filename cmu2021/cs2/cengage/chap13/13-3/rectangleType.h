#ifndef H_rectangleType

#define H_rectangleType

#include <iostream>

using namespace std;

class rectangleType

{

public:

//Overload the stream insertion and extraction operators

friend ostream& operator<<(ostream&, const rectangleType& rectangle);

friend istream& operator>>(istream&, rectangleType& rectangle);

//Overload the arithmetic operators

rectangleType operator+(const rectangleType&);

rectangleType operator-(const rectangleType&);

rectangleType operator*(const rectangleType&);

//Overload the increment and decrement operators

rectangleType operator++();   

//pre-increment

rectangleType operator++(int);   

//post-increment

rectangleType operator--();   

//pre-decrement

rectangleType operator--( int);   

//post-decrement

//Overload the relational operators

bool operator==(

const rectangleType&);

bool operator!=(

const rectangleType&);

bool operator<=(

const rectangleType&);

bool operator<(

const rectangleType&);

bool operator>=(

const rectangleType&);

bool operator>(

const rectangleType&);   

void setDimension(double l, double w);

double getLength() const;

double getWidth() const;

double area() const;

double perimeter() const;

rectangleType();

rectangleType(double l, double w);

protected:

double length;

double width;

};

#endif
