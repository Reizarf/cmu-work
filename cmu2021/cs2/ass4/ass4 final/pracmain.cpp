//
//  Prac12Lmain.cpp
//  
//
//  Created by Antoun, Sherine on 4/14/21.
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*  This is the program Prac12main.cpp                    *
*  It generates a sequence of random shuffles of a set   *
*  of integers so that a sort function can be used and   *
*  the number of comparisons plotted.                    *
*  If compiled with the -DPRINT option, the sorted data  *
*  is printed instead of the plot data.                  *
*  Requires a function with prototype                    *
*     void Sort(int[],int,int&);                         *
*  which sorts an array of a specified length, returning *
*  the number of comparisons made between data values.   *
*********************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "bubblesortt.h"
//#include "bubble.cpp"

#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    srand((unsigned)time(0));
    
    int sample[10000];
    int i, j, k, n, temp, ncomp;

    /*
    CREATE VECTORS OF 10K, 20K, 30K, 50K, 75K
    generate from beginingg to end with random seed
    pass the sorting algo's the vectors
    cout nc's
    */

    //creating and filling a vector of 10k ints
    vector<int> sample1(10000);
    generate(sample1.begin(),sample1.end(),rand);
    cout << &sample1 << endl;
    //creating and filling a vector of 20k ints
    vector<int> sample2(20000);
    generate(sample2.begin(),sample2.end(),rand);
    //creating and filling a vector of 30k ints
    vector<int> sample3(30000);
    generate(sample3.begin(),sample3.end(),rand);
    //etc
    vector<int> sample4(50000);
    generate(sample4.begin(),sample4.end(),rand);
    //etc
    vector<int> sample5(75000);
    generate(sample5.begin(),sample5.end(),rand);

    srand(time(0));
    //create an integer 
    int quickSortComp10k = 0;
    int quickSortComp20k = 0;
    int quickSortComp30k = 0;
    int quickSortComp50k = 0;
    int quickSortComp70k = 0;
    //for each sort
    int heapSort10k = 0;
    int heapSort20k = 0;
    int heapSort30k = 0;
    int heapSort50k = 0;
    int heapSort70k = 0;
    //in each caliber of sorts
    int mergeSort10k = 0;
    int mergeSort20k = 0;
    int mergeSort30k = 0;
    int mergeSort50k = 0;
    int mergeSort70k = 0;
    //these will be returned into that table
    int shellSort10k = 0;
    int shellSort20k = 0;
    int shellSort30k = 0;
    int shellSort50k = 0;
    int shellSort70k = 0;
    //so, the idea is to call each function
    //set it equal to an integer
    //and that integer is the number of comparisons


    int comparison1 = 0;
    int comparison2 = 0;
    int comparison3 = 0;
    int comparison4 = 0;
    int comparison5 = 0;
    
    int mergeComp1 = 0;
    cout << "here" << endl;
    
    quickSort(sample1,0,9999,comparison1);
    quickSortComp10k = quickSort(sample1,0,9999,comparison1);//I'm pretty sure this works
    quickSortComp20k = quickSort(sample2,0,19999,comparison2);
    quickSortComp30k = quickSort(sample3,0,29999,comparison3);
    quickSortComp50k = quickSort(sample4,0,49999,comparison4);
    quickSortComp70k = quickSort(sample5,0,69999,comparison5);

    heapSort10k = heapify(sample1,0,10000);
    heapSort20k = heapify(sample2,0,20000);
    heapSort30k = heapify(sample3,0,30000);
    heapSort50k = heapify(sample4,0,50000);
    heapSort70k = heapify(sample5,0,70000);

    //problem with mergesort seg fault in mergeSort();


    /*
    This is where the merge sort function is supposed to be called
    there is an error, undefined reference to the function

    */


    // mergeSort10k = mergeSorT(sample1,0,sample1.size(),comparison1);
    // mergeSort20k = mergeSort(sample1,0,19999,comparison2);
    // mergeSort30k = mergeSort(sample1,0,29999,comparison3);
    // mergeSort50k = mergeSort(sample1,0,49999,comparison4);
    // mergeSort70k = mergeSort(sample1,0,69999,comparison5);

    shellSort10k = shellSort(sample1);
    shellSort20k = shellSort(sample2);
    shellSort30k = shellSort(sample3);
    shellSort50k = shellSort(sample4);
    shellSort70k = shellSort(sample5);
    

#ifndef PRINT
    cout << "Performance of a sort algorithm\nNumber of values\nNumber of comparisons\n";
#endif
    for (i=0;i<10000;i++)
        sample[i] = i;        // fill the array with consecutive integers
    for (i=1;i<101;i++)
    {
        n = 100*i;        // for n = 100,200,...,10000
        for (j=0;j<n;j++)
        {
            k = rand()%(n-j)+j;    // shuffle the n integers
            if (k != j)
            {
                temp = sample[j];
                sample[j] = sample[k];
                sample[k] = temp;
            }
        }
#ifdef PRINT
        cout << "For " << n << " values\n";    // print out to see if it sorts
        for (j=0;j<n;j++)
        {
            cout << sample[j];
            if (j%10 == 9)
                cout << endl;
            else
                cout << '\t';
        }
#else
        if (i%5 == 0)//THIS IS WHERE THE NUMBERS ARE COMING OUT - 20 rows by 4 colums
        {
            //cout << "l: " <<mergeSort10k;
            //cout << n << '\t' << ncomp << endl;    // print out graph data
            //cout << comparison1 << endl;

        }  
        else
            cout <<"";

#endif
    }
    cout << "QuickSort with 10k int's: " << quickSortComp10k << endl;
    cout << "with 20k int's: " << quickSortComp20k<< endl;
    cout << "with 30k int's: " << quickSortComp30k<< endl;
    cout << "with 50k int's: " << quickSortComp50k<< endl;
    cout << "with 70k int's: " << quickSortComp70k<< endl;

    cout << "HeapSort10k: " << heapSort10k << endl;
    cout << "HeapSort20k: " << heapSort20k << endl;
    cout << "HeapSort30k: " << heapSort30k << endl;
    cout << "HeapSort50k: " << heapSort50k << endl;
    cout << "HeapSort70k: " << heapSort70k << endl;

    cout << "MergeSort10k : " << mergeSort10k << endl;
    cout << "MergeSort20k : " << mergeSort20k << endl;
    cout << "MergeSort30k : " << mergeSort30k << endl;
    cout << "MergeSort50k : " << mergeSort50k << endl;
    cout << "MergeSort70k : " << mergeSort70k << endl;

    cout << "ShellSort10k : " <<shellSort10k << endl;
    cout << "ShellSort20k : " <<shellSort20k << endl;
    cout << "ShellSort30k : " <<shellSort30k << endl;
    cout << "ShellSort50k : " <<shellSort50k << endl;
    cout << "ShellSort70k : " <<shellSort70k << endl;

    return 0;
}
