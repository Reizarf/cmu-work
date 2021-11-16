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

#include <string.h>
#include <cstdio>
#include "algo.h"
static int HorCount = 0, HorComp = 0;
const int size = 256;//25?
int Table[size];

void shiftTable(char pattern[size])
{
    int m = strlen(pattern);
    
    for(int i = 0; i < size-1; i++)
    {
        Table[i] = m;
    }
    for(int j = 0; j < m-2; j++)
    {
        Table[pattern[j]] = m - j - 1;//here it the issue
    }
}

int* horsPoolMatching(char pattern[], char data[])
{
    //call shift table
    int* position = new int[1000];

    shiftTable(pattern);
    int k = 0;
    int m = strlen(pattern-1);
    int n = strlen(data-1);
    int i = m - 1;

    while(i <= n -1)
    {
        k=0;
        while ((k <= m - 1) && (pattern[m-1-k] = data[i-k]))
        {
            k = k + 1;
            HorComp++;
        }
        if( k == m)
        {
            position[HorCount] = (i - m + 1);
            HorCount++;
            i = i + Table[data[i]];
        }
        else
        {
            i = i + Table[data[i]];
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
// int sherine(char pattern[], char data[])
// {//pattern = sample and data = .txt
//     int table[126];
//     char t[100]{'\0'},p[25];
//     int m,i,k,j,m,flag = 0;

//     int n = strlen(pattern);//length of pattern

//     int m = strlen(data);//length of .txt

//     for(int i = 0; i < 126;i++)
//         table[i] = m;

//     for(int j = 0;k<m-2;j++)
//         table[p[j]] = m - 1 - j;
//     i = m -1;
//     while(i<=n-1)
//     {
//         k=0;
//         while(k<=m-1 && p[m-1-k] == t[i-k])
//         {
//             k++;
//             if(k==m)
//             {
//                 printf("The positios of the pattern is found at %d\n",i-m+2);
//                 flag = 1;
//                 break;
//             }
//             else
//                 i = i+table[t[i]];
//         }
//         if(!flag)
//             printf("Pattern is not found in the given text");
//         return table[i];
//     }

// }