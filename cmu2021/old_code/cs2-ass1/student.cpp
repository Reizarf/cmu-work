// write your students details in here

#include <iostream>
#include <cstring>
#include "student.h"
using namespace std;

Student::Student()
{// Default constructor
    //strcpy(ID,"");
    //strcpy(Name,"");
    *ID=' ';
    *Name=' ';
    **SubjectIDs=' ';
    NumSubjects = 0;

    // for(int i = 0;i < 7;i++)
    // {
    //     strcpy(SubjectIDs[i],"");
    //     //fills second dimension automatically

    // }
    // NumSubjects = 0;
}

Student::Student(char pID[], char pName[], char pSubjectIDs[][4],int pNumSubjects)
{// Initialisation constructor

    strcpy(pID,ID);
    strcpy(pName,Name);

    for(int i = 0; i < pNumSubjects;i++)
    {
        strcpy(SubjectIDs[i],pSubjectIDs[i]);
        
    }

    NumSubjects = pNumSubjects;
}

int Student::GetCreditPoints(SubjectList &Subjects)
{// returns no. of CPs student is enrolled in
    //compare students subject id's to
    int total = 0; 
    for(int stucounter = 0;stucounter < NumSubjects; stucounter++)
    {
        total += Subjects.PrintCreditPoints(SubjectIDs[stucounter]);
    }
    return total;
    //return total credit points
}

char *Student::getID(){
    return ID;
};

char *Student::getName(){
    return Name;
};
char *Student::getSubjectIDs(){
    //Cannot return SubjectID's alone here????
    
    return *SubjectIDs;

    
    // for(int i = 0; i < 7; i++)for(int k = 0; k < 4; k++)
    // {
    //     return strcpy(SubjectIDs[i][k];
    // }
    
    //for(int i = 0; i < )
};
int Student::getNumSubjects(){
    return NumSubjects;
};

