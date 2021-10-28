#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    string userInput;

    int fLen;

    char data[fLen];

    cout << "Enter a filename to read: " << endl;
    cin >> data;

    fstream inFile;

    if(strcmp(&data[strlen(data)-4], ".txt") == 0)
    {
        inFile.open(data,ios::in);
    }
    inFile.seekg(0,ios::end);
    int fileLen;
    fileLen = (int)inFile.tellg();
    inFile.seekg(0,ios::beg);

    char *bufferArray = new char[fileLen];

    inFile.read(bufferArray,fileLen);

    inFile.close();

    cout << bufferArray << endl;

    return 0;

}