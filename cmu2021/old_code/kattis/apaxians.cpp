#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    string Uinput;
    

    cout << "Enter an Apaxxian name: "<< endl;

    cin >> Uinput;

    cout << Uinput;

    char arr[Uinput.length()];


    for(int i = 0; i < Uinput.length(); i++)
    {
        arr[i] = Uinput[i];
        cout  << endl;
        cout << arr[i];
    }
    int j = 0;
    if(arr[j] != Uinput[j-1])
    {
        Uinput += arr[j];
    }
    
}