#include <iostream>
#include <iomanip>
#include <fstream>
#include "string.h"
#include "DataType.h"
#include "BinaryTree.cpp"

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
    
    DataType data; //declare data of type DataType

    BinaryTree btree;//creating an object of the class to be used

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
        //okay so now we have the word

        //next is to check if it exists - if not then insert
        btree.Insert(text);//it's not liking it because text is a string??
        //what does it need to be?


        //maybe we can change the string into the datatype needed
        
        //we need to check to see if the word is or is not in the tree already

        btree.SetIterator();//set current data to the root and then???



        cout << endl;

    }


}