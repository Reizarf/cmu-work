#include <iostream>
using namespace std;   
template<class elemType>
int seqOrdSearch(const elemType list[], int length, const elemType& item)
{
    int z=0;
for(int i=0;i<length;i++)
{
if(list[i]== item)
{
cout<<"\n Item found at position = "<<i+1<<"\n\n";
z=1;
return i;
}
}


cout<<"\nNot Found\n\n";
    return -1;
     // return -1 if item not found
} //end seqOrdSearch
