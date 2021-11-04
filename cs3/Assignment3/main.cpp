#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

char* shiftTable(char pattern[])
{
    int m = strlen(pattern);
    static char Table[26];
    

    for(int i = 0; i < strlen(pattern); i++)
    {
        Table[i] = m;
    }
    for(int j = 0; j < m-2; j++)
    {
        Table[pattern[j]] = m - 1 - j;
    }
    return Table;

}
int horsPoolMatching(char pattern[], char data[])
{
    //call shift table
    shiftTable(pattern);

    //takes both pattern and text to read against
    //output
    //the index of the left end of the first
    //matching substring
    //  or -1 if there are no matches


    //m is strlen of pattern-1
    //n is strlen of data-1
    int k = 0;
    int m = strlen(pattern -1);
    int n = strlen(data -1);
    int i = m - 1;

    while(i <= n -1)
    {
        k=0;
        while ((k <= m - 1) && (pattern[m-1-k] = data[i-k]))
        {
            k = k + 1;
        }
        if( k == m)
        {
            return i - m + 1;
        }
        else
        {
        i = i + data[data[i]];
        }
    }
    return -1;
}

void computeLPSArray(char* pattern, int M, int* lps);

void KMPSearch(char* pattern, char* text)
{
    int M = strlen(pattern);
    int N = strlen(text);

    //create lps[] that will hold longest suffix prefix
    //length of the pattern

    int lps[M];

    computeLPSArray(pattern,M,lps);

    int i = 0;//index for text[]
    int j = 0;//index for pattern[]

    while(i < N)
    {
        if(pattern[j] == text[i])
        {
            j++;
            i++;
        }
        if(j == M)
        {
            int k = i - j;
            
            cout << "Pattern found at:"<<k<<endl;
            j = lps[j-1];
        }


        //mismatch after j matches
        else if ( i < N && pattern[j] != text[i])
        {
            //do not match lps
            //they will match anyway
            if(j!= 0)
                j = lps[j-1];
            else
                i = i + 1;
        }
    }
}

void computeLPSArray(char* pattern, int M, int* lps)//compute prefix function
{
    //length of the previous longest suffix
    int length = 0;

    lps[0] = 0;

    int i = 1;

    while(i < M)
    {
        if(pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else//pattern[i] != pattern[length]
        {
            if(length != 0)
            {
                length = lps[length -1];
                //do not increment i here
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

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


    //cin string 
    //strcpy the string to a character array
    //that's what we call the function on

    //now I need to call horspool
    //bruteforce
    //and kmp

    horsPoolMatching(bufferArray,sample);

    return 0;

}





//brute force from ben
int bruteForce(char* tex, char* pattern){ // dont know if this is working
    cout << tex << endl;
    cout << pattern << endl;
    int textLength=strlen(tex);
    int patternLength=strlen(pattern);
    cout << textLength << endl;
    cout << patternLength << endl;
    for(int i=0; i < textLength; i++){
        cout << "here " << i << endl;
        int j=0;
        while(j<patternLength && pattern[j]==tex[i+j])
        {
            j++;
            cout << j << endl;
        }
        if(j==patternLength) {
          cout << "i= " << i<<endl;
          return i;
        }
    }
    return -1;
}