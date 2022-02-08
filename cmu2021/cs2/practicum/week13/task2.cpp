#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    int values[] = {1,2,3,4,5};

    list<int>intList(values,values+6);

    ostream_iterator<int>output(cout," ");

    cout << "Initial values are: ";
    copy(values,values+6,output);
    cout << endl;
    cout << "Initial contents in intList: ";
    copy(intList.begin(),intList.end(),output);
    cout << endl;


    //fill 88 from values +2, to values +3
    fill(values +2,values +4, 88);
    copy(values + 2, values + 3,output);

    cout << "After the fill function...values: ";
    copy(values,values+6,output);
    cout << endl;


    fill_n(intList.begin(),2,99);//should be inserting 99 into the first two spots

    cout << "After the fill_n funct,intList: ";
    copy(intList.begin(),intList.end(),output);
    cout << endl;
    return 0;


}