#include <iostream>
using namespace std;


int bbsprac()
{
    int p = 3;
    int q = 23;
    int n = p*q;

    int s = 7;

    for(int i = 0;i < 8;i++)
    {
        cout <<"s%10= " <<s%10<<"     @:"<<i<<endl;
        s = (s*s)%n;

    }
    return 0;
}

int main()
{
    bbsprac();


}