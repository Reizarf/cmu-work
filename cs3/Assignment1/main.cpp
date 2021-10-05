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
        
        //btree.SetIterator();
        //btree.Locate(ctext,currentNode);
        
        // if(btree.Locate(data,data.word) == false)
        // {

        // }

        //locate first and then insert
        //if locate is true then increment freq and then delete the instance for memeory leaks

        //it's not liking it because text is a string??
        //what does it need to be?
        

        


        cout << endl;

    }


}

int TreeDataCmp(const char* data, const char* root)//were comparing the struct's string with root
{
    // take read word from file and compare it against current
    // being used by findnode(returns pointer to current node)
    // return which is bigger (1/0/-1)
    //https://cplusplus.com/reference/string/string/compare/

    //BinaryTree::SetIterator();//set root to current
    //then were going to compare root and our data
    BinaryTree btree;
    // DataType data;
    btree.SetIterator();


    //while btree.More)
    int strCompare = strcmp(data,root);

    if(strCompare == 1)
    {
        // DataType::
    }
    if(strCompare == 0)
    {
        
    }
    if(strCompare == -1)
    {
        
    }
    //btree.next()  (here or in the if's????)



    //What's going on

    //We need to finish up what happens in the if statements
    //figure out how to increase word specific frequency
    //complete the while loop while allowing to move to next word
    //put returns in the if statements
    return 0;
}