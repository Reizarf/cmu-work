#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <array>
#include <iostream>
#include <string_view>

using namespace std;

int main() {

  int array[15]={125, 100, 94, 88, 75, 71, 66, 58, 
53, 37, 32, 28, 14, 10, 8};

 int n = sizeof(array) / sizeof(array[0]);
  

    sort(array, array + n);
  
    cout << "\nArray after sorting using "
            "default sort is : \n";
    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";
    return 0;
}
