/**********************************************************************
 * btree.cpp - CSCI112 - Ass3 - Contains BinaryTree class definition
 * <SULLIVAN FRAZIER> <STUDENT No.> <DATE>
 **********************************************************************/
#include <cstddef>
#include <cstring>
#include "btree.h"

using namespace std;

// Compare function for BinaryTree class - TreeDataType is defined in btree.h
int TreeDataCmp(const TreeDataType &D1,const TreeDataType &D2){ return strcmp(D1->Word,D2->Word);}

BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	Kill();
}

void BinaryTree::Kill()
{
	PostOrderDelete(root);
	root = NULL;
}

void BinaryTree::PostOrderDelete(BinaryTree::nodePtr curr)
{
	if (curr != NULL)
	{
		PostOrderDelete(curr->left);
		PostOrderDelete(curr->right);
		delete curr;
	}
}

void BinaryTree::Insert(const TreeDataType& data)
{
	InsertNode(data, root);
}

bool BinaryTree::Locate(const TreeDataType& data, TreeDataType& founddata)
{
	nodePtr foundNode = FindNode(data, root);

	if (foundNode != NULL)
	{
		founddata = foundNode->data;
		return true;
	}
	else
		return false;
}

bool BinaryTree::Delete(const TreeDataType& data, TreeDataType& deldata)
{
	nodePtr parent, prev, curr = FindNode(data, root);

	if (curr == NULL)
		return false;
	deldata = curr->data;
	parent = curr->parent;
	if (curr->left == NULL)					// no left subtree
	{
		if (curr->right == NULL)			// no children
		{
			if (parent == NULL)				// curr is root
				root = NULL;
			else if (parent->left == curr)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else								// only right subtree
		{
			if (parent == NULL)
			{
				root = curr->right;
				root->parent = NULL;
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
	else if (curr->right == NULL)			// only left subtree
	{
		if (parent == NULL)
		{
			root = curr->left;
			root->parent = NULL;
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
	else									// has both subtrees
	{
		prev = curr->left;
		while (prev->right != NULL)
			prev = prev->right;
		prev->right = curr->right;
		curr->right->parent = prev;
		if (parent == NULL)
		{
			root = curr->left;
			root->parent = NULL;
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

BinaryTree::nodePtr BinaryTree::FindNode(const TreeDataType& data, BinaryTree::nodePtr root)
{
	if (root == NULL)
		return NULL;

	int Result = TreeDataCmp(data,root->data);

	if (Result == 0)
		return root;
	if (Result < 0 && root->left != NULL)
		return FindNode(data,root->left);
	else if (Result > 0 && root->right != NULL)
		return FindNode(data,root->right);
	return NULL;
}

void BinaryTree::InsertNode(const TreeDataType& data, BinaryTree::nodePtr& root)
{
	if (root == NULL)
	{
		root = new node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
	}
	else if (TreeDataCmp(data,root->data) <= 0)
	{
		if (root->left == NULL)
		{
			root->left = new node;
			root->left->data = data;
			root->left->left = NULL;
			root->left->right = NULL;
			root->left->parent = root;
		}
		else
			InsertNode(data,root->left);
	}
	else
	{
		if (root->right == NULL)
		{
			root->right = new node;
			root->right->data = data;
			root->right->left = NULL;
			root->right->right = NULL;
			root->right->parent = root;
		}
		else
 			InsertNode(data,root->right);
 	}
}

void BinaryTree::SetIterator()
{
	curr = root;
	if (curr != 0)
		while (curr->left != 0)
			curr = curr->left;
}

TreeDataType BinaryTree::Next()
{
	TreeDataType rvalue = curr->data;

	if (curr->right != 0)			// into the right subtree
	{
		curr = curr->right;
		while (curr->left != 0)
			curr = curr->left;
	}
	else if (curr->parent == 0)		// no parent
		curr = 0;					// we are finished
	else							// find ancestor
	{
		while (curr->parent != 0
				&& (curr->parent)->left != curr)
			curr = curr->parent;
		curr = curr->parent;
	}
	return rvalue;
}

bool BinaryTree::More()
{
	return (curr != 0);
}

