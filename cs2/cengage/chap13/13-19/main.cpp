#include <iostream>
#include "lineType.h"
using namespace std;

int main() {
  cout<<"Yeet"<<endl<<endl;
   lineType line1(2, 2, 4);
lineType line2(7, 3, 5);
 line1 = line2;

 if (line1==line2){
   cout<<"True";
 }

    return 0;
}
