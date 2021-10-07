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
    
    while(inFile >> text)//this >> extraction operator skips whitesapce by default
    {
        
        cout << text;
        currentNode = new BinaryTree::node;
        currentNode->data = data;

        //cout <<"data.word: " <<data.word << endl;

        if(btree.Locate(data,currentNode->data) == true)//taking two data types 
        {//if the data in already in the tree
            //currentNode->data.freq+=1;
            currentNode->data.freq+=1;
            cout <<" " << currentNode->data.freq;
        }//and it is found, then increase freq
        else
        {//if it is NOT found
            btree.Insert(data);
        }//insert it into the tree
        
        cout << endl;

    }
    //setiterator
    //while binarytree has more
        //cout << the word and it's frequency
        //next()

    inFile.close();//closing the file

    btree.SetIterator();//setting root far left

    while(btree.More())//while there are words in the tree
    {
        
        cout << "Word: " << data.word <<"  "<< "Freq: " << data.freq << endl;
        data.freq++;
        btree.Next();//move to the next word and print again
    }
    // btree.SetIterator();
    // if(btree.More())
    // {
    //     cout << "if:line Word: " << data.word <<"  "<< "Freq: " << data.freq << endl;
    // }

}
int TreeDataCmp(const DataType& data, const DataType& root)//were comparing the struct's string with root
{
    
    BinaryTree btree;
    
    btree.SetIterator();

    // 
	//take all data in as DataType
	//inside of treedatacmp
	//we will change from dataType to char array
	//


	int length1 = data.word.length();

	int length2 = root.word.length();

	char char_array[length1+1];
	char char_array2[length2+1];

	strcpy(char_array,data.word.c_str());
	strcpy(char_array2,root.word.c_str());

    //while btree.More)
    int strCompare = strcmp(char_array,char_array2);


    //check to see if the word is in the tree

    
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