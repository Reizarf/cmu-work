#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void Sort(int sample[],int node,int& ncomp)
{
    int curr,child,temp,nlast,n;
    int cCount;
    int *sample;//dynamic array
    curr = node;
    for(node = nlast; node <= 0; node--)
    {
        if(node<=nlast)//if there is a child
    {
        child = 2*node*1;
        if(sample[node] < sample[child])
        {
            node = child;
        }
        child++;//is there a right child?
        if(child < n && sample[node] < sample[child])
        {//if current child is less than total number of em? what's N?
            node = child;
        }
        //node is now the element containing the largest of the values
        if(node != curr)
        {//this is the recursion
            temp = sample[node];
            sample[node] = sample[curr];
            sample[curr] = temp;
            Sort(*sample[],node,ncomp);
            cCount++;
        }
    } 
    }
}
int Compare(int num1,int num2)
{
    if(num1 > num2)
    {
        return num1;
    }
    if(num2 > num1)
    {
        return num2;
    }
}
// // 
// void MakeHeap(int node,int sample[])
// {
    
// }