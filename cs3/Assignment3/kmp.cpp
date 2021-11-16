using namespace std;
#include <iostream>
#include <string.h>
#include "algo.h"
static int KMPCount = 0, KMPCompare = 0;
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

#Sources
https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
A. Levitin, Introduction to the design and analysis of algorithms, Pearson, Boston, MA, 2012. 
https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/
https://www.geeksforgeeks.org/kruskals-algorithm-simple-implementation-for-adjacency-matrix/

Submissions that do not include the above academic 
integrity statement will not be considered.
*/
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
            //cout << "Pattern found at:"<<k<<endl;
            j = lps[j-1];
            //increment counter here
            KMPCount++;
        }
        //mismatch after j matches
        else if (i < N && pattern[j] != text[i])
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

void computeLPSArray(char* pattern, int M, int* lps)
{//compute prefix function
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
    // return lps[];
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