#include <string.h>
#include "algo.h"
static int HorCount = 0, HorComp = 0;

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

int* horsPoolMatching(char pattern[], char data[])
{
    //call shift table
    int* position = new int[1000];

    shiftTable(pattern);
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
            position[HorCount] = i - m + 1;
            HorCount++;
        }
        else
        {
        i = i + data[data[i]];
        }
    }
    return position;
}

int HorCounting()
{
    return HorCount;
}
int HorComparing()
{
    return HorComp;
}
void HorReset()
{
    HorCount = 0;
    HorComp = 0;
}