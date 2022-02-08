#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
double getdata(string);
int main ()
{double ft,in,cm;
ft=getdata("feet");
in=getdata("inches");
cm=(12.*ft+in)*2.54;
cout<<ft<<" feet "<<in<<" inches="<<setprecision(2)<<fixed<<cm<<" centimeters\n";
system("pause");
return 0;
}
double getdata(string mess)
{bool done=false;   
double n=0;
string errormessage="input failed";
do   
{try
{cout<<"Enter value for "<<mess<<": ";
cin>>n;
if(cin.fail())   
throw errormessage;
if(n<0)
throw -1;
done = true;
}   
catch(int)
{cout<<"A non positive number is entered\n";
n=0;
}
catch(string errormessage)
{cout<<errormessage<<"-try again\n";
cin.clear();   
cin.ignore(100,'\n');
}
}
while (!done);
return n;
}
