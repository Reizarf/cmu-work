#include <stdio.h>

int increment(int a){
    return a+1;
}

int fun(int a, float b){
    int c = increment(a);
    return b;
}

int main() {
    int z = fun(10,3.14);
    printf("%d",z);
    return 0;
}