#include <iostream>

using namespace std;

const int cashTime = 30;
const int chequeTime = 10;

//--------------------------CUSTOMER NODE---------------------------

struct CustomerNode
{
    int customerNumber;
    int arrivalTime;
    int waitingTime;
    int transactionTime;
    char paymentType;

    CustomerNode* next;
};

//--------------------CUSTOMER LINKED LIST CLASS--------------------

class CustomerLinkedList
{
public:

    // CONSTRUCTOR
    CustomerLinkedList()
    {
        head = NULL;
        tail = NULL;
    };

    // DESTRUCTOR
    ~CustomerLinkedList(){};

    // FUNCTION TO DETERMINE WHETHER THE LINKED LIST IS EMPTY
    bool lineEmpty()
    {
        if (head == NULL && tail == NULL)
        return true;

        else
        return false;
    };


    // FUNCTION WHICH WILL ADD A NODE TO THE BACK OF THE QUEUE
    void lineEnqueue(int custNum, int aTime, int wTime, int tTime, char type)
    {
        CustomerNode *ptr = new CustomerNode; // Creates new node, stores its address in ptr.

        if (ptr == NULL)
        {
            cout << "OVERFLOW." << endl;
            return;
        }

        else
        {
            ptr -> customerNumber = custNum;
            ptr -> arrivalTime = aTime;
            ptr -> waitingTime = wTime;
            ptr -> transactionTime = tTime;
            ptr -> paymentType = type;

            if (head == NULL) // If the list is empty, we are inserting the first node, which head and tail both point to. The next node's address will be NULL.
            {
                head = ptr;
                tail = ptr;

                head -> next = NULL;
                tail -> next = NULL;

                cout << "Customer " << head -> customerNumber + 1 << " arrives at minute " << tail -> arrivalTime << " and is the only one in line. (" << head -> paymentType << ")" << endl;

                return;
            }

            else // If the list is not empty, we need to move the new node to the back of the line.
            {
                tail -> next = ptr;
                tail = ptr;
                tail -> next = NULL;

                cout << "Customer " << tail -> customerNumber + 1 << " arrives at minute " << tail -> arrivalTime << " and has joined the back of the line. (" << tail -> paymentType << ")" << endl;
            }
        }
    };


    // FUNCTION TO DEQUEUE A CUSTOMER FROM THE FRONT OF THE LINE
    void lineDequeue()
    {
        CustomerNode *headNode = head;

        if (headNode != NULL)
        {
            cout << "Customer " << head -> customerNumber + 1 << " is now leaving." << endl;

            head = headNode -> next;

            delete headNode;
        }

        if (head != NULL)
        cout << "Customer " << head -> customerNumber + 1 << " is now at the front of the line. (" << head -> paymentType << ")" << endl;
    };


    // FUNCTION TO DISPLAY THE CURRENT CUSTOMER BEING SERVED
    void showFront()
    {
        if (head == NULL)
        {
            return;
        }

        else
        cout << "Customer " << head -> customerNumber + 1 << " is being served. (" << head -> paymentType << ") (" << head -> waitingTime + 1 << " minutes in store)" << endl;
    };


    // FUNCTION TO DISPLAY THE LINKED LIST
    void displayLine()
    {
        CustomerNode *ptr = head;

        if (head == NULL)
        {
            return;
        }

        else
        {
            while (ptr != NULL)
            {
                cout << "Customer " << ptr -> customerNumber + 1 << endl;
                ptr = ptr -> next;
            }
        }
    };

    // FUNCTION TO INCREMENT WAIT AND SERVICE TIME FOR ALL CUSTOMERS IN THE LINE
    void waitTime()
    {
        CustomerNode *e = head; // Creates a new pointer to the front node.

        if (e == NULL) // If head doesn't exist, end the function.
        return;

        else
        {
            e -> transactionTime += 1; // Increment the transaction time for the front node.

            if (e -> transactionTime == cashTime) // Dequeue if they've been served for 30 minutes.
            {
                lineDequeue();
            }

            else if ((e -> transactionTime) == chequeTime && (e -> paymentType) == 'C') // Send to the back of the line if they've been served 10 minutes and have a cheque.
            {
                cheque();
            }

            while (e != NULL) // For every node in the line, increment their total waiting time by one.
            {
                e -> waitingTime += 1;
                e = e -> next;
            }
        }
    };


    // FUNCTION TO MOVE THE FRONT NODE TO THE BACK OF THE LINE.
    void cheque()
    {
        CustomerNode *temp = head; // Creates a new pointer to the front node.
        temp -> paymentType = '$'; // Changes the front pointer's payment type to cash (this function will only be called if the front node has a cheque).

        if (head == tail) // They are the only customer in line, handle the customer like a cash payment.
        {
            cout << "Even though Customer " << head -> customerNumber + 1 << " has a check, they are the only person in line and are served immediately." << endl;
            return;
        }

        cout << "Customer: " << head -> customerNumber + 1 << " had to move to the back of the line." << endl;

        head = temp -> next; // Set the new head to the second node.
        temp -> next = NULL; // The first node no longer points to the second node.

        tail -> next = temp; // Add the first node to the end of the tail.
        tail = temp; // Sets the new end of the line.
    };


private:
    CustomerNode* head;
    CustomerNode* tail;
};
