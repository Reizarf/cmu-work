#include <iostream>
using namespace std;


double fib(double n)
{
    if(n < 2) return 1;//stopping condition
    return fib(n-1) + fib(n-2);

    //we are off by 1. 
    //you can take user input and -=1;

}

int main()
{
    double n = 49;//this took 51 seconds 


    cout << fib(n);
}