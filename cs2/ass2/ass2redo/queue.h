
// #include "customer.h"
// #include "server.h"
#include<iostream>
#include <fstream>
using namespace std;

/*

// */
// struct Node
// {
//   int number;//arrival time
//   char data;//cash or check
//   // int maxQueueSize = 0;
//   // int queFront = -1;
//   // int queRear = -1;
//   // int maxQueueSize = -1;
//   // int count = 0;
//   // int list[] = {};
//   Node* list;
  
//   Node()//initialize constructor
//   {
//     number = 0;
//     data = ' ';
//   }
//   Node(int n, char d)//passing data into Node
//   {
//     number = n;
//     data = d;
//     next = NULL;
//   }

// };


/*
QUEUE
*/
template <class Type>
struct nodeType
{
  Type info;
  nodeType<Type> *link;
};
template <class Type>
class linkedQueueType
{

  public:
    int maxQueueSize = 0;
    int queFront = 0;
    int queRear = 0;
    //int maxQueueSize = -1;
    int count = 0;
    Type *list;
    //type class
  //template<class Type>
  // void addQueue(const Type& newElement)
  // {
  //   nodeType<Type> *newNode;
  //   newNode = new  nodeType<Type>;
  //   // nodeType<Type> *queFront;
  //   // nodeType<Type> *queRear;
  //   newNode->info = newElement;
  //   newNode->link = nullptr;
  //   if(queFront == nullptr)
  //   {
  //     queFront = newNode;
  //     queRear = newNode;
  //   }
  //   else
  //   {
  //     queRear->link = newNode;
  //     queRear = newNode;
  //   }

  // }
  //create a pointer node to manage front and rear.
  void Queue()//initialization
  {
    queFront = NULL;
    queRear = NULL;
  } 
  
  // ~Queue()//deconstructor
  // {
  //   delete [] list;
  // }
  bool front()//check front
  {
    assert(!isEmpty());//assert not empty
    return list[queFront];//output front
  }
  bool back()
  {
    assert(!isEmpty());//assert not empty
    return list[queRear];//return rear
  }
  bool isEmpty()
  {
    int count;
    return(count == 0);
  }
  bool isFull()
  {
    return (count == maxQueueSize);
  }
  void enqueue(Type newElement)//insert into queue func
  {
    // nodeType<Type> *queRear;
    
    if(!isFull())
    {
      
      count++;
      list[queRear] = newElement;
      queRear = queRear++;
    }
    else
    std::cout <<"Cannot add to a full Queue"<<endl;
  }
  void removeQueue()
  {
    if(!isEmpty())
    {
      count--;
      //queFront = (queFront + 1) % maxQueueSize;//use the mod operator because the array is circular??
      //but it's not circular
      // so
      queFront = maxQueueSize;
    }
    else
      cout << "Cannot remove from an empty queue" << endl;
  }
  bool queueType(int queueSize)//create queue of a certain size
  {
    if(queueSize <= 0)
    {
      cout << "Size of the array must be positive"<<endl;
      cout << "creating a 100 slot array" << endl;

      maxQueueSize = 100;

    }
    else
    {
    maxQueueSize = queueSize;
    queFront = 0;
    queRear = maxQueueSize -1;
    count = 0;
    list = new Type[maxQueueSize];//creating the array here
    }
  }

  void readFile()
  {
    int number = 0;
    char data = ' ';
    int customerID = 0;
    int lines = 50;
    ifstream inData;
    inData.open("Ass2.dat");
    Type newElement;
    for(int i = 0;i < lines;i++)
    {
      inData >> number;
      inData >> data;
      newElement(number, data);
      customerID++;
      //call enqueue function here?/

      enqueue(newElement);
    }
  }
  void initializeQueue()
  {
    int maxQueueSize = 0;
    int queFront = -1;
    int queRear = maxQueueSize -1;
    int count = 0;
  }
  void startQueue()
  {

    nodeType<Type> *temp;
    nodeType<Type> *queFront;
    while(queFront != nullptr)
    {
      temp = queFront;
      queFront = queFront->next;
      delete temp;
    }
    queRear = nullptr;
  }
  private:
  customerT currentCustomer;
  string status;
  int transactionTime;

};
