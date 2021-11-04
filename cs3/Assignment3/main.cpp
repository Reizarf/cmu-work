#include <iostream>
#include <fstream>
#include <string.h>
#include "algo.h"

using namespace std;
int main()
{
    string userInput;

    int fLen;

    char fileName[fLen];

    cout << "Enter a filename to read: " << endl;
    cin >> fileName;

    fstream inFile;

    if(strcmp(&fileName[strlen(fileName)-4], ".txt") == 0)
    {
        inFile.open(fileName,ios::in);
    }
    else
    {
        cout << "Could not find that filename - "<<endl
            <<"Please make sure the file is in this directory."<<endl;
            return 0;
    }
    inFile.seekg(0,ios::end);
    int fileLen;
    fileLen = (int)inFile.tellg();
    inFile.seekg(0,ios::beg);

    char *bufferArray = new char[fileLen];

    inFile.read(bufferArray,fileLen);

    inFile.close();

    cout << bufferArray << endl;

    string testPiece;

    cout << "enter the string you'd like to search for: "<<endl;
    cin >> testPiece;
    int patternSize = testPiece.length();
    char sample[patternSize];

    strcpy(sample,testPiece.c_str());
    //clock start
    int * results;
    //clock stop
    HorReset();//set counters to 0
    //results = horsPoolMatching(sample,bufferArray);
    cout<< "This is how many time is ocurred in horspool: " << HorCounting() << endl;
    for(int i = 0; i < HorCounting();i++)
    {
        cout <<"@: " <<results[i] << " "<<endl;
    }
    delete[] results;

    KMPReset();//set counters to 0
    //clock start
    results = KMPSearch(sample,bufferArray);
    //clock stop
    cout<< "This is how many time is ocurred in KMP: " << KMPCountF() << endl;
    for(int i = 0; i < KMPCountF();i++)
    {
        cout <<"@: " <<results[i] << " "<<endl;
    }
    delete[] results;

    BReset();//set counters to 0
    //clock start
    results = BruteForce(bufferArray,sample);
    //clock stop
    cout<< "This is how many times it ocurred with brute force: " << BruteCountF() << endl;
    for(int i = 0; i < BruteCountF();i++)
    {
        cout <<"@: "<< results[i]<<endl;
    }
    
    delete[] results;
    return 0;
}
