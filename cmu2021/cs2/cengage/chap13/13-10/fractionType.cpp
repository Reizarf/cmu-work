#include <iostream>
#include "fractionType.h"
#include<string>
#include <fstream>
#include <cstring>
using namespace std;

// overload operator <<
ostream& operator << (ostream& os, const fractionType& fraction)
{
   // write overloaded code here
   os << fraction.numerator << "/" << fraction.denominator;
   return os;
}

// overload operator >>
istream& operator>> (istream& is, fractionType& fraction)
{
   // write overloaded code here
   int fracdenom;
   int fracnum;

   std::string inputline;
   if (is>>inputline) {
       int num_read = sscanf(inputline.c_str(), "%d/%d", &fracnum, &fracdenom);
       if (num_read > 0) {
           if (num_read < 2) {
               fracdenom = 1;
           }
           fraction = fractionType(fracnum, fracdenom);
       }
       else {
           is.setstate(std::ios::failbit);
       }
   }
   return is;
}

// overload operator ==
bool fractionType::operator==(fractionType rightFr) const
{
   // write overloaded code here
   if (this->numerator*rightFr.denominator == this->denominator*rightFr.numerator)
       return true;
   else
       return false;
}

// overload operator !=
bool fractionType::operator!=(fractionType rightFr) const
{
   // write overloaded code here
   if (this->numerator*rightFr.denominator != this->denominator*rightFr.numerator)
       return true;
   else
       return false;
}

// overload operator <=
bool fractionType::operator<=(fractionType rightFr) const
{
   // write overloaded code here
   if (this->numerator*rightFr.denominator <= this->denominator*rightFr.numerator)
       return true;
   else
       return false;
}

// overload operator <
bool fractionType::operator<(fractionType rightFr) const
{
   // write overloaded code here
   if (this->numerator*rightFr.denominator < this->denominator*rightFr.numerator)
       return true;
   else
       return false;
}

// overload operator >=
bool fractionType::operator>=(fractionType rightFr) const
{
   // write overloaded code here
   if (this->numerator*rightFr.denominator >= this->denominator*rightFr.numerator)
       return true;
   else
       return false;
}

// overload operator >
bool fractionType::operator>(fractionType rightFr) const
{
   // write overloaded code here
   if (this->numerator*rightFr.denominator > this->denominator*rightFr.numerator)
       return true;
   else
       return false;
}

//constructor
fractionType::fractionType(int num, int deno)
{
   numerator = num;

   if (deno == 0)
   {
       cout << "denominator cannot be zero" << endl;
       denominator = 1;
   }
   else
       denominator = deno;
}

void fractionType::setFraction(int num, int deno)
{
   numerator = num;

   if (deno == 0)
   {
       cout << "denominator cannot be zero" << endl;
       denominator = 1;
   }
   else
       denominator = deno;
}

// overload the operator +
fractionType fractionType::operator+(fractionType rightFr)
{
   // write overloaded code here
   fractionType tmp((this->numerator*rightFr.denominator + this->denominator*rightFr.numerator), (this->denominator*rightFr.denominator));
   return tmp;
}

// overload the operator *
fractionType fractionType::operator*(fractionType rightFr)
{
   // write overloaded code here
   fractionType tmp((this->numerator*rightFr.numerator), (this->denominator*rightFr.denominator));
   return tmp;
}

// overload operator -
fractionType fractionType::operator-(fractionType rightFr)
{
   // write overloaded code here
   fractionType tmp((this->numerator*rightFr.denominator - this->denominator*rightFr.numerator), (this->denominator*rightFr.denominator));
   return tmp;
}

// overload operator /
fractionType fractionType::operator/(fractionType rightFr)
{
   // write overloaded code here
   fractionType tmp(this->numerator*rightFr.denominator, this->denominator*rightFr.numerator);
   return tmp;;
}
