/********************************************************
*    This is the implementation of the generalised  *
*    BinaryTree class.  Note the boolean methods    *
*    Locate and Delete. Also incorporates iterator  *
*    methods.  Requires DataType.h.         *
********************************************************/

#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
    root = 0;
}

BinaryTree::~BinaryTree()
{
    PostOrderDelete(root);
    root = 0;
}

void BinaryTree::PostOrderDelete(BinaryTree::nodePtr curr)
{
    if (curr != 0)
    {
        PostOrderDelete(curr->left);
        PostOrderDelete(curr->right);
        delete curr;
    }
}

void BinaryTree::Insert(const DataType& data)
{
    InsertNode(data, root);
}

bool BinaryTree::Locate(const DataType& data, DataType& founddata)
{
    nodePtr foundNode = FindNode(data, root);
    
    if (foundNode != 0)
    {
        founddata = foundNode->data;
        return true;
    }
    else
        return false;

}

bool BinaryTree::Delete(const DataType& data, DataType& deldata)
{
    nodePtr parent, prev, curr = FindNode(data, root);
    
    if (curr == 0)
        return false;
    deldata = curr->data;
    parent = curr->parent;
    if (curr->left == 0)                // no left subtree
    {
        if (curr->right == 0)           // no children
        {
            if (parent == 0)        // curr is root
                root = 0;
            else if (parent->left == curr)
                parent->left = 0;
            else
                parent->right = 0;
        }
        else                    // only right subtree
        {
            if (parent == 0)
            {
                root = curr->right;
                root->parent = 0;
            }
            else if (parent->left == curr)
            {
                parent->left = curr->right;
                curr->right->parent = parent;
            }
            else
            {
                parent->right = curr->right;
                curr->right->parent = parent;
            }
        }
    }
    else if (curr->right == 0)          // only left subtree
    {
        if (parent == 0)
        {
            root = curr->left;
            root->parent = 0;
        }
        else if (parent->left == curr)
        {
            parent->left = curr->left;
            curr->left->parent = parent;
        }
        else
        {
            parent->right = curr->left;
            curr->left->parent = parent;
        }
    }
    else                        // has both subtrees
    {
        prev = curr->left;
        while (prev->right != 0)
            prev = prev->right;
        prev->right = curr->right;
        curr->right->parent = prev;
        if (parent == 0)
        {
            root = curr->left;
            root->parent = 0;
        }
        else if (parent->left == curr)
        {
            parent->left = curr->left;
            curr->left->parent = parent;
        }
        else
        {
            parent->right = curr->left;
            curr->left->parent = parent;
        }
    }
    delete curr;
    return true;
}

BinaryTree::nodePtr BinaryTree::FindNode(const DataType& data,
        BinaryTree::nodePtr root)
{
    if (root == 0)
        return 0;
        
    int Result = TreeDataCmp(data,root->data);

    if (Result == 0)
        return root;
    if (Result < 0 && root->left != 0)
        return FindNode(data,root->left);
    else if (Result > 0 && root->right != 0)
        return FindNode(data,root->right);
    return 0;
}

void BinaryTree::InsertNode(const DataType& data, BinaryTree::nodePtr& root)
{
    if (root == 0)
    {
        root = new node;
        root->data = data;
        root->left = 0;
        root->right = 0;
        root->parent = 0;
    }
    else if (TreeDataCmp(data,root->data) <= 0)
    {
        if (root->left == 0)
        {
            root->left = new node;
            root->left->data = data;
            root->left->left = 0;
            root->left->right = 0;
            root->left->parent = root;
        }
        else    
            InsertNode(data,root->left);
    }
    else
    {
        if (root->right == 0)
        {
            root->right = new node;
            root->right->data = data;
            root->right->left = 0;
            root->right->right = 0;
            root->right->parent = root;
        }
        else    
            InsertNode(data,root->right);
    }
}

void BinaryTree::SetIterator()
{
    icurr = root;
    if (icurr != 0)
        while (icurr->left != 0)
            icurr = icurr->left;
}

DataType BinaryTree::Next()
{
    DataType rvalue = icurr->data;

    if (icurr->right != 0)          // into the right subtree
    {
        icurr = icurr->right;
        while (icurr->left != 0)
            icurr = icurr->left;
    }
    else if (icurr->parent == 0)        // no parent
        icurr = 0;          // we are finished
    else                    // find ancestor
    {
        while (icurr->parent != 0
                && (icurr->parent)->left != icurr)
            icurr = icurr->parent;
        icurr = icurr->parent;
    }
    return rvalue;
}       

bool BinaryTree::More()
{
    return (icurr != 0);
} 