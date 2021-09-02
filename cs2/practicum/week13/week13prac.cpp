#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using namespace std;
int main()
{
    int values[] = {1,2,3,4,5};
    
    
    vector<int>intVector(5);

    list<int>intList(5);

    copy(values+2,values+4,intVector.begin());

    copy(intVector.begin(),intVector.end(),back_inserter(intList));

    for(int i : intList)
    {
        cout << i << " "<< endl;
    }

    cout <<"after intial copy intVector" << endl;
    for(int e:intVector)
    {
        cout << e << " ";
    }

    cout << "after initial copy intList" << endl;
    for(int e:intList)
    {
        cout << e << " ";
    }
    
    intVector.insert(intVector.begin(),747);

    ostream_iterator<int>output(cout," ");

    cout <<"After the insertion function" << endl;
    copy(intVector.begin(),intVector.begin()+4,output);

    //copy intvector to output here

    copy(intVector.begin(),intVector.begin() + 4,intList.begin());
    cout << "After the copy function, intlist: " <<endl;

    copy(intList.begin(),intList.end(),output);

    return 0;

}
