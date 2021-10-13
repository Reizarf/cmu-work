#include <iostream>
#include <time.h>

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
<<<<<<< HEAD
    double n = 49;//this took 51 seconds 
=======
    clock_t start = 0,end = 0;
    //declaring start and end variables
    double processTime = 0;
    //total time taken
    double n;
    cout << "This program calculates the nth degree of the"
    "fibonacci sequence, done RECURSIVELY." << endl <<
    "Enter the degree of fibonacci sequence you'd like to see: "<<endl;
    cin >> n;


>>>>>>> b007beaccf52f448a8a9ab1e7628554614822deb

    start = clock();
    cout << "Recursive function received: " << fib(n) << endl;
    end = clock();

    processTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "ProcessTime: " << processTime <<endl;
}