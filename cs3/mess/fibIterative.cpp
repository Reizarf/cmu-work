#include <iostream>
<<<<<<< HEAD
#include <clock.h>
=======
#include <time.h>
>>>>>>> b007beaccf52f448a8a9ab1e7628554614822deb

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
    clock_t start = 0,end = 0;
    //declaring start and end variables
    double processTime = 0;
    //total time to run
    double number;
    cout << "This program calculates the nth degree of the"
    "fibonacci sequence, done ITERATIVELY." << endl <<
    "Enter the degree of fibonacci sequence you'd like to see: "<<endl;
    cin >> number;
    cout << ": ";
    start = clock();//starting the clock
    fibonacciSequence(number);//doing the work
    end = clock();//ending the clock
    processTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout <<endl<< "Total process time: " << processTime<<endl;
    return 0;
}