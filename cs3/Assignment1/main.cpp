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
    
    DataType data; //declare data of type DataType
    
    BinaryTree btree;//creating an object of the class to be used
    BinaryTree::nodePtr tempNode;
    cout << "Hello user! Please enter the name of the file you'd like to read: " << endl;

    string input;//user input

    cin >> input;//taking file name

    inFile.open(input + ".txt");//you can enter raw filename no extension
    tempNode = new BinaryTree::node;//creating temp node
    DataType placeHolder;
    

    while(inFile >> text)//this >> extraction operator skips whitesapce by default
    {
        //cout << text;
        
        tempNode->data.word = text;//passing string into node's data
        data.freq = 1;
        data.word = text;
        
        if(btree.Locate(data,placeHolder) == true)
        {//if the data in already in the tree
            
            btree.Delete(data,placeHolder);
            
            placeHolder.freq++;
            //cout << "placehold.freq= " << placeHolder.freq;
            btree.Insert(placeHolder);
        }//and it is found, then increase freq
        else
        {//if it is NOT found
            btree.Insert(data);
        }//insert it into the tree
        
       // cout << endl;
    }
    inFile.close();//closing the file

    btree.SetIterator();//setting root far left

    while(btree.More())//while there are words in the tree
    {
        DataType tempOutput;
        tempOutput = btree.Next();

        cout << "Word: " << tempOutput.word <<"  "<< "Freq: " << tempOutput.freq << endl;
        btree.Next();//move to the next word and print again
    }
}
int TreeDataCmp(const DataType& data, const DataType& root)//were comparing the struct's string with root
{
    
    BinaryTree btree;
    
    btree.SetIterator();

	int length1 = data.word.length();

	int length2 = root.word.length();

	char char_array[length1+1];
	char char_array2[length2+1];

	strcpy(char_array,data.word.c_str());
	strcpy(char_array2,root.word.c_str());

    //while btree.More)
    int strCompare = strcmp(char_array,char_array2);

    if(strCompare > 0)
    {
        // DataType::
        return 1;
    }
    if(strCompare == 0)//the word is in the tree
    {
        return 0;
    }
    if(strCompare < 0)
    {
        return -1;
    }
    return 0;
}