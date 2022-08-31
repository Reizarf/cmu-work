#include <regex.h>
#include <stdio.h>
#include <string>
using namespace std;


//resources
//https://regextutorial.org/
//https://www.geeksforgeeks.org/write-regular-expressions/
//https://medium.com/factory-mind/regex-tutorial-a-simple-cheatsheet-by-examples-649dc1c3f285



// Driver Code
int main()
{
    
    // Variable to create regex
    regex_t regex;
    
    // regex = [_a-zA-Z][_a-zA-Z0-9];

    // letter -> a|b|...z|A|B|...|Z|_
    // digit -> 0|1|...|9
    // identifier -> letter(letter|digit)*

    // Variable to store the return
    // value after creation of regex

    int value;
    string test_value = "testing string";//needs to be char array
    char test_char_string[16] = "testing string!";

    // Function call to create regex
    value = regcomp(&regex,"[:word:]",0);
    
    value = regcomp(&regex,test_char_string,0);//giving char array
    //basically determines posix compatiblity
    //PORTABLE OPERATING SYSTEM INTERFACE - is a family of standards
    //specified by IEEE for maintaining compatibility between operating systems
    

    //basically OS readable characters, like ascii but bigger?

    // If compilation is successful
    if (value == 0) {
        printf("RegEx compiled successfully.");
    }
  
    // Else for Compilation error
    else {
        printf("Compilation error.");
    }
    return 0;
}