// Include the necessary header file.

#include <iostream>

#include "queueAsArray.h"

using namespace std;

// declare the main function

int main()

{

int userPosition;

// prompt the use to enter the position.

cout << "Enter the position of the element to be moved to the front." << endl;

// input number

cin >> userPosition;

cout<<endl;

cout << "queue: ";

queueType<int> queue(10);

// input details.

queue.addQueue(5);

queue.addQueue(11);

queue.addQueue(34);

queue.addQueue(67);

queue.addQueue(43);

queue.addQueue(55);

// call the function.

queue.moveNthFront(userPosition);

while (!queue.isEmptyQueue())

{

cout << queue.front() << " ";

// call the function.

queue.deleteQueue();

}

cout << endl;

cin.get();

return 0;

}



queueADT.h

// declare template

template <class Type>

class queueADT

{

public:

// dclare functions

virtual void initializeQueue() = 0;

virtual bool isEmptyQueue() const = 0;

virtual bool isFullQueue() const = 0;

virtual Type front() const = 0;

virtual Type back() const = 0;

virtual void addQueue(const Type& queueElement) = 0;

virtual void deleteQueue() = 0;

};



queueAsArray.h

// declare the header file.

#include <iostream>

#include <vector>

#include <cassert>

#include "queueADT.h"

using namespace std;

template <class Type>

// defintion of the function.

class queueType: public queueADT<Type>

{

public:

const queueType<Type>& operator=(const queueType<Type>&);

// declare functions

bool isEmptyQueue() const;

bool isFullQueue() const;

void initializeQueue();

Type front() const;

Type back() const;

void addQueue(const Type& queueElement);

void deleteQueue();

queueType(int queueSize = 100);

queueType(const queueType<Type>& otherQueue);

// destructor of the class

~queueType();

void moveNthFront(int n);

private:

// declare variables

int maxQueueSize;

int count;

int queueFront;

int queueRear;

Type *qList;

};

template <class Type>

// definition of the function

bool queueType<Type>::isEmptyQueue() const

{

// return value.

return (count == 0);

}

template <class Type>

// definiton of the funtion

bool queueType<Type>::isFullQueue() const

{

return (count == maxQueueSize);

}

template <class Type>

// definition of the function.

void queueType<Type>::initializeQueue()

{

queueFront = 0;

queueRear = maxQueueSize - 1;

count = 0;

}

template <class Type>

// definition of the function

Type queueType<Type>::front() const

{

assert(!isEmptyQueue());

return qList[queueFront];

}

template <class Type>

Type queueType<Type>::back() const

{

assert(!isEmptyQueue());

return qList[queueRear];

}

template <class Type>

// definition of function.

void queueType<Type>::addQueue(const Type& newElement)

{

if (!isFullQueue())

{

queueRear = (queueRear + 1) % maxQueueSize;

count++;

qList[queueRear] = newElement;

}

else

cout << "Cannot add to a full queue." << endl;

}

template <class Type>

void queueType<Type>::deleteQueue()

{

if (!isEmptyQueue())

{

count--;

queueFront = (queueFront + 1) % maxQueueSize;

}

else

cout << "Cannot remove from an empty queue." << endl;

}

template <class Type>

// definition of the function

queueType<Type>::queueType(int queueSize)

{

if (queueSize <= 0)

{

cout << "Size of the array to hold the queue must "

<< "be positive." << endl;

cout << "Creating an array of size 100." << endl;

maxQueueSize = 100;

}

else

maxQueueSize = queueSize;

queueFront = 0;

queueRear = maxQueueSize - 1;

count = 0;

qList = new Type[maxQueueSize];

}

template <class Type>

queueType<Type>::~queueType()

{

delete [] qList;

}

template <class Type>

const queueType<Type>& queueType<Type>::operator=

(const queueType<Type>& otherQueue)

{

cout << "Write the definition of the function "

<< "to overload the assignment operator." << endl;

}

template <class Type>

// definition of the function.

void queueType<Type>::moveNthFront(int y)

{

// check the condition

if (count == 0)

// display the statement on console.

cout << "The queue is empty." << endl;

else

{

// check the value

int x = (queueFront + y - 1) % maxQueueSize;

Type temp = qList[x];

// check the condition.

if (queueFront <= x)

// check the condition

for (int b = x; b > queueFront; b--)

// assign value.

qList[b] = qList[b - 1];

else{

// start the while loop

while (x != maxQueueSize - 1)

{

// check the condition.

if (x == 0)

{

// assign value.

qList[x] = qList[maxQueueSize - 1];

x = maxQueueSize - 1;

}

else

{

// assign value.

qList[x] = qList[x - 1];

x--;

}

}

// start the for loop

for (int b = x; b > queueFront; b--) qList[b] = qList[b - 1];

}

// Assign value.

qList[queueFront] = temp;

}

}