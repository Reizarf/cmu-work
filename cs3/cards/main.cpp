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
    char answerCard[20];
    string rankAnswer;//coming back

    string userRankGuess;
    string userSuitGuess;

    fillDeck(cards);//to fill the deck full of cards
    shuffleDeck(cards);

    cout << "Enter your selection: "<<endl;

    cout << "A - Guess only face value of card"<<endl
        << "B - Guess only suit of the card" <<endl
        << "C - Guess face and suit"<<endl;
    
    string userInput;
    cin >> userInput;

    while(userInput!="Q")
    {
        if(userInput == "A")
        {
            cout<<"Your guess for face value: "<<
            endl<<"ex: {Two},{Three},{Six}";
            cin >> userRankGuess;
            if(userRankGuess == getCardRank(cards))
            {
                cout << "You guessed correctly!"<<endl;
            }
            else
            {
                cout <<"You guessed incorrectly:("<<endl;
            }
        }
        if(userInput == "B")
        {
            cout<<"Your guess for the suit value: "<<
            endl<<"ex: {Spade},{Clubs},{Diamonds},{Hearts}";
            cin >>userSuitGuess;
            if(userSuitGuess == getCardSuit(cards))
            {
                cout << "You guessed correctly!"<<endl;
            }
            else
                cout <<"You guessed incorrectly";
        }
        if(userInput == "C")
        {

        }
    }
    cout << "You entered: "<<userInput<<endl;

    cout <<endl<<endl<<"The card was:  ";
    rankAnswer = getCardRank(cards);
    cout << "rankAnswer: "<<rankAnswer;
    
    // strcpy(answerCard,suitCheck(cards));


    
    return 0;

}