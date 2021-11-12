/*
I declare that all material in this assessment task is
my work except where there is clear acknowledgement
or reference to the work of others. I further declared
that I have complied to the CMU Academic Integrity
policy at the University Website. 
https://coloradomesa.edu/student-services/documents
Authors Name:       Sullivan Frazier
UID(700#:)          700-479463
Date:               5 November 2021

A. Levitin, Introduction to the design and analysis of algorithms, Pearson, Boston, MA, 2012. 

Submissions that do not include the above academic 
integrity statement will not be considered.
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include "algo.h"

using namespace std;
int main()
{
    string userInput;
    clock_t start = 0, end = 0;
    double processTime = 0;

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

    cout <<endl <<"enter the string you'd like to search for: "<<endl;
    cin >> testPiece;
    int patternSize = testPiece.length();
    char sample[patternSize];

    strcpy(sample,testPiece.c_str());
    //clock start
    int * results;
    start = clock();
    
    HorReset();//set counters to 0
    //results = horsPoolMatching(sample,bufferArray);
    //results = sherine(sample,bufferArray);

    cout<< "This is how many time is ocurred in horspool: " << HorCounting() << endl;
    for(int i = 0; i < HorCounting();i++)
    {
        cout <<"position:  " <<results[i] << " "<<endl;
    }
    end = clock();
    processTime = ((double) (end-start)) / CLOCKS_PER_SEC;
    //cout processTime
    cout << "processTime for horspool: " <<processTime <<endl;
    start = 0, end = 0;
    delete[] results;

    KMPReset();//set counters to 0
    //clock start
    start = clock();
    results = KMPSearch(sample,bufferArray);
    //clock stop
    cout<< "This is how many time is ocurred in KMP: " << KMPCountF() << endl;
    for(int i = 0; i < KMPCountF();i++)
    {
        cout <<"p:  " <<results[i] << " "<<endl;
    }
    end = clock();
    processTime = ((double) (end-start)) / CLOCKS_PER_SEC;
    //cout processTime
    cout << "processTime for KMP: " <<processTime <<endl;
    start = 0, end = 0;
    delete[] results;

    BReset();//set counters to 0
    //clock start
    start = clock();
    results = BruteForce(bufferArray,sample);
    //clock stop
    cout<< "This is how many times it ocurred with brute force: " << BruteCountF() << endl;
    for(int i = 0; i < BruteCountF();i++)
    {
        cout <<"p:  "<< results[i]<<endl;
    }
    end = clock();
    processTime = ((double) (end-start)) / CLOCKS_PER_SEC;
    //cout processTime
    cout << "processTime for BruteForce: " <<processTime <<endl;
    delete[] results;
    return 0;
}
