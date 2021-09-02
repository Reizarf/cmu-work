// write your student details in here

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "StudList.h"
using namespace std;

const char STUDENT_FILE[] = "student.txt";
//constructor
StudentList::StudentList()
{
	NumOfStudents = 0;
    //start with 0
}

StudentList::~StudentList()
{
   //delete array spots here
    for(int i = 0; i < 12; i++)//delete
    {
        delete Students[i];//1-12
    }
}

int StudentList::ReadFile()
{// Loads Student array from file
    
    char pID[4];
    char pName[26];
    char pSubjectID[7][4];
    int pNumSubjects;
    //use ifstream

    //ifstream studFile

    //studFile.open(??);

    ifstream studFile;
    studFile.open(STUDENT_FILE);
    
    if(!studFile)
    {
        cerr << "there was an Error reading the studFile.\n";
        exit(1);
    }
    
    string subjects;
    
    //while loop to iterate through lines of readfile

    while(!studFile.eof())//while were not at the end of file
    {
        int counter = 0;//createa counter start @ 0


        studFile >> pID;//enter in ID
        studFile.getline(pName, '\n');//getline until newline character
        studFile.getline(pName, 26);


        studFile >> pNumSubjects;//get numSubjects
        studFile >> ws;//account for whitespace


        getline(studFile, subjects);
        
        for(int row = 0; row < pNumSubjects; row++)//iterate through num of subjects
        {
            for(int column = 0; column < 4; column++)
            {
                pSubjectID[row][column] = subjects[counter];
                counter++;
            }
        }
        Students[NumOfStudents] = new Student(pID, pName, pSubjectID, pNumSubjects);//creating datahere
        NumOfStudents++;//increase the total number of students
    }
    studFile.close();
    //close - done with reading
	return 1;
}

void StudentList::PrintStudentsInSubject(char SubjectCode[])
{
    string subjectInput, studentSubjects;
    subjectInput = SubjectCode;
    cout << "\nCurrent Enrolled Students" <<endl<< "-------------------"<<endl;
    for(int i = 0; i < NumOfStudents; i++)
    //i<12
    {
        studentSubjects = Students[i]->GetSubjectIDs();
        
        if(studentSubjects.find(subjectInput) != string::npos){
            cout << Students[i]->GetName() << endl;
            continue;
        }
    }
}
int StudentList::PrintStudentDetails(char StudentID[])
{
    // Prints name and subjects codes belonging to StudentID
    for(int i = 0; i < NumOfStudents; i++)
    {
    //Cavan had this idea of moving data like this in this IF statement
    //Moves everything simultaneously
        if((Students[i]->GetID()[0] == StudentID[0]) &&//if they ALL match
           (Students[i]->GetID()[1] == StudentID[1]) &&//cout successfully
           (Students[i]->GetID()[2] == StudentID[2]) &&
           (Students[i]->GetID()[3] == StudentID[3]) &&
           (Students[i]->GetID()[4] == StudentID[4]) &&//only if they match
           (Students[i]->GetID()[5] == StudentID[5])){
            cout << "ID: " << Students[i]->GetID() << endl;
            cout << "Name: " << Students[i]->GetName() << endl;
            cout << "Subjects Enrolled: " << endl;
            
            cout << '\t' << Students[i]->GetSubjectIDs() << endl;
            
            return 1;
        }
    }
	return 0;
}

void StudentList::PrintStudentsBasedOnCredit(int CPLimit,SubjectList &Subjects)
{
    // Prints all students doing less than CPLimit

        int studen = 0;
        int num = 0;
        for(studen = 0; studen < NumOfStudents; studen++)
        //i<12
        {
            if(Students[studen]->GetCreditPoints(Subjects) < CPLimit)//if students at curr < CPLim
            {
                cout << Students[studen]->GetName() << endl;//cout their name
                cout << Students[studen]->GetCreditPoints(Subjects) << endl;//they match the if case
                //incrememnt int num before exit
                num++;
            }
        }
        cout << endl << "there is/are " << num << " (num of) students taking less than " << CPLimit << " credits." << endl;
}

