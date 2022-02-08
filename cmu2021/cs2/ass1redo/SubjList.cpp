// write your student details in here
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "subject.h"
#include "SubjList.h"
using namespace std;

const char SUBJECT_FILE[] = "subject.txt";

//initial constructor

SubjectList::SubjectList()
{
   NoOfSubjects = 0;
}
//deconstructor
SubjectList::~SubjectList()
{
    for(int i = 0; i < NoOfSubjects; i++)//for loop to delete []
    {
        delete Subjects[i];
    }
    
}

int SubjectList::ReadFile()
{//this will laod the subject array from file
    char pID[4];//id array 
    char pName[26];//to hold their name
    int pSemester;//int for semester number 0/1/2
    int pCredits;//int num of credits
    ifstream subjFile;//create subjectfile
    subjFile.open(SUBJECT_FILE);//open subjectfile
    
    if(!subjFile)
    {
        cerr << "failed to readFile"<<endl;
        exit(1);
    }
    while(!subjFile.eof())//while not end of file
    {
        subjFile >> pID;//cin pID
        subjFile.getline(pName, '\n');//get pname until newline character
        subjFile.getline(pName, 26, '\n');
        //NEED TO COLLECT CREDITS AND SEMESTER
        subjFile >> pCredits;//cin amount of credits
        subjFile >> pSemester;//cin the semester number

        Subjects[NoOfSubjects] = new Subject(pSemester, pID, pName, pCredits);
        //enter all recorded data into a new data slot
        NoOfSubjects++;
        //increment the num of subjects
    }
    subjFile.close();
   return 1;
}

void SubjectList::PrintSubjectsInSemester(int Semester)
{
//print the subjects matching semester number entered
   for(int i = 0; i < NoOfSubjects; i++)   
   {
      if(Subjects[i]->GetSemester() == Semester)
      {
         cout << Subjects[i]->GetIDNumber() << '\t' << Subjects[i]->GetName() << endl;
      }//told me to include tab character
   }
}

int SubjectList::PrintSubjectDetails(char SubjectCode[])
{
    // Prints subject code & name of subject which matches SubjectCode
    for(int i = 0; i < NoOfSubjects; i++)
    //for(int i = 0; i < 14; i++)
    {
        //only works like this - worked with cavan
       if((Subjects[i]->GetIDNumber()[0] == SubjectCode[0]) &&
          (Subjects[i]->GetIDNumber()[1] == SubjectCode[1]) &&
          (Subjects[i]->GetIDNumber()[2] == SubjectCode[2]))
       {
          cout << "Subject Code : " << Subjects[i]->GetIDNumber() << "\nSubject Name : " << Subjects[i]->GetName() << endl;

           return 1;
       }
    }
   return 0;
}

int SubjectList::printCredits(char pSubjectIDs[][4])
{
    //Print credits based on IDnumber
    int tot = 0;
    for(int i = 0; i < NoOfSubjects; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(Subjects[i]->GetIDNumber()[0] == pSubjectIDs[j][0] && Subjects[i]->GetIDNumber()[1] == pSubjectIDs[j][1] && Subjects[i]->GetIDNumber()[2] == pSubjectIDs[j][2]){
                
                tot += Subjects[i]->GetCredits();
            }
        }
    }
    return tot;
}





