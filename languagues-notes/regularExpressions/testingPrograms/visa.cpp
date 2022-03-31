#include <regex>
#include <iostream>

using namespace std;

//regex = ^4[0-9]{12}(?:[0-9]{3})?$
// ^ is the start
// 4 means the starting number of the string should be a 4
// 0-9 {12} means the next 12 digits should be between 0 and 9
// ? represents the 0 or 1 time
// $ represents the ending of the string

bool isVisaCard(string str)
{
    const regex pattern("^4[0-9]{12}(?:[0-9]{3})?$");

    if(regex_match(str,pattern))
        return true;
    else
        return false;
}

int main()
{
    //test case 

    string str1 = "4155279860457";
    cout << isVisaCard(str1) << endl;

    string str2 = "4155279860457201";
    cout << isVisaCard(str2) << endl;

    string str3 = "8080";
    cout << isVisaCard(str3) << endl;

    string str4 = "6166777788889999";
    cout << isVisaCard(str4) << endl;

    string str5 = "4144090088887777";
    cout << isVisaCard(str5) << endl;
}