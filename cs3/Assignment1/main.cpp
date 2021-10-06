#include <iostream> 
#include <iomanip>  
#include <fstream>  //file manip
#include <cstring> //include to use strcpy
#include <string.h>
#include "DataType.h"
#include "BinaryTree.cpp"

using namespace std;



int main()
{

    ifstream inFile;
    string text;//going into here
    //char ctext[text.size() + 1];//creating char array size of string
    DataType data; //declare data of type DataType
    BinaryTree btree;//creating an object of the class to be used
    BinaryTree::nodePtr currentNode;
    cout << "Hello user! Please enter the name of the file you'd like to read: " << endl;

    string input;//user input

    cin >> input;//taking file name

    inFile.open(input + ".txt");//you can enter raw filename no extension

    while(inFile >> text)//this >> extraction operator skips whitesapce by deafault
    {
        cout << text;

        //construct a DataType instance with the word in it
        
        data.word = text;
        
        int length = text.length();//creating integer so find size of array
        int length2 = currentNode->data.word.length();

        char char_array[length + 1];//creaing array
        char char_array2[length2 + 1];

        strcpy(char_array,text.c_str());//copy string data into char array
        strcpy(char_array2,currentNode->data.word.c_str());

        TreeDataCmp(char_array,char_array2);
        


        cout << endl;

    }
}

int TreeDataCmp(const char* char_array, const char* char_array2)//were comparing the struct's string with root
{
    
    BinaryTree btree;
    
    btree.SetIterator();

    
    //while btree.More)
    int strCompare = strcmp(char_array,char_array2);

    if(strCompare > 0)
    {
        // DataType::
    }
    if(strCompare == 0)
    {
        //if the words match
        //freq++;
    }
    if(strCompare < 0)
    {
        
    }
    //btree.next()  (here or in the if's????)



    //What's going on

    //Basically we got the TreeDataCmp function to work
    //it return successfully(look at strcmp.cpp)
    //now we need to be able to build and traverse
    //the tree and cleanup afterwards
    // - Finish the results area
    // - don't forget about word frequency
    //Look at Fibonacci
    return 0;
}