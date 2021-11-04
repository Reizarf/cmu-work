#include <bits/stdc++.h>
#include <time.h>

using namespace std;

#define V 10

int parent[V];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

//does union of i and j - it return false
//if i and j are already in same set

void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);

    parent[a] = b;
}

void KruskalMST(int cost[][V])
{
    int minCost = 0;

    for(int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    //include min weight edges one by one
    int comparisons = 0;
    int edgeCount = 0;

    while(edgeCount < V -1)
    {
        int min = INT_MAX, a= -1,b = -1;
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if(find(i) != find(j) && cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                    comparisons++;
                    
                }
            }
        }
        union1(a,b);
        printf("Edge %d:(%d, %d) cost:%d \n",
            edgeCount++,a,b,min);
        minCost += min;
    }
    printf("\nMinimum cost = %d \n", minCost);
    cout << "comparisons: " << comparisons << endl;
}

int main()
{
    int cost[][V] = {
        {INT_MAX, 6, 10, INT_MAX, INT_MAX, INT_MAX,INT_MAX,INT_MAX,INT_MAX},
        {6,INT_MAX,12,11,14,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
        {10,12,INT_MAX,12,INT_MAX,INT_MAX,INT_MAX,16,INT_MAX,INT_MAX},
        {INT_MAX,11,12,INT_MAX,INT_MAX,6,3,INT_MAX,INT_MAX,INT_MAX},
        {INT_MAX,14,INT_MAX,INT_MAX,INT_MAX,4,INT_MAX,INT_MAX,6,INT_MAX},
        {INT_MAX,INT_MAX,INT_MAX,6,4,INT_MAX,INT_MAX,INT_MAX,12,INT_MAX},
        {INT_MAX,INT_MAX,8,3,INT_MAX,INT_MAX,INT_MAX,INT_MAX,16,6},
        {INT_MAX,INT_MAX,16,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,8},
        {INT_MAX,INT_MAX,INT_MAX,INT_MAX,6,12,16,INT_MAX,INT_MAX,13},
        {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,6,8,13,INT_MAX}
    };
    clock_t start,end;

    double timeTaken;

    start = clock();
    
    KruskalMST(cost);//function call here
    
    end = clock();

    timeTaken = ((double) (end-start));

    cout << "The amount of time taken in clocks per sec: " <<timeTaken << endl;
    
    return 0;
}