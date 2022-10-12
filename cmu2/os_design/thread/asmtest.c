#include <stdio.h>

int fun(int x){
    x = x+1;
    return x;
}

int y = 100,z;

int main() {
    z = fun(y);
    printf("%d",z);
    return 0;

}