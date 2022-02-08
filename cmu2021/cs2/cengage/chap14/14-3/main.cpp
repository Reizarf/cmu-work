#include <iostream> 

using namespace std;



void addFractions(int num1, int num2, int den1, int den2, 
				  int& numfrac, int& denfrac);
void subtractFractions(int num1, int num2, int den1, int den2, 
				       int& numfrac, int& denfrac);
void multiplyFractions(int num1, int num2, int den1, int den2, 
				       int& numfrac, int& denfrac);
void divideFractions(int num1, int num2, int den1, int den2, 
				     int& numfrac, int& denfrac);

void menu();
void getFraction(int choice,int fractNo, int& numerator, int& denominator);

void showResult(char operation, int num1, int num2, int den1, int den2, 
				  int numfrac, int denfrac);

int main()
{
  cout<<"Denominator must be nonzero"<<endl;
    int numerator1, numerator2, denominator1, denominator2;
    int resultnum, resultdeno;

    int choice;

    menu();
    cin >> choice;

    while (choice != 9)
    {
        cout << "For fraction 1" << endl;
        getFraction(choice, 1, numerator1, denominator1);
        cout << endl;

        cout << "For fraction 2" << endl;
        getFraction(choice, 2, numerator2, denominator2);
        cout << endl;

        switch (choice)
        {
		case 1: 
            addFractions(numerator1, numerator2,
                         denominator1, denominator2,
                         resultnum, resultdeno);
            showResult('+', numerator1, numerator2,
                            denominator1, denominator2,
                            resultnum, resultdeno);
            break;
        case 2: 
            subtractFractions(numerator1, numerator2,
                              denominator1, denominator2,
                              resultnum, resultdeno);
            showResult('-', numerator1, numerator2,
                            denominator1, denominator2,
                            resultnum, resultdeno);
            break;
		case 3: 
            multiplyFractions(numerator1, numerator2,
                             denominator1, denominator2,
                             resultnum, resultdeno);
            showResult('*', numerator1, numerator2,
                            denominator1, denominator2,
                            resultnum, resultdeno);
            break;
        case 4: 
            divideFractions(numerator1, numerator2,
                            denominator1, denominator2,
                            resultnum, resultdeno);
            showResult('/', numerator1, numerator2,
                            denominator1, denominator2,
                            resultnum, resultdeno);
            break;
        default: 
            cout << "Invalid selection." << endl;
        }
		
        menu();
        cin >> choice;
    }

    return 0;
}

void addFractions(int num1, int num2, int den1, int den2, 
				  int& numfrac, int& denfrac)
{
    numfrac = num1 * den2 + num2 * den1;
    denfrac = den1 * den2;
}

void subtractFractions(int num1, int num2, int den1, int den2, 
                       int& numfrac, int& denfrac)
{
    numfrac = num1 * den2 - num2 * den1;
    denfrac = den1 * den2;
}

void multiplyFractions(int num1, int num2, int den1, int den2, 
                       int& numfrac, int& denfrac)
{
    numfrac = num1 * num2;
    denfrac = den1 * den2;
}

void divideFractions(int num1, int num2, int den1, int den2, 
                     int& numfrac, int& denfrac)
{
    numfrac = num1 * den2;
    denfrac = num2 * den1;
}

void menu()
{
    cout << "This program performs operations on fraction. Enter" 
         << endl;
    cout << "1 : To add fraction" << endl;
    cout << "2 : To subtract fraction" << endl;
    cout << "3 : To multiply fraction" << endl;
    cout << "4 : To divide fraction" << endl;
    cout << "9 : To exit the program" << endl;
}

void getFraction(int choice, int fractNo, int& numerator, int& denominator)
{
    cout << "Enter the numerator: ";
    cin >> numerator;
    cout << endl;

    if (choice == 4 && fractNo == 2 && numerator == 0)
    {
		cout << "To divide, the second fraction must be nonzero." 
             << endl;
        while (numerator == 0)
        {
            cout << "Enter a nonzero number for the numerator: ";
            cin >> numerator;
            cout << endl;
        }
    }

    cout << "Enter the denominator: ";
    cin >> denominator;
    cout << endl;
}

void showResult(char operation, int num1, int num2, int den1, int den2, 
				int numfrac, int denfrac)
{
    cout << num1 << "/" << den1;

    switch (operation)
    {
    case '+': 
        cout << " + ";
        break;
    case '-': 
        cout << " - ";
        break;
    case '*': 
        cout << " * ";
        break;
    case '/': 
        cout << " / ";
        break;
    default: 
        cout << "Invalid operation." << endl;
    }

    cout << num2 << "/" << den2 << " = " << numfrac << "/" 
         << denfrac << endl;
}
