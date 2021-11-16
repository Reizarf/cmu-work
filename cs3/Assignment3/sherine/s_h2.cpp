#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
//Code Example

using namespace std;


int main()
{
    int table[126];

    char t[100]{'\0'},p[25];

    int n,i,k,j,m,flag=0;

    cout << "Enter the text you'd like to search through: " <<endl;
    cin .getline(t,126);
    cout << "Enter the pattern you'd like to search for: "<<endl;
    cin.getline(p,25);

    n = strlen(t);
    m = strlen(p);


    // for(int i = 0; i < n; i++)
    // {
    //     cout << t[i] <<"#1: " << endl;
    // }

    for(i = 0; i < 126;i++)
    {
        table[i] = m;
    }
    for(j = 0; j< m-2;j++)
    {
        table[p[j]]=m-1-j;
    }
    i = m-1;
    while(i<=n-1)
    {
        k = 0;
        while(k<=m-1 && p[m-1-k]==t[i-k])
        {
            k++;
        }
        if(k==m)
        {
            printf("The position of the pattern is %d \n",i-m+2);
            flag = 1;
            break;
        }
        else
            i=i+table[t[i]];
    }
    if(!flag)
        printf("Pattern is not found :(");
    return 0;



}