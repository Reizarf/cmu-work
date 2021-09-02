
#include <iostream>
#include "searchSortAlgorithms.h"

using namespace std;

int main() {
    int yeet;
    int array[10];

    for (int i=0;i<10;i++){
      cin>>yeet;
      array[i]=yeet;
      cout<<array[i]<<" ";
    }
    cout<<endl;
insertionSort(array,10);

for (int i=0;i<10;i++){
      cout<<array[i]<<" ";
    }
    cout<<endl;
    




    return 0;
}
