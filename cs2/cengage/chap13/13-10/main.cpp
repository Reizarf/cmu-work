//Header files
#include <iostream>
#include <iomanip>
#include "fractionType.h"

using namespace std;

int main()
{
   //Object creation
   fractionType num1(5, 6);
   fractionType num2;
   fractionType num3;
   //Setting
   cout << fixed;
   cout << showpoint;
   cout << setprecision(2);
   //Output overload check
   cout << "Num1 = " << num1 << endl;
   cout << "Num2 = " << num2 << endl;
   //Input overload check
   cout << "Enter the fraction in the form a / b: ";
   cin >> num2;
   cout << endl;

   cout << "New value of num2 = " << num2 << endl;
   //+ overload check
   num3 = num1 + num2;

   cout << "Num3 = " << num3 << endl;
   cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
   //* overload chec
   cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
   //- overload check
   num3 = num1 - num2;

   cout << "Num3 = " << num3 << endl;
   cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
   /// overload check
   cout << "(" << num1 << ") / (" << num2 << ") = " << num1 / num2 << endl;

   return 0;
}

