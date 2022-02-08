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
      int GetCredits();

   private:
      int Semester;
      char IDNumber[4];
      char Name[26];
      int CreditPoints;
};


#endif

