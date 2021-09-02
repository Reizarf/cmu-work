// write your student details in here

#ifndef _STUDENT_H
#define _STUDENT_H

#include "SubjList.h"
//#include "subject.h"

class Student
{
   public:
      Student();
      Student(char pID[], char pName[], char pSubjectIDs[][4],int pNumSubjects);
      int GetCreditPoints(SubjectList &Subjects);

      char *getID();
      char *getName();
      char *getSubjectIDs();
      int getNumSubjects();

   private:
      char ID[7];
      char Name[26];
      char SubjectIDs[7][4];
      int  NumSubjects;
};


#endif

