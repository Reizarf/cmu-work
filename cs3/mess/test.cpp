// comparing apples with apples
#include <iostream>
#include <string>
using namespace std;

struct Datatype
    {
        string word;
    };


int main ()
{
  string str1 ("green apple");//original string
  string str2 ("red apple");
    
    Datatype data;//creating data object linked to struct
    data.word = str1;//setting struct word to the string

    cout << data.word;//green apple

  if (str1.compare(str2) != 0)
    cout << str1 << " is not " << str2 << '\n'; //green apple x2

  if (str1.compare(6,5,"apple") == 0)
    cout << "still, " << str1 << " is an apple\n";

  if (str2.compare(str2.size()-5,5,"apple") == 0)
    cout << "and " << str2 << " is also an apple\n";

  if (str1.compare(6,5,str2,4,5) == 0)
    cout << "therefore, both are apples\n";

  return 0;
}