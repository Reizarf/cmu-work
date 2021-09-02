/*
Our objective is: 

to generate 100000 data items (ints) into an array
 - use heap sort 
 - display outcome
 - display time took to sort array
 - print tree
*/
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ratio>

using namespace std;
using namespace chrono;

//to heapify the data

void heapify(int array[],int n,int i)
{
    int largest = i;//largest number in the array

    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && array[left] > array[largest])
    {//if left child is larget than root
        largest = left;        
    }
    if(right < n && array[right] > array[largest])
    {//if right child is larger than root
        largest = right;
    }
    if(largest != i)
    {//is largest at the root?
        swap(array[i],array[largest]);
        //recursive heapify call to fix the subtree
        heapify(array,n,largest);
    }

}

/* 
A main driver function for the heap sort
*/

void heapsort(int array[], int n)
{
    //build heap - rearrange the array
    for(int i = n/2-1; i >= 0; i--)
    {
        heapify(array,n,i);
    }
    for(int i = n-1; i >= 0; i--)
    {
        swap(array[0],array[i]);
        //swapped highest value to the front
        //call heapify on the reduced array of data
        heapify(array,n,i);
    }

}
//print contents of the array
void printArr(int array[],int n)
{
    for(int i; i < n; i++)
    {
        cout << array[i]<<" ";
    }
    cout << endl;
}

int main()
{
    int array[100];
    srand(832773);
    for(int i = 0; i < 1; i<10000)
    {
        array[i] = rand()*123;
    }
    //computing processing time, NOT IO time
    high_resolution_clock::time_point start = high_resolution_clock::now();
    int n = sizeof(array)/sizeof(array[0]);
    heapsort(array,n);
    high_resolution_clock::time_point end = high_resolution_clock::now();

    printArr(array,n);
    cout << endl << endl;

    duration<double> timespan = duration_cast<duration<double>>(end - start);
    std::cout << "time elapsed: "<< timespan.count()<<endl;
}