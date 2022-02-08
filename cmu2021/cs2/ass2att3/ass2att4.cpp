/*
/*
 I declare that all material in this assessment task is my work except where
there is clear acknowledgement or reference to the work of others.

I further declare that I have compiled and agreed to the CMU Academic Integrity
Policy at the University website.
     http://www.coloradomesa.edu/student-services/documents

     Author's Name: Sullivan Frazier
     UID (700#): 700479463
     Date: April 1, 2021

Worked on with
    Stephen Marshall,
	Cavan P,
    Lauren Lewis,
    Sebastian Medina,
	Blake Kohlbrecher,
    Ethan

 */


// main.cpp - CSCI112 - Spring 2021 - S Antoun
// Student Name       : Sullivan Frazier
// Student Number     : 700-470463
// Email              : sdfrazier@mavs.coloradomesa.edu
// Date Completed     : March 31, 2021
// Description        : MRO Office
// ****** NOTE: DO NOT MODIFY ANYTHING IN THIS FILE! ******
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include<fstream>

using namespace std;

struct Customer
{
    int ArrivalTime,DepartureTime,key;
    string Payment;
    Customer * next;
};

Customer Customers[50];

class Queue
{
  public:
    Customer *front;
    Customer *rear;

    Queue()//initialize
    {
      front = NULL;
      rear = NULL;
    }
    bool isEmpty()
    {
    if(front==NULL && rear==NULL)
    {
    return true;
    }
    else
    {
    return false;
    }
    }

bool checkIfCustomerExist(Customer *n)
{
Customer *temp = front;
bool exist=false;
while(temp!=NULL)
{
    if(temp->key==n->key)
    {
        exist=true;
        break;
    }
    temp=temp->next;
}
    return exist;
}
 
void enqueue(Customer *n)
 {
    if (isEmpty())//if the line IS empty
    {
        front = n;
        rear = n;
        cout<<"Customer walks in and enters the line."<<endl;
    }
    else if(checkIfCustomerExist(n))//Avoiding duplicate customers
    {
      cout<<"Customer already exist with this Key value."
      <<"Enter different Key value"<<endl;
    }
    else
    {
      rear->next=n;//move rear to next
      rear=n;//set rear
      
      cout<<"Customer  ENQUEUED successfully"<<endl;
    }
    
   }
 
 Customer* dequeue()
    {
    Customer *temp=NULL;//temporary pointer
      if (isEmpty())
      {
        cout << "Queue is Empty" << endl;
        return NULL;
      }
      else//if not empty
      {
        if(front==rear)
        {
          temp=front;//set temp to front
          front = NULL;//clear front
          rear = NULL;//clear rear
          return temp;//return what's left of temp
        }
        else
        {
          temp=front;//set temp as front
          front = front->next;//move front
          return temp;//let go of temp
        }
          
       }
    }
 
 int count()
    {
      int index = 0;
      Customer *temp=front;
      while(temp!=NULL)
    {
        index++;
        temp=temp->next;
    }
     return index;
    }
 
 void display()//display who's in line
    {
      if(isEmpty())//empty
      {
        cout << "Line empty" << endl;
        //cout << endl;
      }
    else//not empty
    {
      cout << "Customer' currently in line: " << endl;
        Customer *temp=front;
        while(temp!=NULL)
        {
          cout<<"Customer number: "<<temp->key+1<<" in line at: "<<temp->ArrivalTime<<", paying with: "<<temp->Payment<<endl;
          temp=temp->next;
          
        }
      cout<<endl;
    }
    
    }
};

int main()
{
  string payment;//store payment method
    int arrivaltime;//store time of arrival
  ifstream myfile ("Ass2.dat");
  if (myfile.is_open())
  {
      int i=0;//I used to customer counter
    while (!myfile.eof())//while not eof
    {
      myfile >> arrivaltime;
      myfile >> payment;
      Customers[i].ArrivalTime=arrivaltime;
      Customers[i].Payment=payment;
      Customers[i].key=i;
      cout<<Customers[i].ArrivalTime<<" "<<Customers[i].Payment<<endl;
      i++;//read again at the bottom, 
    }
    myfile.close();
  }

  else cout << "Unable to open file";
    
    
    Queue q;
    int option,key, ArrivalTime;
    int time=0;
    string Payment;
    while (time<1800)
    {
        for(int i=0;i<50;i++)
        {
            //cout<<Customers[i].ArrivalTime<<endl;
            if(Customers[i].ArrivalTime==time)
            {
                //cout<<"Yeet"<<endl;
                Customer * new_Customer = new Customer();
                key=Customers[i].key;
                ArrivalTime=Customers[i].ArrivalTime;
                Payment=Customers[i].Payment;
                new_Customer->key = key;
                new_Customer->ArrivalTime = ArrivalTime;
                new_Customer->Payment= Payment;
                q.enqueue(new_Customer);
            }
            if(Customers[i].ArrivalTime+30==time)
            {
                q.dequeue();
            }
            if(Customers[i].Payment == "C")
            {
               Customers[i].DepartureTime+=10;
            }
            /*if(Customers[i].ArrivalTime+30==time){
                cout << "DEQUEUE Function Called - " <<endl;
                new_Customer = q.dequeue();
                cout<<"Dequeued Value is: ("<<new_Customer->key<<","
           <<new_Customer->ArrivalTime<<")";
                delete new_Customer;
           cout<<endl;
            }*/
        }
        q.display();
        //cout << "clock: " <<time<<endl;
        time++;
    }
     
      /*do {
        cout << "What operation do you want to perform?"
     <<"Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. count()" << endl;
        cout << "5. display()" << endl;
        cout << "6. Clear Screen" << endl << endl;
     cin >> option;
     
       //Customer n1 = new Customer();
     Customer * new_Customer = new Customer();
     
        
        switch (option) {
        case 0:
          break;
        case 1:
            cout << "ENQUEUE Function Called -" <<endl;
          cout << "Enter KEY and VALUE of Customer to ENQUEUE "
     <<"in the Queue"
     <<endl;
          cin >> key;
          cin >> ArrivalTime;
                cin >> Payment;
          new_Customer->key = key;
          new_Customer->ArrivalTime = ArrivalTime;
            new_Customer->Payment= Payment;
          q.enqueue(new_Customer);
          break;
        case 2:
          cout << "DEQUEUE Function Called - " <<endl;
          new_Customer = q.dequeue();
          cout<<"Dequeued Value is: ("<<new_Customer->key<<","
     <<new_Customer->ArrivalTime<<")";
          delete new_Customer;
     cout<<endl;
          
          break;
        case 3:
            cout << "isEmpty Function Called - " << endl;
          if (q.isEmpty())
            cout << "Queue is Empty" << endl;
          else
            cout << "Queue is NOT Empty" << endl;
          break;
        case 4:
            cout << "Count Function Called - " << endl;
          cout << "No of Customers in the Queue: " <<q.count()
     <<endl;
          break;
        case 5:
          cout << "Display Function Called - " << endl;
          q.display();
          cout << endl;
          break;
        
        case 6:
          system("cls");
          break;
        default:
          cout << "Enter Proper Option number " << endl;
        }
     
      } while (option != 0);

*/
    return 0;
}
