#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

bool greaterThan3(int value)
{
    return value > 3;
}

int main()
{
    int x;
    int values[] = {1, 7, 3, 4, 3, 6, 1, 2};

    list<int>intList(values,values+8);

    ostream_iterator<int>output(cout," ");

    cout << "Initial content values : " <<endl;
    copy(values,values+8,output);
    cout << endl;
    cout << "Initial list values : "<<endl;
    copy(values,values+8,output);
    cout << endl;
    remove(values,values+8,3);
    

    remove_if(values,values+8,greaterThan3);

    cout << "after the remove function,: ";
    copy(values,values+8,output);
    cout << endl;
    cout << "after the remove with parameters function: ";
    copy(intList.begin(),intList.end(),output);
    cout << endl;
    return 0;


}