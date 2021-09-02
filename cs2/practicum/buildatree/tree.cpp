#include <iostream>
using namespace std;

class BST
{
    struct bstN
    {
        int data;
        bstN* left;
        bstN* right;
    };
    bstN *root;
    
    //makeEmpty function
    bstN* makeEmpty(bstN*t)
    {
        if(t == NULL)
        {
            return NULL;
        }
        else
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    bstN* Insert(int x,bstN* t)
    {
        if(t == NULL)//if there is nothing in the tree
        {//go ahead and insert something, but set left and right to NULL
            t = new bstN;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
        {//if node to be inserted is less than current data
            t->left = Insert(x,t->left);
        }//insert left
        else if (x > t->data)
        {//if x is greater than data
            t->right = Insert(x,t->right);
        }//insert to the right "<"
        return t;
    }

    bstN* findMin(bstN* t)
    {
        if(t == NULL)
        {
            return NULL;
        }
        else if(t->left == NULL)
        {
            return t;
        }
        else
            return findMin(t->left);
    }
    bstN* findMax(bstN* t)
    {
        if(t == NULL)
        {
            return NULL;
        }
        else if(t->right == NULL)
        {
            return t;
        }
        else
            return findMax(t->right);
    }

    bstN* remove(int x,bstN* t)
    {
        bstN* temp;

        if(t == NULL)
        {
            return NULL;
        }
        else if(x < t->data)
        {
            t->left = remove(x,t->left);
        }
        else if(x > t->data)
        {
            t->right = remove(x,t->right);
        }
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data,t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
            {
                t = t->right;
            }
            else if(t->right = NULL)
            {
                t = t->left;
            }
            delete temp;
        }
        return t;
    }

    void inOrderTraversal(bstN* t)
    {
        if(t == NULL)
        {
            return;//return NULL but VOID
        }
        inOrderTraversal(t->left);
        cout << "t->data: " << t->data << " ";
        inOrderTraversal(t->right);
        
    }
    //insert function
    //find minimum value
    //find maximum maybe
    //remove./dequeue
    //iterator to traverse the list to remove data - inorder traversal
    bstN* find(bstN* t, int x)
    {
        if(t == NULL)
        {
            return NULL;
        }
        else if(x < t->data)
        {
            return t->left = find(t->left,x);
        }
        else if(x > t->data)
        {
            return t->right = find(t->right,x);
        }
        return t;
    }
    public:
        //bst()
        BST()
        {
            //int data = 0;
            root = NULL;
        }
        ~BST()
        {
            root = makeEmpty(root);
        }

        void insert(int x)
        {
            root = Insert(x,root);
        }

        void remove(int x)
        {
            root = remove(x,root);
        }
        void display()
        {
            inOrderTraversal(root);
            cout << endl;
        }
        void search(int x)
        {
            root = find(root,x);
        }
    
        //~bst()

        //insert function

        //remove function

        //display function

        //search./find tool
    
    
};


int main()
{
    cout << "Hello and welcome to the BST Tree: " << endl;

    BST t;

    t.insert(20);
    t.insert(10);
    t.insert(13);
    t.insert(500);
    t.insert(73);
    t.insert(42);
    t.insert(29);

    t.display();
    t.remove(42);
    t.display();


}

