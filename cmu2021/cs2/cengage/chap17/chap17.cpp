#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#include <cmath>

#include "simulation.h"
#include "queueAsArray.h"

using namespace std;

void setSimulationParameters(int& sTime, int& numOfServers, int& transTime, int& tBetweenCArrival);

void runSimulation(int numberOfServers, int simulationTime, serverListType& serverList, waitingCustomerQueueType& queue, int tBtwCustomerArrival, int transactionTime);

int main() {

    int simulationTime;       // Total run time for the simulation as time units
    int numberOfServers;      // Number of available servers for the queue
    int transactionTime;      // Time that it takes for a customer/server to finish a single transaction
    int tBtwCustomerArrival; // AVERAGE time between the arrival of each customer


    setSimulationParameters(simulationTime, numberOfServers, transactionTime, tBtwCustomerArrival);
  
    serverListType serverList = serverListType(numberOfServers); // Establish a list for all servers
    waitingCustomerQueueType queue = waitingCustomerQueueType(); // Establish a queue for all customers

    runSimulation(numberOfServers,simulationTime, serverList, queue, tBtwCustomerArrival, transactionTime);

    return 0;
}

void setSimulationParameters(int& sTime, int& numOfServers, int& transTime, int& tBetweenCArrival) {
    cout << endl;
    cout << "   Enter the simulation time: ";
    cin >> sTime;

    cout << "   Enter the number of servers: ";
    cin >> numOfServers;

    cout << "   Enter the transaction time: ";
    cin >> transTime;

    cout << "   Enter the average time between customer arrivals: ";
    cin >> tBetweenCArrival;
    cout << endl;
    cout << "•••••••••••••••••••••• Begin Simulation ••••••••••••••••••••••" << endl;
}

void runSimulation(int numServers, int simulationTime, serverListType& serverList, waitingCustomerQueueType& queue, int tBtwCustomerArrival, int transactionTime) {

    // Calculate the cut off for the probability of a customer arriving using the Poisson Distributoin (e^(-1/numCustomers))
    const double EulerConstant = std::exp(1.0);
    double cutOff = pow(EulerConstant, -1.0/tBtwCustomerArrival);
  
    srand(time(NULL));
    double rNum;                    // Random number using srand to compare against the cut off
    int totalNumCustomers = 0;      // Counter for the number of processed customers as they enter the queue
    bool queueChanged;              // Flag to check if the queue has changed during each tick
    int totalWaitingTime = 0;       // Cumulative waiting time of all customers

    for (int tick = 1; tick<=simulationTime; tick++){
        queueChanged = false;

        // Process a new tick for all servers -> set servers with completed transactions free!
        serverList.updateServers(cout);

        // If there are any customers in the queue, update their waiting times
        if (!queue.isEmptyQueue()){
           queue.updateWaitingQueue();
        }

        // If a new customer arrives at the current tick, add them to the waiting queue
        rNum = ((double) rand() / (RAND_MAX));
        if(rNum > cutOff){
        totalNumCustomers++;
        cout << "\x1b[31mCustomer number " << totalNumCustomers << " came at time: " << tick << "\x1b[0m"<< endl;
            customerType nextUp = customerType(totalNumCustomers, tick, 0, transactionTime);
            queue.addQueue(nextUp);
            queueChanged = true;
        }

        // If there are free servers and customers are waiting in the queue, process a customer
        for (int i = 0; i < numServers && (serverList.getFreeServerID() != -1); i++){
            if(!queue.isEmptyQueue()){
                customerType beingServed = queue.front();
                serverList.setServerBusy(serverList.getFreeServerID(), beingServed, transactionTime);
                queue.deleteQueue();
            }
        }

        // If there are more customers left in the queue, add their wait times to the cumulative waiting time and display the queue
        if (!queue.isEmptyQueue()) {
            totalWaitingTime += queue.getCount();
            if (queueChanged){
                cout << "\x1b[36mCustomers in the queue: ";
                queue.printQueue();
                cout << "\x1b[0m\n";
            }
        }
    } // End of the clock loop
    serverList.updateServers(cout);

    // If there are any customers in the queue, update their waiting times
    if (!queue.isEmptyQueue()){
        queue.updateWaitingQueue();

    }


    // Output the input data
    cout << endl << "Total simulation time: " << simulationTime << endl;
    cout << "Number of servers: " << numServers << endl;
    cout << "Transaction time: " << transactionTime << endl;
    cout << "Average time difference between customer arrival: " << tBtwCustomerArrival << endl << endl;

    // Output the calculated simulation data
    cout << "\x1b[33mTotal waiting time: " << totalWaitingTime << endl;
    cout << "Number of customers that completed a transaction: " << serverList.getNumCompletedTransactions() << endl;
    cout << "Number of customers left in the servers:" << serverList.getNumberOfBusyServers() << endl;
    cout << "Number of customers left in the waiting queue: " << queue.getCount() << endl;
    cout << "Average waiting time: " << (double)totalWaitingTime/(serverList.getNumCompletedTransactions()+serverList.getNumberOfBusyServers()+queue.getCount()) << "\x1b[0m\n";

    cout << "•••••••••••••••••••••• End Simulation ••••••••••••••••••••••" << endl << endl;
}

simulation.h


#include <fstream>
#include <string>
#include "queueAsArray.h"

using namespace std;

class customerType {
public:
    customerType(int cN = 0, int arrvTime = 0, int wTime = 0, int tTime = 0);

    void setCustomerInfo(int customerN = 0, int inTime = 0, int wTime = 0, int tTime = 0);

    int getWaitingTime() const;

    void setWaitingTime(int time);

    void incrementWaitingTime();

    int getArrivalTime() const;
    int getTransactionTime() const;

    int getCustomerNumber() const;

private:
    int customerNumber;
    int arrivalTime;
    int waitingTime;
    int transactionTime;
};
class serverType {
public:
    serverType();
    bool isFree() const;
    void setBusy();

    void setFree();

    void setTransactionTime(int t);

    void setTransactionTime();

    int getRemainingTransactionTime() const;

    void decreaseTransactionTime();

    void setCurrentCustomer(customerType cCustomer);

    int getCurrentCustomerNumber() const;
    int getCurrentCustomerArrivalTime() const;
    int getCurrentCustomerWaitingTime() const;

    int getCurrentCustomerTransactionTime() const;

private:
    customerType currentCustomer;
    string status;
    int transactionTime;
};

class serverListType {
public:
    serverListType(int num = 1);
    ~serverListType();
    int getFreeServerID() const;
    int getNumberOfBusyServers() const;
    void setServerBusy(int serverID, customerType cCustomer, int tTime);
    void setServerBusy(int serverID, customerType cCustomer);
    void updateServers(ostream& outFile);
    int getNumCompletedTransactions();
      //Return the number of completed transactions

private:
    int numOfServers;
    serverType *servers;
    int numCompletedTransactions; // New variable to count all completed transactions
};

class waitingCustomerQueueType: public queueType<customerType> {
public:
    waitingCustomerQueueType(int size = 100);
    void updateWaitingQueue();

    void printQueue();
};

simulation.cpp


#include <iostream>
#include <string>
#include <cstdlib>

#include "Simulation.h"
#include "queueAsArray.h"

using namespace std;

//*************** customerType ************
void customerType::setCustomerInfo(int customerN, int arrvTime, int wTime, int tTime) {
    customerNumber = customerN;
    arrivalTime = arrvTime;
    waitingTime = wTime;
    transactionTime = tTime;
}

customerType::customerType(int customerN, int arrvTime, int wTime, int tTime) {
    setCustomerInfo(customerN, arrvTime, wTime, tTime);
}


int customerType::getWaitingTime() const {
    return waitingTime;
}

void customerType::incrementWaitingTime() {
    waitingTime++;
}

void customerType::setWaitingTime(int time) {
    waitingTime = time;
}

int customerType::getArrivalTime() const {
    return arrivalTime;
}

int customerType::getTransactionTime() const {
    return transactionTime;
}

int customerType::getCustomerNumber() const {
    return customerNumber;
}
//**************** serverType **********

serverType::serverType() {
    status = "free";
    transactionTime = 0;
}

bool serverType::isFree() const {
    return (status == "free");
}

void serverType::setBusy() {
    status = "busy";
}

void serverType::setFree() {
    status = "free";
}

void serverType::setTransactionTime(int t) {
    transactionTime = t;
}

void serverType::setTransactionTime() {
    int time;

    time = currentCustomer.getTransactionTime();

    transactionTime = time;
}

void serverType::decreaseTransactionTime() {
    transactionTime--;
}

int serverType::getRemainingTransactionTime() const {
    return transactionTime;
}

void serverType::setCurrentCustomer(customerType cCustomer) {
    currentCustomer = cCustomer;
}

int serverType::getCurrentCustomerNumber() const {
    return currentCustomer.getCustomerNumber();
}

int serverType::getCurrentCustomerArrivalTime() const {
    return currentCustomer.getArrivalTime();
}

int serverType::getCurrentCustomerWaitingTime() const {
    return currentCustomer.getWaitingTime();
}

int serverType::getCurrentCustomerTransactionTime() const {
    return currentCustomer.getTransactionTime();
}

serverListType::serverListType(int num) {
    numOfServers = num;
    servers = new serverType[num];
    numCompletedTransactions = 0;
}

serverListType::~serverListType() {
    delete [] servers;
}

int serverListType::getFreeServerID() const {
    int serverID = -1;

    int i;

    for (i = 0; i < numOfServers; i++)
        if (servers[i].isFree())
        {
            serverID = i;
            break;
        }

    return serverID;
}

int serverListType::getNumberOfBusyServers() const {
    int busyServers = 0;

    int i;

    for (i = 0; i < numOfServers; i++)
        if (!servers[i].isFree())
            busyServers++;

    return busyServers;
}

void serverListType::setServerBusy(int serverID, customerType cCustomer, int tTime) {
    servers[serverID].setBusy();
    servers[serverID].setTransactionTime(tTime);
    servers[serverID].setCurrentCustomer(cCustomer);
}

void serverListType::setServerBusy(int serverID, customerType cCustomer) {
    int time;

    time = cCustomer.getTransactionTime();

    servers[serverID].setBusy();
    servers[serverID].setTransactionTime(time);
    servers[serverID].setCurrentCustomer(cCustomer);
}

void serverListType::updateServers(ostream& outFile) {
    int i;

    for (i = 0; i < numOfServers; i++)
        if (!servers[i].isFree()) {
            servers[i].decreaseTransactionTime();

            if (servers[i].getRemainingTransactionTime() == 0) {
                numCompletedTransactions++;
                outFile << "\x1b[32mServer number " << (i + 1)
                        << " processed customer number "
                        << servers[i].getCurrentCustomerNumber()
                        << " at time: "
                        << servers[i].
                              getCurrentCustomerArrivalTime()
                           + servers[i].
                              getCurrentCustomerWaitingTime()
                           + servers[i].
                              getCurrentCustomerTransactionTime()
                        << "\033[0m" << endl;
                servers[i].setFree();
            }
        }
}

int serverListType::getNumCompletedTransactions() {
    return numCompletedTransactions;
}

waitingCustomerQueueType::waitingCustomerQueueType(int size):queueType<customerType>(size) {
    // Default Initialization
}

void waitingCustomerQueueType::updateWaitingQueue() {
    customerType cust;

    cust.setWaitingTime(-1);
    int wTime = 0;
  
   addQueue(cust);

    while (wTime != -1)
    {
        cust = front();
        deleteQueue();

        wTime = cust.getWaitingTime();
        if (wTime == -1)
            break;
        cust.incrementWaitingTime();
        addQueue(cust);
   }
}

void waitingCustomerQueueType::printQueue(){
    for(int number = this->front().getCustomerNumber(); number <= this->back().getCustomerNumber(); number++){
        cout << number << " ";
    }
}

queueAsArray.h

//Header file QueueAsArray

#ifndef H_QueueAsArray
#define H_QueueAsArray

#include <iostream>
#include <cassert>

#include "queueADT.h"

using namespace std;

template <class Type>
class queueType: public queueADT<Type> {
public:
const queueType<Type>& operator=(const queueType<Type>&);
      //Overload the assignment operator.

bool isEmptyQueue() const;
bool isFullQueue() const;

void initializeQueue();

Type front() const;
Type back() const;

void addQueue(const Type& queueElement);
void deleteQueue();

int getCount();
      //Return the count of the queue

queueType(int queueSize = 100);
      //Constructor

queueType(const queueType<Type>& otherQueue);
      //Copy constructor

~queueType();
      //Destructor

private:
    int maxQueueSize; //variable to store the maximum queue size
    int count;        //variable to store the number of
                      //elements in the queue
    int queueFront;   //variable to point to the first
                      //element of the queue
    int queueRear;    //variable to point to the last
                      //element of the queue
    Type *list;       //pointer to the array that holds
                      //the queue elements
};

template <class Type>
bool queueType<Type>::isEmptyQueue() const {
    return (count == 0);
} //end isEmptyQueue

template <class Type>
bool queueType<Type>::isFullQueue() const {
return (count == maxQueueSize);
} //end isFullQueue

template <class Type>
void queueType<Type>::initializeQueue() {
queueFront = 0;
queueRear = maxQueueSize - 1;
count = 0;
} //end initializeQueue

template <class Type>
Type queueType<Type>::front() const {
assert(!isEmptyQueue());
return list[queueFront];
} //end front

template <class Type>
Type queueType<Type>::back() const {
assert(!isEmptyQueue());
return list[queueRear];
} //end back

template <class Type>
void queueType<Type>::addQueue(const Type& newElement) {
if (!isFullQueue()) {
        queueRear = (queueRear + 1) % maxQueueSize; //use mod
                            //operator to advance queueRear
                            //because the array is circular
        count++;
        list[queueRear] = newElement;
      }
      else
        cout << "Cannot add to a full queue." << endl;
} //end addQueue

template <class Type>
void queueType<Type>::deleteQueue() {
if (!isEmptyQueue()) {
    count--;
        queueFront = (queueFront + 1) % maxQueueSize; //use the
                        //mod operator to advance queueFront
                        //because the array is circular
      }
      else
        cout << "Cannot remove from an empty queue." << endl;
} //end deleteQueue


    //Count getter
template <class Type>
int queueType<Type>::getCount() {
return count;
} //end count getter

    //Constructor
template <class Type>
queueType<Type>::queueType(int queueSize) {
if (queueSize <= 0) {
    cout << "Size of the array to hold the queue must "
    << "be positive." << endl;
    cout << "Creating an array of size 100." << endl;

    maxQueueSize = 100;
}
else
        maxQueueSize = queueSize;   //set maxQueueSize to
                                    //queueSize

    queueFront = 0;                 //initialize queueFront
    queueRear = maxQueueSize - 1;   //initialize queueRear
    count = 0;
    list = new Type[maxQueueSize]; //create the array to
                                    //hold the queue elements
} //end constructor

    //Destructor
template <class Type>
queueType<Type>::~queueType() {
delete [] list;
} //end destructor

template <class Type>
const queueType<Type>& queueType<Type>::operator=(const queueType<Type>& otherQueue) {

if (this != &otherQueue) {

   queueFront = otherQueue.queueFront;
   queueRear = otherQueue.queueRear;

   count = otherQueue.count;
   maxQueueSize = otherQueue.maxQueueSize;

   delete [] list;
   list = new Type[otherQueue.maxQueueSize];
   assert(list != NULL);

   if (count != 0)
    for (int i = queueFront; i <= queueRear; i = (i + 1) % maxQueueSize)
      list[i] = otherQueue.list[i];
}

return *this;
} //end assignment operator

template <class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue) {

queueFront = otherQueue.queueFront;
queueRear = otherQueue.queueRear;
count = otherQueue.count;
maxQueueSize = otherQueue.maxQueueSize;

list = new Type[otherQueue.maxQueueSize];
assert(list != NULL);

for (int i = queueFront; i <= queueRear; i = (i + 1) % maxQueueSize)
    list[i] = otherQueue.list[i];

} //end copy constructor

#endif


queueADT.h

//Header file: stackADT.h

#ifndef H_queueADT
#define H_queueADT

template <class Type>
class queueADT {
public:
    virtual bool isEmptyQueue() const = 0;

    virtual bool isFullQueue() const = 0;

    virtual void initializeQueue() = 0;

    virtual Type front() const = 0;

    virtual Type back() const = 0;

    virtual void addQueue(const Type& queueElement) = 0;

    virtual void deleteQueue() = 0;
};

      
#endif


linkedQueue.h

//Header file linkedQueue.h

#ifndef H_linkedQueue
#define H_linkedQueue

#include <iostream>
#include <cassert>
#include "queueADT.h"

using namespace std;

//Definition of the node
template <class Type>
struct nodeType {
    Type info;
    nodeType<Type> *link;
};


template <class Type>
class linkedQueueType: public queueADT<Type> {
public:
    const linkedQueueType<Type>& operator=
                    (const linkedQueueType<Type>&);
      //Overload the assignment operator.

    bool isEmptyQueue() const;

    bool isFullQueue() const;
    void initializeQueue();

    Type front() const;

    Type back() const;

    void addQueue(const Type& queueElement);

    void deleteQueue();

    linkedQueueType();
    linkedQueueType(const linkedQueueType<Type>& otherQueue);
      //Copy constructor

    ~linkedQueueType();
      //Destructor

private:
    nodeType<Type> *queueFront; //pointer to the front of
                                //the queue
    nodeType<Type> *queueRear; //pointer to the rear of
                                //the queue
};
template<class Type>
linkedQueueType<Type>::linkedQueueType() {
    queueFront = NULL; //set front to null
    queueRear = NULL; //set rear to null
} //end default constructor

template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const {
    return(queueFront == NULL);
} //end

template<class Type>
bool linkedQueueType<Type>::isFullQueue() const {
    return false;
} //end isFullQueue

template <class Type>
void linkedQueueType<Type>::initializeQueue() {
    nodeType<Type> *temp;

    while (queueFront!= NULL) //while there are elements left
                               //in the queue
    {
        temp = queueFront; //set temp to point to the
                            //current node
        queueFront = queueFront->link; //advance first to
                                        //the next node
        delete temp;    //deallocate memory occupied by temp
    }

    queueRear = NULL; //set rear to NULL
} //end initializeQueue


template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement) {
    nodeType<Type> *newNode;

    newNode = new nodeType<Type>;   //create the node

    newNode->info = newElement; //store the info
    newNode->link = NULL; //initialize the link field to NULL

    if (queueFront == NULL) //if initially the queue is empty
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else        //add newNode at the end
    {
        queueRear->link = newNode;
        queueRear = queueRear->link;
    }
}//end addQueue

template <class Type>
Type linkedQueueType<Type>::front() const {
    assert(queueFront != NULL);
    return queueFront->info;
} //end front

template <class Type>
Type linkedQueueType<Type>::back() const {
    assert(queueRear!= NULL);
    return queueRear->info;
} //end back

template <class Type>
void linkedQueueType<Type>::deleteQueue() {
    nodeType<Type> *temp;

    if (!isEmptyQueue()){
        temp = queueFront; //make temp point to the
                            //first node
        queueFront = queueFront->link; //advance queueFront

        delete temp;    //delete the first node

        if (queueFront == NULL) //if after deletion the
                                //queue is empty
            queueRear = NULL;   //set queueRear to NULL
    }
    else
        cout << "Cannot remove from an empty queue" << endl;
}//end deleteQueue

template <class Type>
linkedQueueType<Type>::~linkedQueueType() {
} //end destructor

template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
                    (const linkedQueueType<Type>& otherQueue) {

} //end assignment operator

   //copy constructor
template <class Type>
linkedQueueType<Type>::linkedQueueType
                 (const linkedQueueType<Type>& otherQueue) {
}//end copy constructor

#endif