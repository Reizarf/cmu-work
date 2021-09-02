#include <chrono>
#include <iostream>
using namespace std;
#include <fstream>


//Customer w/ Cash
//-arrive
//Hop in line, (line delay), +30s. transaction
//-Out


//Line delay = Other customers in line, +/- 30s waiting on each other


//Customer w/ Checkque
//-Arrive
//Hop in line, (line delay) and then +10s. to stamp checkque
//-Out

//google chrono library - use to manage time.

class Node
{
    public:
    int key,data;
    Node * next;
    //key = cash or card
    //data = amount
    Node()
    {
        int key[50] = {0};
        char data[50] = {};
        int timestamp[50] = {0};

        next = NULL;
    }
    // Node~()
    // {
    //     delete Node;
    // }

    Node(int k,int d)
    {
        key = k;
        data = d;
        next = NULL;
    }

};
//Node comprises of Key, Data, and tail to the next node
//Head
//Key = pointer or head of data
//Data = content

class Queue
{
    public:
        Node * front;
        Node * rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    //front, end, check if, insert, delete,etc;
    bool checkIfEmpty()
    {
        if(front == NULL && rear && NULL)
        {
            return true;
            
        }
        else
        {
            return false;
        }
    }

    bool checkIfNodeExists(Node *n)
    {
        Node *temp = front;//temporary pointer to the front to move when inserting
        bool exist = false;
        while(temp != NULL)
        {
            if(temp->key == n->key)//access the key of n1
            {                      //temp is pointing to n1 rn
                exist = true;      //
                break;
            }
            temp = temp -> next;//temp is pointing to n1, now pointing to n2

        }
        return exist;//exist == true;
    }

    void inQueue(Node *n)
    {
        if(checkIfEmpty())
        {
            front = n;
            rear = n;
            cout << "Node inserted correctly" << endl;

        }
        else if(checkIfNodeExists(n))
        {
            cout<< "Node already exists with this Key Value" << endl;
            cout <<"Enter a different Key value" << endl;

        }
        else
        {
            rear->next = n;
            rear = n;
            //top = n;

            cout << "Node inserted successfully"<< endl;
        }
    }
    //remove from
    Node* deQueue(Node *n)
    {
        Node *temp = NULL;
        if(checkIfEmpty())
        {
            cout << "empty list" << endl;
            return NULL;
        }
        else
        {
            if(front==rear)
            {
                temp = front;
                front = NULL;
                rear = NULL;   //empty and replaces with null
                return temp;

            }
            else
            {
                temp = front;
                front = front -> next;
                return temp;
            }

        }
    }
    int count()
    {
        int count = 0;
        Node *temp = front;

        while(temp != NULL)
        {
            count++;
            temp = temp -> next;//move and check again
        }
        return count = 50;
    }

    void display()
    {
        if(checkIfEmpty())
        {
            cout << "empty list" << endl;

        }
        else
        {
            cout <<"All values in the list are: " << endl;
            Node *temp = front;
            for(int k = 0; k < 50; k++)
            {
                cout <<"("<< temp->key << ","<< temp -> data <<")"<<" ->";
                temp = temp->next;
                //cout << "customer #" << temp->key << endl << "payment method: " << endl;
            }
        cout << endl;

        }

    }
};

void ReadFile()
{
    int key;
    char data;

    double digit;
    char payment;
    int lines = 50;
    ifstream inD;
    inD.open("Ass2.dat");
    Node * new_node = new Node();
    for(int i = 0; i < lines; i++)
    {
        inD >> key;//time counter for customer
        inD >> ws;//including whitespace between
        inD >> ws;//filler char
        inD >> ws;//filler char - not saving any ws. 
        inD >> data;//payment method
        
        new_node -> key = key;
        
        digit = key;

        new_node -> data = data;

        payment = data;
        cout << endl <<digit << endl<< payment<< endl;
    }
}

void PutInLine(char key, int data)
{

//     int customer,time = 0;
//     //start ticking a timer counter
//     // check if digit matches time
//     // then start the timer for service
//     // other customers queue'd after, hop in line and wait
//     // once service is completed, if there's a customer in line, serve them
//     // don't forget if they're card it takes 40 seconds.


    //feed digits into an array
    int timestamp[50] = {NULL};
    for(int fill = 0; fill < 50; fill++)
    {
        timestamp[fill] = 0;
    }
    int time = 0;
    for(int i = 0; i < 50; i++)
    {
        cout << data << endl << endl;
        //cout << timestamp[i];
        //timestamp[i] = data;
        //timestamp[i]=data;
        cout << timestamp[i];
    }

    int j = 0;
    for(int j = 0; j < 50;j++)
    {
        if(timestamp[j] == time)
        {
            
            cout << "000001" << endl;
            cout << time << ": " <<
            "customer # " << timestamp[j] << " is currently being served" << endl;
        }
        if(timestamp[j]+30 > timestamp[j+1])//) + (30-(timestamp[j+1] - timestamp[j])))
        {
            timestamp[j+1] += (30-(timestamp[j+1] - timestamp[j]));
            //cout << "000002" << endl;
            cout << time <<": " << "customer # " << timestamp[j] << "is currently beind served" << endl;
            
        }
        else
        {
            j++;
        }
        time++;
        //j++;
    }
}

int main()
{
    Node * new_node = new Node();
    Queue q;
    int option,key;

    double data;//variable used for timer
    
    char payment;//variable used for payment method

    int lines = 50;
    ifstream inD;
    inD.open("Ass2.dat");
    
    cout <<"here test" << endl;

    option = -1;
    while(option != 0)
    {
        //cout << "Select which option you'd like to do" << endl;
        
        
        switch(option)
        {
            case 0:
                break;
            case 1:
                cout << "Enter function called." << endl <<
                "Reading Ass2.dat - " << endl;
                cout << "void func" << endl;
                PutInLine(data,key);
                //ReadFile();
                
                break;

            case 2:
                cout << "Delete function called."<<endl<<
                endl;
                new_node = q.deQueue(new_node);//check if we pass it new node here???
                cout << "Removed value is: ( "<<new_node->key<<","<<new_node->data<<")";
                delete new_node;
                cout << endl;
        
            case 3:
                cout << "checkIfEmpty function called - " << endl;
                if(q.checkIfEmpty())
                {
                cout << "Queue is empty" << endl;

                }
                else
                {
                    cout << "Queue is NOT empty" << endl;
                }
                break;
        
            case 4:
                cout << "Count function called - " << endl;
                cout << "No. of nodes in the Queue: "<< q.count() << endl;
                break;

            case 5:
                cout <<"Display function called - " << endl;
                ReadFile();
                cout << endl;
                break;
            // case 6:
            //     cout << "License renewal selection called - " << endl;
            //     break;
            // case 7:
            //     cout << "Registration renewal selection called - " << endl;
            //     break;
            case 8:
                cout << "void func" << endl;
                PutInLine(data,key);
            case 9:
                system("cls");
                break;

            default:
                cout << "1) To start the line" << endl <<
                "2) to delete the array" << endl << "3)To check if queue is empty"<< endl<<
                "4)To count the number of nodes in the array" << endl << "5) to Display ALL" << endl;
                cin >> option;
                break;
             
        }
        cout << "Enter a selection - " << endl;
        cin >> option;
    }
}

    