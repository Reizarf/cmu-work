// write your student details in here

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "StudList.h"
//#include "student.h"
//#include "subject.cpp"
using namespace std;

const char STUDENT_FILE[] = "student.txt";

StudentList::StudentList()
{
	NumOfStudents = 0;
}

StudentList::~StudentList()
{
	
	//delete [] Students;
}

int StudentList::ReadFile()
{// Loads Student array from file
	ifstream inFile;
	NumOfStudents = 0;
	inFile.open(STUDENT_FILE);

	int pNumSubjects = 0;
	char pSubjectIDs[7][4];
	char pID[7];
	char pName[26];
	//for(int j = 0; j < 12; j++)
	while(!inFile.eof())
	{
		
		inFile >> pID;
		inFile.getline(pName,'\n');
		inFile.getline(pName,26);

		//cout << pName << endl;


		inFile >> pNumSubjects;

		for(int i = 0; i < pNumSubjects; i++)
		{
			inFile >> pSubjectIDs[i];
		}
		
		Students[NumOfStudents] = new Student(pID,pName,pSubjectIDs,pNumSubjects);
		NumOfStudents++;
	
	}

	return 1;
}

void StudentList::PrintStudentsInSubject(char SubjectCode[])
{// Prints name of all students enrolled in SubjectCode
	cout << "Enrolled Students\n"
		 <<	"-----------------\n";
		
	//int i = 0;
	//cout << Students[i] ->getSubjectIDs() << endl;
	//loop over every student in the Students list
	for(int i = 0; i < NumOfStudents; i++)
	{	
		//make a Student pointer to refer to the student being compared currently
		//Student * thisStudent = Students[i];

		// //arrow notation: access members of class pointer
		//thisStudent->getName(); //this student is teeny
		
		
		// //. notation: access members of class
		// Student thatStudent = *thisStudent; //that student is full size
		// thatStudent.getName();
		//cout << Students[i]->getName() << endl;
		//check every class they are enrolled in
		for( int j = 0; j < Students[i]-> getNumSubjects(); j++)
		{
			//if we find the one we are looking for, print, and finish (break)
			if(string(SubjectCode) == Students[i]->getSubjectIDs())
			{
				//woohoo
				
				
				
				cout << Students[i]->getName() << endl;
				cout << Students[i]->getSubjectIDs() << endl;
				break;
			}
		}
	}
}

int StudentList::PrintStudentDetails(char StudentID[])
{// Prints name and subjects codes belonging to StudentID
	// Prints name and subjects codes belonging to StudentID
	for(int i = 0; i < NumOfStudents; i++)
	{
		//!! LOOK AT THIS ONE IN THE INSTRUCTIONS!!
			//Look at the return's and the IF Statement!

			//her ehere herherhehrherher
			
			//student ID array is same as studentID
		if(strcmp(Students[i]->getID(),StudentID))
		{
			//cout <<"Here test 123" << endl;
			cout << Students[i]->getID();
			cout << Students[i]->getName();
			cout << Students[i]->getSubjectIDs();
			return 1;
		}
		
	}
	return 0;
}

void StudentList::PrintStudentsBasedOnCredit(int CPLimit,SubjectList &Subjects)
{// Prints all students doing less than CPLimit

	int i = 0;
	//first for loop goes through all of the students
	//then a check to see if the current student meets CP Limit requirement
	//print their name and the amount of credit points
	//last print the amount of students that met that category
	
	for(i = 0; i < NumOfStudents; i++)
	{
		if(Students[i] -> GetCreditPoints(Subjects) < CPLimit)
		{
			cout << Students[i] -> getName() << endl;
			cout << Students[i] -> GetCreditPoints(Subjects) << endl;
		}
	}
	//print number of students in this category
	cout << endl << "The number of students with less credits than (CPLIMIT)" << i;
}

