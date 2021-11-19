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