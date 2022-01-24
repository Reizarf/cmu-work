#include <iostream>
#include <fstream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"

using namespace std;

int main()
{
    cout << "readfile" << endl;
    readFile();



    
}

void readFile()
{
    string userInput,fileName;

    cout << "enter a filename"<<endl;
    
    getline(cin,fileName);

    ifstream inData;
    inData.open(fileName);

}

void inWord()
{
    string filename,word,freq;

    ifstream inData;
    inData.open(filename);

    while(!inData.eof())
    {
        inData >> word;
        BinaryTree::Locate(word);
        
    }
}



