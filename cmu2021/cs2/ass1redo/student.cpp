// write your students details in here

#include <iostream>
#include <cstring>
#include "student.h"
using namespace std;
//create all slots of data in array and initialize to null or Stephen likes '\0'
Student::Student()
{// Default constructor
    for(int i = 0; i < 6; i++)//iterate through slots
    {
        ID[i] = '\0';//set all slots to 0 or null
    }
    
    for(int i = 0; i < 26; i++)//iterate through slots
    {
        Name[i] = '\0';//set all slots to 0 or null
    }
    
    for(int i = 0; i < 7; i++)//iterate through slots
    {
        for(int j = 0; j < 4; j++)
        {
            SubjectIDs[i][j] = '\0';//set all slots to 0 or null
        }
    }
    NumSubjects = 0;//int declared to 0
}

Student::Student(char pID[], char pName[], char pSubjectIDs[][4], int pNumSubjects)
{// Initialization constructor
    strcpy(ID, &pID[0]);//copying string from id to pId
    strcpy(Name, &pName[0]);//strcpy name to pName
    NumSubjects = pNumSubjects;//same
     

    //NEED A NESTED FOR LOOP

    //for int i < pNumSubjects
    //for int j < 4
    //subjectIDs [i (everytime)][j(once)]

    for(int i = 0; i < pNumSubjects; i++)//i<12 for loop
    {
        for(int j = 0; j < 4; j++)//4 different spots
        {
            SubjectIDs[i][j] = pSubjectIDs[i][j];
        }
    }
}

int Student::GetCreditPoints(SubjectList &Subjects)
{
    return Subjects.printCredits(SubjectIDs);
}

char* Student::GetID()
{
    return ID;//getter that returns Id
}

char* Student::GetName()
{
    return Name;//getter that returns student name
}

char* Student::GetSubjectIDs()
{
    return *SubjectIDs;//getter that returns subjectID
}

int Student::GetNumSubjects()
{
    return NumSubjects;//getter that returns  number of subjects
}
