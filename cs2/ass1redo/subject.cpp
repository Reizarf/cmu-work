#include <iostream>
#include <cstring>
#include "subject.h"
using namespace std;
//create the array and fill with empty data

//for loop it create spots IDNumber[i] and Name[i]
//ALL spots empty FIRST

Subject::Subject()
{// Default constructor
    Semester = 0;
    for(int i = 0; i < 4; i++)
    {
        IDNumber[i] = '\0';//empty
    }
    for(int i = 0; i < 26; i++){
        Name[i] = '\0';//empty
    }
    
    CreditPoints = 0;
}

Subject::Subject(int pSemester, char pIDNumber[4], char pName[26], int pCreditPoints)
{// Initialisation constructor
    Semester = pSemester;
    strcpy(IDNumber, &pIDNumber[0]);
    strcpy(Name, &pName[0]);
    CreditPoints = pCreditPoints;
}

int Subject::GetSemester()
{
   return Semester;//getter returning Semester
}

char *Subject::GetIDNumber()
{
   return IDNumber;//getter for IDNumb
}

char *Subject::GetName()
{
   return Name;//getter returning name char arr
}

int Subject::GetCredits()
{
    return CreditPoints;//getter returning creditpoints integer
}

