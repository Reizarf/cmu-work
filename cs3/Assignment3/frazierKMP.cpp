#include <bits/stdc++.h>
using namespace std;
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
            
            cout << "Pattern found at:", k);
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

void computeLPSArray(char* pattern, int M, int* lps)
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