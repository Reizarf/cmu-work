#include <iostream>
#include "att2.h"
//using namespace std;
int main()
{
  for(int k = 0; k < 1; k++)
  {
    int option;

    cout <<endl <<  "Press an option." << endl;
    cin >> option;
    
    // if(option == 1)
    // {
    //     cout << "readfile func" << endl;
    //     q.readFile();
    // }
    if(option == 1)
    {
      Queue mainQueue, chequeQueue;
      cout <<"inline" << endl;
      mainQueue.readFile();
      simulate(mainQueue, chequeQueue);
      //q.enqueue(parrivalTime,ptransactionTime,pdata,pserviceTime,phasArrived,pcustomerID);
    
    }
    if(option == 2)//display
    {
      cout << "display option chosen: " <<endl;
      Queue mainQueue;
      mainQueue.readFile();
      mainQueue.display();
    }
    
  }
}


