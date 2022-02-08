/*
I declare that all material in this assessment task is
my work except where there is clear acknowledgement
or reference to the work of others. I further declared
that I have complied to the CMU Academic Integrity
policy at the University Website. 
https://coloradomesa.edu/student-services/documents
Authors Name:       Sullivan Frazier
UID(700#:)          700-479463
Date:               13 October 2021

Submissions that do not include the above academic 
integrity statement will not be considered.
*/


int * BruteForce(char text[], char pattern[]);
int BruteCompF();
int BruteCountF();
void BReset();


int HorCounting();
int HorComparing();
void HorReset();
int* horsPoolMatching(char pattern[], char data[]);
char* shiftTable(char pattern[]);


int* KMPSearch(char* pattern, char* text);
void computeLPSArray(char* pattern, int M, int* lps);
int KMPCompareF();
int KMPCountF();
void KMPReset();
