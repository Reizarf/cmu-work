/**********************************************************************
 * ass3.cpp - CSCI112 BTree - Implementation file for displaying text file word statistics
 * <Sullivan Frazier> <700-479463> <2021>
 **********************************************************************/




/*
/*
/*
 I declare that all material in this assessment task is my work except where
there is clear acknowledgement or reference to the work of others.

I further declare that I have compiled and agreed to the CMU Academic Integrity
Policy at the University website.
     http://www.coloradomesa.edu/student-services/documents

     Author's Name: Sullivan Frazier
     UID (700#): 700479463
     Date: April 18, 2021

Worked on with
    Stephen Marshall,
	Cavan P,
    Lauren Lewis,
    Sebastian Medina,
	Blake Kohlbrecher,
    Ethan

 */


// main.cpp - CSCI112 - Spring 2021 - S Antoun
// Student Name       : Sullivan Frazier
// Student Number     : 700-470463
// Email              : sdfrazier@mavs.coloradomesa.edu
// Date Completed     : March 31, 2021
// Description        : MRO Office
// ****** NOTE: DO NOT MODIFY ANYTHING IN THIS FILE! ******
//////////////////////////////////////////////////////////////////////////






#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "list.h"
#include "btree.h"
using namespace std;

// ******** Global Data ********

BinaryTree WordTree;

// ******** Function Prototypes ********


void CleanUp()
{
	WordTree.SetIterator();
	while(WordTree.More())
	{
		delete WordTree.Next();
		//delete wordtree.next()
		//call wordtree kill
	}
	//WordTree.Kill();
	
// set WordTree's Iterator
// while more words in tree do
//     get next WordCounterPtr
//     free data
// Kill tree
}



// ******** Menu Function Definitions ********

void TestContainers()
{
	int i; char *WrdPtr, Word[10];

	cout<<"\n **** TESTING CONTAINERS ****\n";
	cout<<"Testing IntList\n";
	LinkedList IntList;		// declare a list of ints
	cout<<"Inserted:=> ";
	for(i=0;i<10;i++)
	{
		cout<<i<<' ';
		IntList.AddToTail(i);	// insert some ints into it
	}
	cout<<endl;
	IntList.SetIterator();
	cout<<"Extracted=> ";
	while(IntList.More())
		cout<<IntList.Next()<<' ';            // print the ints in the list
	cout<<endl<<endl;

	cout<<"Testing WordTree\n";
	WordCounterPtr P1, P2;                        // declare some WordCounterPtrs
	Word[1]='\0';
	cout<<"Inserted => \n";
	for(i=0;i<100;i++)
	{
		Word[0]='A'+rand()%10;                // get a random 1 letter word
		cout<<Word<<' ';
		P1 = new WordCounterType;             // allocate new  WordCounterType
		P1->Word = new char[strlen(Word)+1];  // allocate memory for each word
		strcpy(P1->Word,Word);
		P1->Count = 1;                        // set word counter
		int WordPos = i;
		P1->LocList.Insert(WordPos);          // add the word's position to the new WordCounter
		if(WordTree.Locate(P1, P2))           // if word is already in tree then...
		{
			P2->Count++;                     // increment esisting WordCounter
			P2->LocList.AddToTail(WordPos);  // add the word's position to the existing WordCounter
			delete P1->Word;                 // get rid of not needed WordCounter
			delete P1;                       // ditto
		}
		else
			WordTree.Insert(P1);             // else not in tree! so insert WordCounter
	}
	cout<<endl;
	cout<<"Extracted=> \n";
	WordTree.SetIterator();
	while(WordTree.More())
	{
		P1 = WordTree.Next();
		cout << P1->Word;                        // print each word in the tree
		cout << '\t' << P1->Count<<"\t";
		P1->LocList.SetIterator();
		while(P1->LocList.More())
			 cout<<P1->LocList.Next()<<' ';
		cout << endl;
	}
	cout<<endl;
	cout << "here1"<<endl;
	CleanUp();                                      
	// delete tree
	
	cout<<" **** END OF TESTS ****\n\n";

}

void ReadTxtFile()
{
	string iN;
	cout << "Enter filename: "<<endl;
	cin >> iN;

	string data;
	string temporary;
	
	
	int freq = 0;
	char lower;


	ifstream inD;
	inD.open(iN);
	TreeDataType tTree;

	if(inD)
	{
		while(!inD.eof())
		{
			inD >> data;//in 1 word
			
			int len = 0;
			for(int i = 0, len = data.size();i < len; i++)
			{

				if(ispunct(data[i]))//if there's punctuation
				{
					data.erase(i--,1);//erase that punct
					len = data.size();//update data.size
				}
				
			}
			
			//if length is 0 after punctuation is dealt with, move on to next word
			if(isalpha(data[0]))
			{
				for(int k = 0; k < data.length(); k++)
			{
				//temporary += tolower(k);
				//temporary = data[k];
				lower = data[k];
				putchar(tolower(lower));
			}

			//cout << "all words: " << temporary;
		WordCounterPtr temp;
		temp = new WordCounterType;// allocate new  WordCounterType
		WordCounterPtr P2 = NULL;

		temp->Word = new char[data.length()+1]; 
		
		for(int k = 0; k < data.length(); k++)
		{
			temp->Word[k] = data[k];
		}
		

		freq+=1;
		if(!WordTree.Locate(temp,P2))//if we cant find it
		{//temp is word counter pointer
			WordTree.Insert(temp);//insert it
			temp->LocList.AddToTail(freq);
		}
		else if(WordTree.Locate(temp,P2))//if we DO find it
		{
			
			P2->LocList.AddToTail(freq);//increment frequency
			P2->Count++;
			// delete temp->Word;
			// delete temp;
		}
			}
		cout << " " << freq << endl;
		}
		inD.close();


	}

// ask user to "Enter filename: ";
// open file
// if file not found then print error msg and exit
// set counter to zero
// read word
// while not eof
//     convert word to lower case and remove any punctuation marks
//     increment counter
//     allocate new WordCounterType
//     put data in new WordCounter
//     if word is already in tree then
//         inc existing WordCounter
//         add the location (ie counter value) to existing WordCounter
//         free memory 
//     else
//         add new wordCounter to tree
//  print how many words were added to tree
//  close file
}


void DisplayWordStats()
{
	int position = 0;
	
	WordTree.SetIterator();
	//print displaywordstats themed heading here

	cout << "Display Word Stats Function Called : " << endl;
	cout << "=======================================" << endl;
	WordCounterPtr curr = WordTree.Next();
	
	while(WordTree.More())
	{
		cout << "here" <<endl;
		curr->LocList.SetIterator();//seg fault here
		cout << "here 2" <<endl;
		position = curr->LocList.Next();
		cout << "current word: " << curr->Word << endl;
		cout << "word count now: " << curr->Count << endl;
		cout << "Positions: ";
		// curr->LocList.Next() << endl;
		while(curr->LocList.More())
		{
			position = curr->LocList.Next();
			cout << position << " ";
		}
		
		curr = WordTree.Next();
		
	}
// set WordTree's Iterator
// print heading
// while more words in tree do
//     get next WordCounterPtr
//     print word
//     print word count 
//     set WordCounter's list iterator
//     while more ints in list
//         print next word location
//
	
}

