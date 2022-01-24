/********************************************************
*    This is the interface of the generalised		*
*    BinaryTree class.  Note the boolean methods	*
*    Locate and Delete. Also incorporates iterator	*
*    methods.  Requires DataType.h.			*
********************************************************/

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "DataType.h"
#include <cstring>

int TreeDataCmp(const DataType&,const DataType&);


class BinaryTree
{
	public:
		BinaryTree();
		~BinaryTree();
		void Insert(const DataType&);
		bool Locate(const DataType&, DataType&);
		bool Delete(const DataType&, DataType&);
		void SetIterator();	// find left most node
		DataType Next();	// return next data item
		bool More();		// are there any more nodes?
		//int TreeDataCmp(const char* &char_array, const char* &char_array2);

		struct node;
		typedef node *nodePtr;
		struct node
		{
			DataType data;
			nodePtr left, right, parent;
		};		
	private:
		nodePtr root;
		nodePtr icurr;
		
		nodePtr FindNode(const DataType&, nodePtr);
		void InsertNode(const DataType&, nodePtr&);
		void PostOrderDelete(nodePtr);
};




#endif
