/*
	Bubble Sort from the lectures with the comparisons counted
    Author Sherine Antoun May 2000
*/
#include <iostream>
#include <vector>
#include "bubblesort.h"
//#include "Prac12main.cpp"

using namespace std;
//SHELL SORT w/ VECTOR

void shellSort(vector<int> &arr)
{
	//for loop setup:
	//		set the gapSize to the size of the array
	//			/2
	int nc = 0;

	for(int gapSize = arr.size() / 2; gapSize > 0; gapSize /=2)
	{
		for(int currentIndex = gapSize; currentIndex < arr.size();currentIndex++)
		{
			//save current index
			int currentIndexCopy = currentIndex;
			int item = arr[currentIndex];
			//increase counter here??
			nc++;

			while(currentIndexCopy >= gapSize && arr[currentIndexCopy - gapSize] > item)
			{
				arr[currentIndexCopy] = arr[currentIndexCopy-gapSize];
				currentIndexCopy -= gapSize;
			}
			arr[currentIndexCopy] = item;

		}
	}
}




//MERGE SORT
// MERGE SORT HERE HAS SEVERAL FUNCTIONS - one might say,,,, recursive
//merge sort with vectors

int mergE(vector<int> &arr,int start, int middle, int end,int &comparisons)
{
	vector<int> leftArray(middle-start + 1);
	vector<int> rightArray(end-middle);
	
	//fill in left array
	for(int i = 0; i < leftArray.size();++i)
	{
		leftArray[i] = arr[start+i];
		comparisons++;
	}
	//fill in left array
	for(int i = 0; i <  rightArray.size(); ++i)
	{
		rightArray[i] = arr[middle + 1 + i];
		comparisons++;
	}
	
	//merge the temp arrays

	int leftIndex = 0;
	int rightIndex = 0;

	int currentindex = start;

	while(leftIndex < leftArray.size() && rightIndex < rightArray.size())
	{
		if(leftArray[leftIndex] <= rightArray[rightIndex])
		{
			arr[currentindex] = leftArray[leftIndex];
			leftIndex++;
			//increase counter maybe here?
			comparisons++;
		}
		else
		{
			arr[currentindex] = rightArray[rightIndex];
			rightIndex++;
			//or increase here? or both?
			comparisons++;
		}
		currentindex++;
	}
	while(leftIndex < leftArray.size()) arr[currentindex++] = leftArray[leftIndex];

	while(rightIndex < rightArray.size()) arr[currentindex++] = rightArray[rightIndex];
	return comparisons;
}
void mergeSort(vector<int> &arr, int start, int end, int& comparisons)
{
	if(start < end)
	{
		//find middle point
		int middle = (start + end)/2;

		mergeSort(arr,start,middle);//sort first half
		mergeSort(arr,middle+1,end);//sort second half
		//merge sorted halves
		mergE(arr,start,middle,end,comparisons);
	}
	
}


//HEAP SORT
//with vectors doe

int heapify(vector<int> &arr, int i, int size_)
{
	int largest, l = (2*i) + 1, r  = l + 1;
	int nc = 0;
	if(l < size_ && arr[l]  > arr[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	
	if(r < size_ && arr[l] > arr[largest])
	{
		largest = r;
	}
	
	if(largest != i)
	{
		swap(arr[i],arr[largest]);
		heapify(arr,largest,size_);
	}
}
void buildMaxHeap(vector<int> &arr)
{
	int nc;
	for(int i = (arr.size() / 2); i >= 0; i--)
	{
		heapify(arr,i,arr.size());
		nc++;
	}
}



//quick sort with vector
void switchh(vector <int> &arr, int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}
int quickSort(vector<int> &vec, int L, int R, int &Comparisons) {
    int i, j, mid, piv;
    i = L;
    j = R;
    mid = L + (R - L) / 2;
    piv = vec[mid];

    while (i<R || j>L) {
        while (vec[i] < piv){
            i++;
            Comparisons++;
        }
        while (vec[j] > piv){
            j--;
            Comparisons++;
        }

        if (i <= j) 
		{
            switchh(vec, i, j); 
            i++;
            j--;
            Comparisons++;
        }
        else {
            Comparisons++;
            if (i < R){
                quickSort(vec, i, R,Comparisons);
                Comparisons++;
            }
            if (j > L){
                quickSort(vec, L, j,Comparisons);
            }
            return Comparisons;
        }
    }
    return -9999999;
}







/*
Extra functions - 


// void Sort(int arr[], int n, int& ncomp)//bubble sort
// {
// 	int temp, j, LastUnsorted = n-1, LastSwapIndex;
	
// 	ncomp = 0;
// 	while (LastUnsorted > 0)
// 	{
// 		LastSwapIndex = 0;
// 		for (j=0;j<LastUnsorted;j++)
// 		{
// 			ncomp++;
// 			if (arr[j] > arr[j+1])
// 			{
// 				temp = arr[j];
// 				arr[j] = arr[j+1];
// 				arr[j+1] = temp;
// 				LastSwapIndex = j;
// 			}
// 		}
// 		LastUnsorted = LastSwapIndex;
// 	}
// }
// void insertionSort(int arr[],int n,int ncomp)
// {
// 	int i,key, j;
// 	for(i = 1; i < n; i++)
// 	{
// 		key=arr[i];
// 		//move elements of arr[i-1] that are greater than key
// 		//to one position ahead of current position
// 		while(j >= 0 && arr[j] < key)
// 		{
// 			arr[j+1] = arr[j];
// 			j = j-1;
// 		}
// 		//incremeent number of comparisons here?
// 		ncomp++;
// 		arr[j+1] = key;
// 	}
// }
// void printArray(int arr[], int n)
// {
// 	int i;
// 	for(i = 0;i < n; i++)
// 	{
// 		cout << arr[i] << " ";
// 	}
// 	cout << endl;
// }
// shell sort vector check
// merge sort check vector check
// quick sort check
// heap sort check with vector
// int shellSort(int arr[],int n)
// {
// 	for(int gap = n/2; gap > 0; gap /=2)
// 	{
// 		 // Do a gapped insertion sort for this gap size.
//         // The first gap elements a[0..gap-1] are already in gapped order
//         // keep adding one more element until the entire array is
//         // gap sorted
// 		for(int i = gap; i < n; i+=1)
// 		{
// 			 // add a[i] to the elements that have been gap sorted
//             // save a[i] in temp and make a hole at position i
// 			int temp = arr[i];
// 			// shift earlier gap-sorted elements up until the correct 
//             // location for a[i] is found
// 			int j;
// 			for(j = i; j >= gap && arr[j-gap] > temp; j-=gap)
// 			{
// 				arr[j] = temp;
// 			}
// 			return 0;
// 		}
// 	}
// }


//QUICK SORT
// void quickSort(int arr[],int low, int high)
// {
// 	if(low < high)
// 	{
// 		int pi = partition(arr,low,high);
		
// 		quickSort(arr,low,pi-1);
// 		quickSort(arr,pi+1,high);
// 	}
// }
// void swap(int *a, int *b)
// {
// 	int t = *a;
// 	*a = *b;
// 	*b = t;
// }
// int partition(int arr[],int low, int high)
// {
// 	int pivot = arr[high];
// 	int i = (low-1);

// 	for(int j = low; j <= high - 1; j++)
// 	{
// 		if(arr[j] < pivot)
// 		{
// 			i++;
// 			swap(&arr[i],&arr[j]);
// 		}

// 	}
// 	swap(&arr[i+1], &arr[high]);
// 	return (i+1);
// }



void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for(int i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
	for(int j = 0; j < n2;j++)
	{
		R[j] = arr[m + 1 + j];
	}
	 // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
		}
		k++;
	}
	while(i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

}
void mergeSort(int arr[],int l, int r)
{
	if(l>=r)
	{
		return;
	}
	int m = l + (r-1)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
}



void heapify(int arr[],int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i +2;

	if(l < n && arr[l] > arr[largest])
	{
		largest = l;
	}
	if(r < n && arr[r] > arr[largest])
	{
		largest = r;
	}
	if(largest != i)
	{
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
	
}
void heapSort(int arr[], int n)
{
	for(int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr,n,i);
	}
	for(int i = n -1; i > 0; i--)
	{
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}


*/