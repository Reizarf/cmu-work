// write your student details in here

#include <iostream>
#include <cstring>
#include "subject.h"
//#include "StudList.cpp"
using namespace std;

Subject::Subject()
{// Default constructor
   int Semester = 0;
   //strcpy(IDNumber,"");
   *IDNumber=' ';
   *Name=' ';
   //strcpy(Name,"");
   int CreditPoints = 0;
}

Subject::Subject(int pSemester,char pIDNumber[4],char pName[26],int pCreditPoints)
{// Initialisation constructor
   Semester = pSemester;
   strcpy(IDNumber,pIDNumber);
   strcpy(Name,pName);
   CreditPoints = pCreditPoints;
}
//get credit points function here
int Subject::GetCreditPoints()
{
   return CreditPoints;
}
int Subject::GetSemester()
{
   return Semester;
}

char *Subject::GetIDNumber()
{
   return IDNumber;
}

char *Subject::GetName()
{
   return Name;
}

