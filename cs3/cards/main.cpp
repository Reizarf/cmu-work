//iostream string algorithm vector stdio.h

//shuffle is stl

//guess faceonly(vector)

//guess suitOnly

//guess face and suit
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
#include "cardwork.h"
//#include "cardwork.cpp"

using namespace std;
vector<int> cards(52);

static const int column = 52;
static const int row = 2;

vector<vector<int>> vec(column,vector<int>(row,0));


int main()
{
    

    fillDeck(cards);//to fill the deck full of cards
    shuffleDeck(cards);

    cout << "Enter your selection: "<<endl;

    cout << "A - Guess only face value of card"<<endl
        << "B - Guess only suit of the card" <<endl
        << "C - Guess face and suit"<<endl;
    
    string userInput;
    cin >> userInput;
    cout << "You entered: "<<userInput<<endl;



    TwoDCardName(vec);
    TwoDFill(vec);

    cout <<endl<<endl<<"The card was:  ";
    getCardName(cards);

    
    // shuffleDeck();
    



    
    
    return 0;

}