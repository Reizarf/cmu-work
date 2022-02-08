#include <bits/stdc++.h>
using namespace std;

#include "inf.h"
InfixToPostfix :: InfixToPostfix( )
{
   top = -1 ;
   strcpy ( target, "" ) ;
   strcpy ( stack, "" ) ;
   t = target ;
   s = "" ;
}
void InfixToPostfix :: getInfix ( char *str )
{
   s = str ;
}

void InfixToPostfix :: showInfix ( )
{
   cout<<"Infix Expression :"<<s<<endl;
}
void InfixToPostfix :: push ( char c )
{
   if ( top == MAX )
       cout << "\nStack is full\n" ;
   else
   {
       top++ ;
       stack[top] = c ;
   }
}
char InfixToPostfix :: pop( )
{
   if ( top == -1 )
   {
       //cout << "\nStack is empty\n" ;
       return -1 ;
   }
   else
   {
       char item = stack[top] ;
       top-- ;
       return item ;
   }
}
void InfixToPostfix :: convertToPostfix( )
{
   while ( *s )
   {
       if ( *s == ' ' || *s == '\t' )
       {
           s++ ;
           continue ;
       }
       if ( isdigit ( *s ) || isalpha ( *s ) )
       {
           while ( isdigit ( *s ) || isalpha ( *s ) )
           {
               *t = *s ;
               s++ ;
               t++ ;
           }
       }
       if ( *s == '(' )
       {
           push ( *s ) ;
           s++ ;
       }
       char opr ;
       if ( *s == '*' || *s == '+' || *s == '/' || *s == '%' || *s == '-' || *s == '$' )
       {
           if ( top != -1 )
           {
               opr = pop( ) ;
               while ( precedence ( opr ) >= precedence ( *s ) )
               {
                   *t = opr ;
                   t++ ;
                   opr = pop( ) ;
               }
               push ( opr ) ;
               push ( *s ) ;
           }
           else
               push ( *s ) ;
           s++ ;
       }
       if ( *s == ')' )
       {
           opr = pop( ) ;
           while ( ( opr ) != '(' )
           {
               *t = opr ;
               t++ ;
               opr = pop( ) ;
           }
           s++ ;
       }
   }
   while ( top != -1 )
   {
       char opr = pop( ) ;
       *t = opr ;
       t++ ;
   }
   *t = '\0' ;
}
int InfixToPostfix :: precedence   ( char c )
{
   if ( c == '$' )
       return 3 ;
   if ( c == '*' || c == '/' || c == '%' )
       return 2 ;
   else
   {
       if ( c == '+' || c == '-' )
           return 1 ;
       else
           return 0 ;
   }
}
void InfixToPostfix :: showPostfix( )
{
   cout << "\nPostfix expression : "<<target<<endl ;
}

============================================================

inf.h

#include <bits/stdc++.h>

using namespace std;
const int MAX = 50 ;
class InfixToPostfix
{
   private :
       char target[MAX], stack[MAX] ;
       char *s, *t ;
       int top ;
   public :
       InfixToPostfix( ) ;
       void getInfix ( char *str ) ;
       void showInfix () ;
       void push ( char c ) ;
       char pop( ) ;
       void convertToPostfix( ) ;
       int precedence ( char c ) ;
       void showPostfix( ) ;
       void Delete();
} ;

=======================================================

main.cpp

#include <bits/stdc++.h>
#include "inf.cpp"
using namespace std;
int main( )
{
   ///char expr[MAX] ;
  

  
  
   ifstream infile("input.txt");

   while (infile.good())
{
  
       int BUF_SIZE=100;
char expr[BUF_SIZE];
memset(expr,0,sizeof(expr));
  
if( infile.getline(expr, BUF_SIZE))
{
  
  
InfixToPostfix q ;
q.getInfix ( expr ) ;
q.showInfix();
       q.convertToPostfix( ) ;
       q.showPostfix( ) ;
}

  
  
  
}

  
}