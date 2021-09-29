#include <iostream>
#include <iomanip>
#include <fstream>
#include "string.h"
#include "DataType.h"
using namespace std;


// struct DataType
// {
//     string word;
//     int freq;
// };

int main()
{

    ifstream inFile;
    string text;//going into here
    //follow this order
    //struct DataType;
    //request a file name
    DataType data; //declare data of type DataType

    //open the file

    //read a word

    //while(more words)
        //focus on the output right now

    cout << "Hello user! Please enter the name of the file you'd like to read: " << endl;

    string input;//user input

    cin >> input;//taking file name

    inFile.open(input + ".txt");//you can enter raw filename no extension

    while(inFile >> text)//this >> extraction operator skips whitesapce by deafault
    {
        cout << text;
        //so now we have the word here
        //and now it needs to be set to DataType.word?
        //and then inserted into the tree
        //increment freq


        //construct a DataType instance with the word in it
        
        data.word = text;
        
        
        


        cout << endl;

    }


}