#include <iostream>
#include <clock.h>

using namespace std;

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
    cout << "Enter the number you'd like to see of the Fibonacci series: " <<endl;
    cin >> number;
    cout << ": ";
    fibonacciSequence(number);

    return 0;
}