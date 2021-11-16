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

#include <iostream>
#include <cstring>
#include "algo.h"

using namespace std;

static int BruteCount = 0, BruteComp = 0;

int * BruteForce(char text[], char pattern[])
{
    int *Pos = new int[1000]; //Array to hold positions of where pattern is found

    int n = strlen(text), m = strlen(pattern);
    
    for (int i = 0; i <= n-m; i++) 
    {
        int j = 0;
        BruteComp ++;
        while (j < m && pattern[j] == text[i+j])
        {
            j ++;
            BruteComp ++;
        }
        if (j == m)
        {
            Pos[BruteCount] = i;
            BruteCount ++;
        }
    }
    return Pos;
}

int BruteCountF()
{
    return BruteCount;
}

int BruteCompF()
{
    return BruteComp;
}

void BReset()
{
    BruteCount = 0;
    BruteComp = 0;
}