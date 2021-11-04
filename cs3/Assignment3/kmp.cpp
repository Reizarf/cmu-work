using namespace std;
#include <iostream>
#include <string.h>
#include "algo.h"
static int KMPCount = 0, KMPCompare = 0;
int* KMPSearch(char* pattern, char* text)
{
    int M = strlen(pattern);
    int N = strlen(text);

    //create lps[] that will hold longest suffix prefix
    //length of the pattern
    int * position = new int[1000];

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
            position[KMPCount] = i - j;
            cout << "Pattern found at:"<<k<<endl;
            j = lps[j-1];
            //increment counter here
            KMPCount++;
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
        KMPCompare++;
    }
    return position;
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
            lps[i] = 0;
            i++;
        }
    }
}


int KMPCompareF()
{
    return KMPCompare;
}
int KMPCountF()
{
    return KMPCount;
}
void KMPReset()
{
    KMPCount = 0;
    KMPCompare = 0;
}