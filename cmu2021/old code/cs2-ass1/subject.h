// write your student details in here

#ifndef _SUBJECT_H
#define _SUBJECT_H

class Subject
{
   public:
      Subject();
      Subject(int pSemester,char pIDNumber[4],char pName[26],int pCreditPoints);
      int GetSemester();
      char *GetIDNumber();
      char *GetName();
      int GetCreditPoints();
   private:
      int Semester;
      char IDNumber[4];
      char Name[26];
      int CreditPoints = 0;
};



#endif

