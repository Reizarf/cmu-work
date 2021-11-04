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
    int * results = horsPoolMatching(bufferArray,sample);
    //clock stop
    cout<< "This is how many time is ocurred: " << HorCounting() << endl;
    for(int i = 0; i < HorCounting();i++)
    {
        cout << results[i] << " ";
    }
    delete[] results;

    //clock start
    results = KMPSearch(bufferArray,sample);
    //clock stop
    cout<< "This is how many time is ocurred: " << KMPCountF() << endl;
    for(int i = 0; i < KMPCountF();i++)
    {
        cout << results[i] << " ";
    }
    delete[] results;

    //clock start
    results = BruteForce(bufferArray,sample);
    //clock stop
    cout<< "This is how many time is ocurred: " << BruteCountF() << endl;
    for(int i = 0; i < BruteCountF();i++)
    {
        cout << results[i] << " ";
    }
    
    delete[] results;
    return 0;
}
