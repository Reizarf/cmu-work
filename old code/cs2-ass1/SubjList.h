// write your student details in here

#ifndef _SUBJLIST_H
#define _SUBJLIST_H

#include "subject.h"

const int MAX_SUBJECT = 100;

class SubjectList
{
   public:
      SubjectList();
      ~SubjectList();
      int ReadFile();
      void PrintSubjectsInSemester(int Semester);
      int PrintSubjectDetails(char SubjectCode[]);
      int PrintCreditPoints(char SubjectID[]);

   private:
      Subject *Subjects[MAX_SUBJECT];
      int NoOfSubjects;
};

#endif

