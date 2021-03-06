/**********************************************************************
 * btree.h - CSCI112 - Ass3 - Contains BinaryTree class declaration
 * <Sullivan Frazier> <STUDENT No.> <DATE>
 **********************************************************************/
#ifndef BTREE_H_
#define BTREE_H_
#include <string>
#include <cstddef>
#include "list.h"
using namespace std;

// Definition of data contained in BinaryTree

struct WordCounterType
{
	 char *Word;//the actual data/word
	 int Count;//frequency
	LinkedList LocList;//positions of each word
};
typedef WordCounterType* WordCounterPtr;


typedef WordCounterPtr TreeDataType;   // This is a tree of pointers to WordCounterTypes.
                                       // Note: the TreeDataCmp() function also must be
                                       // defined for this data type in btree.cpp

class DataType
{
	string word = " ";
	int frequency = 0;
	//also need to store the location of word
	//dynamically allocate memory to store the location of word ex. "time" is 4th word.
};
//struct for the dataType
//include string word
//int frequency




class BinaryTree
{
	public:
		BinaryTree();
		~BinaryTree();
		void Insert(const TreeDataType&);
		bool Locate(const TreeDataType&, TreeDataType&);
		bool Delete(const TreeDataType&, TreeDataType&);
		void Kill();           // deletes tree
		void SetIterator();    // find left most node
		TreeDataType Next();   // return next data item
		bool More();           // are there any more nodes?

		struct node;
		typedef node *nodePtr;
		struct node
		{
			TreeDataType data;
			nodePtr left, right, parent;
			//datatype and name
			//

		};	
		

	private:
		nodePtr root,curr;
		
		nodePtr FindNode(const TreeDataType&, nodePtr);
		void InsertNode(const TreeDataType&, nodePtr&);
		void PostOrderDelete(nodePtr);
};

#endif
