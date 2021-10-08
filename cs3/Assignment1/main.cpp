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
    // DataType tempNode;
    BinaryTree btree;//creating an object of the class to be used
    BinaryTree::nodePtr currentNode;
    BinaryTree::nodePtr tempNode;
    cout << "Hello user! Please enter the name of the file you'd like to read: " << endl;

    string input;//user input

    cin >> input;//taking file name

    inFile.open(input + ".txt");//you can enter raw filename no extension
    
    while(inFile >> text)//this >> extraction operator skips whitesapce by default
    {
        cout << text;
        // currentNode = new BinaryTree::node;//create another temporary one
        // //
        //copy text variable into data.word
        tempNode = new BinaryTree::node;
        // tempNode->data = data;
        //tempNode->data.word = text;

        
        strcpy(tempNode->data.word,text);
        

        //pass locate the temporary node->data
        //(if locate is true)
        //itll write in temporary what the tree has
        //delete(data,temp)
        //in temp is freq
        //freq+=1
        //insert temp
        

        //cout <<"data.word: " <<data.word << endl;

        if(btree.Locate(data,tempNode->data) == true)
        {//if the data in already in the tree
            tempNode->data.freq+=1;
            cout << tempNode->data.freq << ":#"<<endl;
            btree.Delete(tempNode->data,data);
            
        }//and it is found, then increase freq
        else
        {//if it is NOT found
            btree.Insert(tempNode->data);
        }//insert it into the tree
        
        cout << endl;

    }
    inFile.close();//closing the file

    btree.SetIterator();//setting root far left

    while(btree.More())//while there are words in the tree
    {
        
        cout << "Word: " << tempNode->data.word <<"  "<< "Freq: " << tempNode->data.freq << endl;
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