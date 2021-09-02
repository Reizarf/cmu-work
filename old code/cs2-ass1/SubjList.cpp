// write your student details in here

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "subject.h"
#include "SubjList.h"
//#include "student.h"

using namespace std;

//const char SUBJECT_FILE[] = "subject.txt";

SubjectList::SubjectList()
{
   NoOfSubjects = 0;
}

SubjectList::~SubjectList()
{
   //delete [] Subjects;
}

int SubjectList::ReadFile()
{// Loads subject array from file
   ifstream SUBJECT_FILE;
   SUBJECT_FILE.open("subject.txt");
   int pCreditPoints = 0;
   int pSemester = 0;
   char pIDNumber[4];
   char pName[26];


   while(!SUBJECT_FILE.eof())
   {
      // getline(SUBJECT_FILE,SubjectCode);
      // getline(SUBJECT_FILE,Semester);
      SUBJECT_FILE >> pIDNumber;

      SUBJECT_FILE.getline(pName, '\n');
      SUBJECT_FILE.getline(pName,26);
      
      SUBJECT_FILE >> pCreditPoints;

      SUBJECT_FILE >> pSemester;

      Subjects[NoOfSubjects] = new Subject(pSemester,pIDNumber,pName,pCreditPoints);
      NoOfSubjects++;  
   }
   return 1;
}

void SubjectList::PrintSubjectsInSemester(int Semester)
{// Prints all subjects that match Semester
   cout<<"Subjects offered are:\n";
   for(int i=0;i<NoOfSubjects;i++){
      if(Subjects[i]->GetSemester()==Semester){
         cout<<Subjects[i]->GetIDNumber()<<'\t'<<Subjects[i]->GetName()<<endl;
      }
   }
}

int SubjectList::PrintSubjectDetails(char SubjectCode[])
{// Prints subject code & name of subject which matches SubjectCode
   
   // Prints subject code & name of subject which matches SubjectCode

   cout << "Subject Details : \n";
   string idnumber,SubjectC;
   //
   cout << NoOfSubjects << endl;
   //
   // strcpy(Subjects[i]->GetIDNumber(),idnumber);
   // strcpy(SubjectCode,SubjectC);
   for(int i = 0; i < NoOfSubjects; i++)
   {
      if(Subjects[i]->GetIDNumber() == string(SubjectCode))
      {
         cout << "ID: " << Subjects[i]->GetIDNumber() << "\nName: " << Subjects[i]->GetName() << "\nSemester: " << Subjects[i]->GetSemester() << endl;
      }
   }

   return 1;
}

int SubjectList::PrintCreditPoints(char SubjectID[4])
{
   for(int i = 0; i < NoOfSubjects;i++)
   {
      if(strcmp(SubjectID,Subjects[i]->GetIDNumber()))
      return Subjects[i]->GetCreditPoints();
   }
}