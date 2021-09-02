/**********************************************************************
 * main.cpp - CSCI112 - Ass3 - main() driver for displaying text file word statistics
 * <Sullivan Frazier> <STUDENT No.> <DATE>
 **********************************************************************/
 

/*
 I declare that all material in this assessment task is my work except where
there is clear acknowledgement or reference to the work of others.

I further declare that I have compiled and agreed to the CMU Academic Integrity
Policy at the University website.
     http://www.coloradomesa.edu/student-services/documents

     Author's Name: Sullivan Frazier
     UID (700#): 700479463
     Date: April 18, 2021

Worked on with
    Stephen Marshall,
	Cavan P,
    Lauren Lewis,
    Sebastian Medina,
	Blake Kohlbrecher,
    Ethan

 */


// main.cpp - CSCI112 - Spring 2021 - S Antoun
// Student Name       : Sullivan Frazier
// Student Number     : 700-470463
// Email              : sdfrazier@mavs.coloradomesa.edu
// Date Completed     : March 31, 2021
// Description        : MRO Office
// ****** NOTE: DO NOT MODIFY ANYTHING IN THIS FILE! ******
//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "ass3.h"
using namespace std;

char Menu();

int main(){

   cout << "Welcome to the Text File Word Counter\n";
   for(;;){
      switch(Menu()){
         case 't': TestContainers();   break;
         case 'r': ReadTxtFile();      break;
         case 'd': DisplayWordStats(); break;
         case 'q': CleanUp();
                   cout << "Thanks for using Text File Word Counter\n";
                   return(1);
         default: cout << "Invalid command!\n";
      }
   }
}


char Menu(){
   char Cmd[20];
   cout << endl;
   cout << "(t)est container classes\n";
   cout << "(r)ead text file\n";
   cout << "(d)isplay word stats\n";
   cout << "(q)uit\n";
   cout << "Command > ";
   cin.getline(Cmd,20);
   cout<<endl;
   return Cmd[0];
}
