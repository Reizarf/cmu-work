#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;


bool greaterThan3(int value)
{
    return value > 3;
}
int main()
{
    int values[] = {1,7,3,4,3,6,1,2};
    list<int>intList(values,values+8);

    ostream_iterator<int>output(cout," ");
    cout << "initial contents/values: ";
    copy(values,values+8,output);

    cout << "intiial intList: ";
    copy(intList.begin(),intList.end(),output);

    int newValues[] = {9,9,9,9,9,9,9};

    list<int>newIntList(newValues,newValues+8);

    unique(intList.begin(),intList.end());

    unique_copy()

}
