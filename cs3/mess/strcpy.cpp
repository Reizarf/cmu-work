#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string test = "word";
    char data[test.size() + 1];
    
    cout << test << endl;

    strcpy(data,test.c_str());

    cout << data << endl;

    return 0;
}