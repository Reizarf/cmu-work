#include <iostream>

using namespace std;
//memory leak program

int main(){
    for (int i = 0; i < 1000; i++)
    {
        int *p=(int *)malloc(sizeof(int)*100);
        if(rand()%100>50) free(p);
        cout << i << endl;
    }
    return 0;
}