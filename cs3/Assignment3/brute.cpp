#include <iostream>
#include <fstream>  
#include <iomanip>
using namespace std;
int main()
{
    
    // char T[1000];
    // char P[100];
    
    // ifstream read;

    // int markNum;

    // read.open("testfile.txt");

    // if(!read.good())
    // {
    //     cerr << "File not found" << endl;
    //     exit(1);
    // }
    // read >> T;
    

    // for(int i = 0; i < 1000; i++)
    // {
    //     cout << T[i];
    // }



    //need to be able to read in the entire file in a few lines
    //seekg()?????
    //look into cout.write
    //get the readfile function working
    //
    //

    ifstream is("testfile.txt",ifstream::binary);
    if(is)
    {
        is.seekg(0,is.end);//setting position to the start
        int len = 0;
        is.seekg(0,is.beg);//setting postiion to eof

        char * buffer = new char[len];

        is.read(buffer,len);

        is.close();

        cout.write(buffer,len);
        cout << buffer;//print here

        delete[] buffer;

    }

    return 0;
}