/**********************************************************************
 * list.cpp - CSCI112 - Ass3 - Contains LinkedList class definition
 * <Sullivan Frazier> <STUDENT No.> <DATE>
 **********************************************************************/

#include <cstddef>
#include "list.h"
using namespace std;


// Compare function for LinkList class - ListDataType is defined in list.h

int ListDataCmp(const ListDataType &D1,const ListDataType &D2){ return D1 > D2;}

LinkedList::LinkedList()
{
	Head = NULL;
}

LinkedList::~LinkedList()
{
	delete Head;
}

bool LinkedList::IsEmpty()
{
	return(Head==nullptr);//got this from cengage
}

void LinkedList::AddToTail(const ListDataType& newdata)
{
	nodePtr tmp, curr;

	

//	create a new customer and store the information

	tmp = new node;
	tmp->data = newdata;
	tmp->next = NULL;

//	add to the end of the list if the list is not empty

	if (Head != NULL)
	{
		curr = Head;
		while (curr->next)	// is this the end?
			curr = curr->next;
		curr->next = tmp;
	}
	else
		Head = tmp;
}

ListDataType LinkedList::RemoveFromHead()
{
	nodePtr temp;

	//if head is null return data
	if(Head == NULL)
	{
		return Head->data;
	}
	temp = Head;
	Head = Head->next;
	delete[] temp;

	return Head->data;

}

/* 
ListDataType LinkedList::RemoveFromHead(Node *root, int k)
//sourced from this website

//https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

{
	if(root == NULL)
	{//base case
		return NULL;
	}
	if(root->key > k)
	{
		root->left = RemoveFromHead(root->left,k);
		return root;
	}
	else if(root->key < k)
	{
		root->right = RemoveFromHead(root->right, k);
		return root;
	}

	//node is now to be deleted
	//if one of the children are empty

	if(root->left == NULL)
	{
		Node *temp = root->right;
		delete root;
		return temp;
	}
	else if(root->right == NULL)
	{
		Node * temp = root->left;
		delete root;
		return temp;
	}

	//if both children exist
	else
	{
		Node * successParent = root;

		//find successor

		Node * succ = root->right;
		while(succ->left != NULL)
		{
			succssParent = succ;
			succ = succ->left;
		}
		// Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
		if(successParent != root)
		{
			successParent -> left = succ->right;
		}
		else
		{
			successParent->right = succ->right;
		}
		root->key = succ -> key;

		delete succ;
		return root;
	}

}
*/

void LinkedList::Insert(const ListDataType& newdata)
{
	nodePtr curr, prev, newnode;

	curr = Head;
	prev = 0;
	while (curr && (ListDataCmp(newdata,curr->data) > 0))
	{
		prev = curr;
		curr = curr->next;
	}
	newnode = new node;
	newnode->data = newdata;	// needs copy constructor
	// new node goes after prev and before curr
	if (prev)					// if there is a previous node
		prev->next = newnode;
	else
		Head = newnode;
	newnode->next = curr;
}

void LinkedList::SetIterator()
{
	/*
	I robbed this from btree.cpp - might work?
	*/
	Current = Head;


	// if(Current != 0)
	// {
	// 	while(Current->next != 0)
	// 	{
	// 		Current = Current->next;
	// 	}
	// }

	//============================
	Current = Head;
	if (Current != 0)
		while (Current->next != 0)
			Current = Current->next;
	//================================
}

ListDataType LinkedList::Next()
{
	if(Current != NULL)
	{
		ListDataType thisvalue = Current->data;
		Current = Current->next;
		return thisvalue;
	}
	else
	{
		return Current->data;
	}
	
	//thisvalue = Current;
	
	// if(Current->right != 0)
	// {
	// 	Current = Current->right;
	// 	while(Current->)
	// }
	//if current = NULL
	
}

bool LinkedList::More()
{
	return Current != 0;
}

