#include <iostream>
using namespace std;

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
        key[52] = NULL;
        data[52] = NULL;
        next = NULL;
    }
    // Node~()
    // {
    //     delete Node[];
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
        return count;
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
            while(temp != NULL)
            {
                cout <<"("<< temp->key << ","<< temp -> data <<")"<<" ->";
                temp = temp->next;
            }
        cout << endl;

        }

    }
};

int main()
{
    Queue q;
    int option,key,data;

    int lines = 51;
    ifstream inData;
    inData.open("Ass2.dat");
    

    for(int i = 0; i < lines;i++)
    //or while(!in.eof())
    double digit;
    char payment;
    {
        in >> key;//but not accounting for whitespace
        in >> data;//between the key (#'s) and payment method.


        new_node -> key = key;
        
        digit = key;

        new_node -> data = data;

        payment = data;
        q.inQueue(new_node);



        getline(cin,key,' ');//collect key input until whitespace
        

        getline(cin,data,'\n');//collect cash/card input until newline


        key.push_back(digit);//moves the content one spot back in array
        data.push_back(payment);

    }

    
    //------------------SWITCH STATEMETS ------------------//




    option = -1;
    while(option != 0)
    {
        cout << "Select which option you'd like to do" << endl;
    //option 1 insert
    //option 2 delete
    //cin option;

    //Node n1 =new node;  
    //This scope is global - AND NEEDS TO BE DESTROYED AS WELL
    
        Node * new_node = new Node();
        
        switch(option)
        {
            case 0:
                break;
            case 1:
                cout << "Enter function called." << endl <<
                "Reading Ass2.dat - " << endl;
                
                //

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
                q.display();
                cout << endl;
                break;
            // case 6:
            //     cout << "License renewal selection called - " << endl;
            //     break;
            // case 7:
            //     cout << "Registration renewal selection called - " << endl;
            //     break;

            case 9:
                system("cls");
                break;

            default:
                cout << "Enter your selection: " << endl;
    }
    }
}

    