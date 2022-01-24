// write your student details in here

#ifndef _STUDLIST_H
#define _STUDLIST_H

#include "student.h"
#include "SubjList.h"
const int MAX_STUDENT = 100;


class StudentList
{
   public:
      StudentList();
      ~StudentList();
      int ReadFile();
      void PrintStudentsInSubject(char SubjectCode[]);
      int PrintStudentDetails(char SubjectCode[]);
      void PrintStudentsBasedOnCredit(int CPLimit,SubjectList &Subjects);

   private:
      Student *Students[MAX_STUDENT];
      int NumOfStudents;

};


#endif


