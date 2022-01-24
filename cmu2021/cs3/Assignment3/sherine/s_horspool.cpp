#include <string.h>
#include <cstdio>


int sherine(char pattern[], char data[])
{//pattern = sample and data = .txt
    int table[126];
    char t[100]{'\0'},p[25];
    int i,k,j,flag = 0;

    int n = strlen(t);//length of pattern

    int m = strlen(data);//length of .txt

    for(int i = 0; i < 126;i++)
        table[i] = m;

    for(int j = 0;k<m-2;j++)
        table[p[j]] = m - 1 - j;
    i = m -1;
    while(i<=n-1)
    {
        k=0;
        while(k<=m-1 && p[m-1-k] == t[i-k])
        {
            k++;
            if(k==m)
            {
                printf("The positios of the pattern is found at %d\n",i-m+2);
                flag = 1;
                break;
            }
            else
                i = i+table[t[i]];
        }
        if(!flag)
            printf("Pattern is not found in the given text");
        return table[i];
    }

}


int main()
{
    char p[25] = "this";

    char data[200] = "one day this might work";

    int result = sherine(&p[25],&data[200]);
    
    return 0;

}