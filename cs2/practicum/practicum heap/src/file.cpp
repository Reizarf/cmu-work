/*
	This file contains the implementation for class file.

	Sherine Antoun
    Colorado Mesa University
*/

#include <iostream>
#include <fstream>
#include "file.h"
using namespace std;

// the default constructor should just initialise the private members to nothing

file::file()
{
	char buffer = NULL;
}


// initialisation constructor to associate file with class instance
// allocated appropriate segments on the heap.

file::file(char filename[])
{
	
}

// associated method takes a file, seeks to end, allocates memory on heap then copies
// contents into buffer

void file::associate(char filename[])
{
	
}

void readFile(char filename[])
{
	int size,length = 0;
	string buffer(size,' ');
	ifstream t;
	
	t.open("dataset.txt");//open inputfile
	t.seekg(0,std::ios::end);//look at the end
	length = t.tellg();//set length to the end
	t.seekg(0, std::ios::beg);//go back to the beginning
	buffer = new char[length];
	t.read(buffer,length);
	t.close();

	//sherine solution to reading file all in one go
	//ifstream is(".txt")
	//is.seekg(0,is.end);
	//int length = is.tellg();
	//is.seekg(0,is.beg);

	//char * buffer = new char [length];

	//is.read(buffer,length);
	//is.close();
	//delete[] buffer;



}
//read file all in one go
//implement a sizeof func