#include <iostream>
using namespace std;
//a = x
//b = y
//c = z

void fibonacciSequence(double number)
{
    double a = 0, b = 1, c = 0;

    for(int i = 0;i<number;i++)
    {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
}

int main()
{
    double number;
    cout << "This program calculates the nth degree of the"
    "fibonacci sequence, done ITERATIVELY." << endl <<
    "Enter the degree of fibonacci sequence you'd like to see: "<<endl;
    cin >> number;
    cout << ": ";
    fibonacciSequence(number);

    return 0;
}