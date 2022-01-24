#include <iostream> 
using namespace std;
#include <fstream>

class Node
{
    public:
    int number;
    char data;
    int serviceTime = 0;//how long they've actually stayed in line
    int customerID = 0;
    int arrivalTime = 0;
    int timeLeft = 30;//default value of 30, counts down while being served
    int transactionTime = 0; //because im lazy
    int hasArrived = -1;
    Node * next;
    int end = 0;
    
    Node()
    {
        number = 0;
        data = ' ';
    }
    Node(int n,char d)
    {
        transactionTime = n;
        data = d;
        //arrivalTime = a;
        next = NULL;
    }
};
class Queue
{
    public:
    Node *cheque;
    Node *front;
    Node *rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    bool isEmpty()
    {
        Node *listptr = front;
        //front = listptr;
        bool isEmpty = true;
        while(listptr!=NULL)//if line is NOT empty
        {
            
            if(listptr->hasArrived == 1)//returning false that the line is NOT empty
            {
                isEmpty = true;
            }
            
            listptr = listptr->next;
        
        }
        return front == NULL;
    }
    bool checkIfNodeExists(Node *n)
    {
      Node *temp = front;
      bool exist = false;
      while(temp!=NULL)
      {
        if(temp->transactionTime==n->transactionTime)
        {
          exist = true;
          break;
        }
      }
      return exist; 
    }
    bool isLinkedListEmpty()
    {
        if(front == NULL && rear == NULL)
        {
          return false;//if line is empty return false
        }
        else
          return true;
    }
    void enqueue(int parrivalTime, int ptransactionTime,char pdata,int pserviceTime,int phasArrived, int pcustomerID)
    {
      //create a new node
      //pass all the data
      //connect the nodes
      Node *node = new Node;

      node->arrivalTime = parrivalTime;
      node->transactionTime = ptransactionTime;
      node->data=pdata;
      node->customerID = pcustomerID;
      node->serviceTime=pserviceTime;
      node->hasArrived=phasArrived;

      if(front == NULL)
      {
        front = node;  
        rear = node;    
        front->next = NULL;
        rear->next = NULL;
      }
      else//not our first node, we need to add it to the back of the list
      {
        
        rear->next = node;
        rear = rear -> next;
        //rear = node;
        rear->next = NULL;
      }
      //see what is in the rear node via the rear pointer HERE
      //cout << " arrival time " <<rear->arrivalTime<< endl;
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
        enqueue(arrivalTime,transactionTime,data,serviceTime,hasArrived,customerID);
        
      }
    }
    void display() //prints contents of queue
    {
      Node* curr;
      curr = front;

      while (curr != NULL)
      {
        cout << curr->arrivalTime << " " << curr->data << "  " << curr->customerID << endl;
        curr = curr->next;
      }
      cout << endl;
    }

    void dequeue()//(Node *&point)
    {
      if(front != NULL)//sets temp to the front, moves front and deletes temp
      {
        Node * temp;
        temp = front;
        cout << "front: " << front << endl;
        front = front->next; 
        
        delete temp;
        cout <<"temp->arrivalTime: " << temp->arrivalTime << endl;
        
        //cout << "front->next: " << front->next<<endl;
        cout <<"made it" << endl;
      }

      else
      {
        front = rear = NULL;
      }
    }
    
    //front = rear = NULL;
    

      /*
      if(point == NULL)//if front is empty
      {
          rear = NULL;//clear rear
          
          return;//supposed to be when the line is empty
      }
      //#problem here too
      cout << "customer #: " << point->customerID << "is leaving  the line " << endl;

      if (point->next == NULL)//if next node is empty
      {
          cout << "123123" << endl;
          point->transactionTime = 100;
          point->hasArrived = -1;
          return;
      }

      point = point -> next;
      point->hasArrived = -1;
      point->transactionTime = 0;
      //add 30 to their arrival time to go back into the clockcounter while loop
      //right????
      //to put them back in the normal line
      
      //point->arrivalTime += 30;
      
      
      //delete(temp);//delete temp
      */
    //}
    // void moveLineDQ(Node *&point)
    // {
    //   cout <<"1!:" << point->transactionTime << endl;
    //   Node * newnode = front;
    //   int truecount = 0;
    //   if(point->transactionTime == 30)//#PROBLEM HEREEEEE
    //   {
    //       cout << "test" <<endl;
    //       cout << point->hasArrived << "has arrived" << endl;
    //       dequeue(point);
    //   }
   
    // }
    void printFront(int time)
    {
      if(front!=NULL)
      {
        if(front->arrivalTime >= time)
        {
          //cout << "person, timeLeft:"<<front->timeLeft;
        }
        else if(front->hasArrived == 1)
        {
            cout << "------empty-----";
        }
      }
    }

    //only runs for peoplr who finished chekc line & are rejoining cash
  void addToQueue(int clockCounter, Node *&insertPerson, bool checkOrder = true)
  {
    Node * lastPerson = front;
    bool isFront = true;

    if(checkOrder)
    { //only if we need to be careful where we put em
      if(front->arrivalTime <= clockCounter)
      {
        isFront = true;
      } 
      else
      {
        isFront = false;
      }
      while(lastPerson->next != NULL && lastPerson->next->arrivalTime <= clockCounter)
      {
        lastPerson = lastPerson->next;
      }
    } 
    else 
    {
      lastPerson = rear; 
    }
    //at this point, pointer refers to the last person in queue @ currenttime

    if(!isFront)
    {
      insertPerson->next = lastPerson->next;
      lastPerson->next = insertPerson;
    }
    //else if(front != NULL)
    //
    else if(front!=NULL)//if they need to go in front (the line is empty)
    {
      insertPerson->next = front;
      front = insertPerson;
    }
    else
    {
      front = insertPerson;
    }
 
  }

    
};

// void leaveCheckLine()
// {
  
// }

void simulate(Queue &main, Queue &cheque) //called once, main simulation
{
  int clockCounter = 0;

//   Node * chequeFront = cheque.front;
//   Node * mainFront = main.front;
  
  cout << "MAIN QUEUE:\n";
  main.display();
  
  cout << "\n\nCHEQUE QUEUE:\n";
  cheque.display();

  //the "BIG LOOP"
  while(clockCounter < 200)//clock timer to iterate
  {
    
//##########   MAIN QUEUE  ######################
    if(main.front->arrivalTime >= clockCounter)
    { //only serve people who have arrived
        //send people to cheque queue
        while(main.front->arrivalTime <= clockCounter && !main.isEmpty())
        { //send all the cheque people at front to cheque
          // cout << "main.front->arrivalTime: " << main.front->arrivalTime << endl;
          // cout << "Removing cheque customer from main queue\n";
          // cout << " main.front->timeLeft: " << main.front->timeLeft << endl;
          main.front->timeLeft += 10;
          cheque.addToQueue(clockCounter, main.front, false); //by god, this better add to the end of cheque
          // cout << "test 123" <<endl;
          // cout << "seg fking fault" <<endl;
          
          if(main.front->arrivalTime == clockCounter)//if(main)
          { //'1' is selected so that customers do not wait a second @ 0timeLeft
            cout << "Spending 1 second serving cash customer\n";

            main.front->timeLeft --;
            cout << "main.front->timeLeft : "<< main.front->timeLeft << endl;
            break;

          }

          else if(main.front->timeLeft == clockCounter+10)
          { //the person in front is done, leaves
            cout << "Removing cash customer from main queue\n";
            main.front->timeLeft --;
            //main.dequeue();//look up a proper way to dequeue here
          }
          else if(main.front->timeLeft == 0)
          {
            //main.front = main.front->next;
            //main.front = main.front->next;
            main.dequeue();
          }
          else if(main.front->data == '$')
          {
            cout << "spending a sec for cash customer" << endl;
            main.front->timeLeft--;
          }
          else
          {
            cout << "clockCounter++: " << endl;
          }
        }
    } 
//##########   CHEQUE QUEUE  #####################
    if(cheque.front!= NULL)
    {
        if(cheque.front->timeLeft >= 31)
        {
          cout <<"cheque.front->timeLeft: "<< cheque.front->timeLeft<<endl; //they still gotta wait
          cout << "Spending 1 second serving cheque customer\n";
          cheque.front->timeLeft--;
        }
        else if(cheque.front->timeLeft == 0)
        {
          cheque.dequeue();
        }
        else if(cheque.front->timeLeft < 31 && cheque.front->data == 'C')
        { //they are done, get em ready to send to main
          cout << "Removing cheque customer from cheque queue\n";
          cheque.front->timeLeft--;
          cout << "cheque.front->timeLeft: " << cheque.front->timeLeft << endl;
          cheque.front-> data = '$';
          cout<< "here" << endl;
          cout << cheque.front->data;
          main.addToQueue(clockCounter, cheque.front);
          cheque.front = cheque.front->next;
          // main.front = main.front->next;

          cout << main.front->next->arrivalTime << " :cheq front"<<endl;

        }
        else if(cheque.front->timeLeft > 0)
        {
          cheque.front->timeLeft--;
          cout << "here" << endl;
          cout << "cheque.front->timeLeft: " << cheque.front->timeLeft << endl;
        }
        else if(cheque.front->timeLeft = 0)
        {
          cheque.dequeue();
        }
    }
//##########   DONE  #############################
    
    /*
    //MISSING CODE TO DEAL WITH PEOPLE THAT HAVE ONLY CASH FROM THE START
    //IF(main.front->data == '$')
    //{
      //main.front

    //}

   
    */
    clockCounter++;
    cout << clockCounter << ":clock" << endl;
    //cout << "main: ";
    main.printFront(clockCounter);
    //cout << "\tcheque: ";
    cheque.printFront(clockCounter); 
    cout << endl;
  }
}
