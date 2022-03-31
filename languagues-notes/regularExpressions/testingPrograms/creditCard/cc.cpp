#include <regex>
#include <string>
#include <iostream>

using namespace std;

bool isVisaCardNumber(const string &candidate)
{
    regex matcher("/^(?:2131|1800|35\d{3})\d{11}$/");

    const regex pattern("^4[0-9]{12}(?:[0-9]{3})?$");
    
    return regex_match(candidate,matcher);
}

int main()
{
    const int num_of_tests = 2;//change if increasing test cases
    const string tests[num_of_tests] = {"4012888888881881","4418831001112089"};
    
    for(int i = 0; i < num_of_tests; i++)
    {
        string flag = "";
        bool result = isVisaCardNumber(tests[i]);
        if(result == true)
            flag = "True";
        if(result ==false)
            flag = "false";
        else
            flag = "false";
        
        cout << "Trial# " << i+1 << " :   " << flag << endl;

    }
    return 0;
}
