#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;


int TreeDataCmp(const char* char_array, const char* char_array2)
{
    int strCompare = strcmp(char_array,char_array2);
    // for(int i = 0; i < char_array.length();i++)
    // {

    // }
    cout << strCompare << "<-strCompare#" <<endl;
    if(strCompare >0)
    {
        cout << "=1" <<endl;
        return 1;
    }
    if(strCompare == 0)
    {
        cout << "=0" <<endl;
        return 0;
    } 
    if(strCompare <0)
    {
        cout << "=-1" <<endl;
        return -1;
    } 
    

}

int main()
{
    string data = "a";

    string word = "b";

    int length = data.length();//creating integer so find size of array
    int length2 = word.length();


    char char_array[length + 1];//creaing array
    char char_array2[length2 + 1];


    strcpy(char_array,data.c_str());//copy string data into char array
    strcpy(char_array2,word.c_str());

    
   
    for(int i = 0; i < data.length(); i++)
    {
        cout << "Char_array[i] =  ";
        cout << char_array[i] << endl;  
        
    }
    for(int i = 0; i < word.length(); i++)
    {
        cout << "Char_array2[i] =  ";
        cout << char_array2[i] << endl;  
        
    }

    int res = TreeDataCmp(char_array,char_array2);


    if(res == 0)
    {
        cout << "we made it!" << endl;
    }
    if(res == 1)
    {
        cout << "res = 1" <<endl;
    }
    if(res == -1)
    {
        cout << "res = -1" <<endl;
    }
    //cleanup
    //char_array[] = null;
    //maybe no cleanup if we just keep rewriting
    //??

    return 0;
}