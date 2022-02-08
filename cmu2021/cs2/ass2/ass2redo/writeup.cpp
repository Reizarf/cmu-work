#include <iostream>
#include <cassert>
#include "customer.h"
#include "queue.h"
#include "server.h"

using namespace std;

int main() 
{
  cout << "Hello World!\n"<<endl;
  linkedQueueType <customerT> que;
  que.initializeQueue();

}


void readFile()
    {
      //Queue q;
      int transactionTime = 0;
      char data = ' ';
      const int hasArrived = -1;
      int serviceTime = 0;
      int lines = 50;
      int customerID = 0;
      int arrivalTime = 0;
      ifstream inD;
      inD.open("Ass2.dat");
      
      for(int i = 0; i < lines; i++)//change to a controlled loop (eof)
      {
          inD >> arrivalTime;
          // inD >> ws;
          // inD >> ws;
          // inD >> ws;
          inD >> data;
          customerID++;
          
          //addToQueue();
          
      }