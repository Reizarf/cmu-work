#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

int nextNum()
{
    static int n = 20;
    return n++;
}


int main()
{   
    int values[] = {1,2,3,4,5};
    list<int>intList(values,values+6);

    ostream_iterator<int>output(cout," ");

    cout <<"Initial contents/values: ";
    copy(values,values+6,output);
    cout << endl;

    cout <<"Initial contents, list: ";
    copy(intList.begin(),intList.end(),output);
    cout << endl;

    //use a function to add generated data
    generate(values+2,values+4,nextNum);
    cout << "after generate: " << endl;
    copy(values,values+6,output);

    generate_n(intList.begin(),4,nextNum);
    cout << "after generate_n: " <<endl;
    copy(values,values+6,output);
    return 0;

}