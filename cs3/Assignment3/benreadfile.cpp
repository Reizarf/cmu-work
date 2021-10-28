#include <iostream>
#include <fstream>
#include <string.h>
//#include "knp,BF,HP.cpp"
using namespace std;
int main(){
    //still working on reading all contents at once???
    string choice;
    int fileLength;
    char fileN[fileLength];                          //initialize start/quit (choice), and file name
    cout << "Please enter a file to read: ";
    cin >> fileN;                               //store file name

    //read file here
    fstream fileStrm;

    if(strcmp(&fileN[strlen(fileN)-4], ".txt")==0)
        fileStrm.open(fileN,ios::in);

    fileStrm.seekg(0,ios::end);
    fileLength=(int)fileStrm.tellg();

    fileStrm.seekg(0,ios::beg);

    //char filler[fileLength];
    char *filler = new char[fileLength];

    fileStrm.read(filler,fileLength);

    fileStrm.close();

    cout << filler << endl << endl;


    
}