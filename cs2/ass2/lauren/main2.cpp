#include <iostream>
using namespace std;
#include "lauren.h";


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
        
        
        for(int i = 0; i < lines; i++)
        {
            inD >> arrivalTime;
            
            inD >> ws;
            inD >> ws;
            inD >> ws;
            inD >> data;
            customerID++; 
            lineEnqueue(arrivalTime,transactionTime,data,serviceTime,hasArrived,customerID);
            
        }
    }


int main()
{
    
}