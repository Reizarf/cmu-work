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


 /*
    CREATE VECTORS OF 10K, 20K, 30K, 50K, 75K
    generate from beginingg to end with random seed
    pass the sorting algo's the vectors
    cout number of comparisons
            10k     20k     30k     40k     50k     75k
Quick Sort   nc      nc      nc      nc     nc
ShellSort
MergeSort
heapSort
    */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "bubblesort.h"
#include "bubblesort.cpp"

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
    vector<int> sample1(10000);
    generate(sample1.begin(),sample1.end(),rand);
    cout << &sample1 << endl;
    
    vector<int> sample2(20000);
    generate(sample2.begin(),sample2.end(),rand);

    vector<int> sample3(30000);
    generate(sample3.begin(),sample3.end(),rand);

    vector<int> sample4(50000);
    generate(sample4.begin(),sample4.end(),rand);

    vector<int> sample5(75000);
    generate(sample5.begin(),sample5.end(),rand);

    srand(time(0));

    int quickSortComp20k = 0;
    int quickSortComp30k = 0;
    int quickSortComp50k = 0;
    int quickSortComp70k = 0;
        
    int comparison1 = 0;
    int mergeSort10k = 0;
    mergeSort10k = mergE(sample1,0,5555,9999,comparison1);
    


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
            cout << "l: " <<mergeSort10k;
            cout << n << '\t' << ncomp << endl;    // print out graph data
            //cout << comparison1 << endl;
        }  
        else
            cout << "_\t" << ncomp << endl;
#endif

    }
    

    return 0;
}
