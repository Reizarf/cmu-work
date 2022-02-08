#ifndef bubblesort_H
#define bubblesort_H

#include <vector>
#include <algorithm>
//#include "Prac12main.cpp"

using namespace std;
#include <iterator>
#include <cstdlib>


    void shellSort(vector<int> & arr);
    int merge(vector<int> &arr, int start, int middle,int end);
    void mergeSort(vector<int> &arr, int start,int end);
    int heapify(vector<int> &arr, int i, int size_);
    void buildMaxHeap(vector<int> &arr);
    void switchh(vector<int> &arr, int x, int y);
    int quickSort(vector<int> &vec, int L, int R, int &Comparisons);


#endif