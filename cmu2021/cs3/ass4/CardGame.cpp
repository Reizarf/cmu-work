//
//  CardGame.cpp
//  KMP
//
//  Created by Antoun, Sherine on 11/15/21.
//  Copyright © 2021 Antoun, Sherine. All rights reserved.
//

#include "CardGame.hpp"





/*
 
 Card Guessing Game
 Menu driven
 A- Guess only face value of card
 B- Guess only the suit of the card
 C- Guess face and suit
 Shuffle the deck before you start.
 
 */


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
 
using namespace std;

const string face[] = {"One", "Two", "Three", "Four", "Five",
                       "Six", "Seven", "Eight","Nine", "Ten",
                       "Jack", "Queen", "King"};
const string suit[] = {"Spade", "Club", "Diamond", "Heart"};

void guessFaceOnly(vector<string> d);
void guessSuitOnly(vector<string> d);
void guessFaceAndSuit(vector<string> d);
void guessFaceAndSuit(vector<string> d);
void menu();

int main()
{
    vector<string> deck;                                //Line 1

        //create the deck of cards
    for (int i = 0; i < 13; i++)
        for (int j = 0; j < 4; j++)
            deck.push_back(face[i] + " of " + suit[j]); //Line 2

    menu();                                             //Line 3
    int choice;                                         //Line 4
    cin >> choice;                                      //Line 5

    while (choice != 9)                                 //Line 6
    {
        switch (choice)                                 //Line 7
        {
        case 1:                                         //Line 8
            guessFaceOnly(deck);                        //Line 9
            break;                                      //Line 10
        case 2:                                         //Line 11
            guessSuitOnly(deck);                        //Line 12
            break;                                      //Line 13
        case 3: guessFaceAndSuit(deck);                 //Line 14
        }

        menu();                                         //Line 15
        cin >> choice;                                  //Line 16
    }

    return 0;                                           //Line 17
}

void guessFaceOnly(vector<string> d)
{
        //shuffle the deck
    random_shuffle(d.begin(), d.end());                 //Line 18

    string topCard = d[0];                              //Line 19

    string topCardFace =
         topCard.substr(0, topCard.find("of") - 1);     //Line 20
    string faceValue;

    cout << "Enter the face: ";                         //Line 21
    cin >> faceValue;                                   //Line 22
    cout << endl;                                       //Line 23

    if (topCardFace == faceValue)                       //Line 24
        cout << "You won!" << endl;                     //Line 25
    else                                                //Line 26
    {
        cout << "You lose!" << endl;                    //Line 27
        cout << "The face of the card is: "
             << topCardFace << endl;                    //Line 28
    }
}

void guessSuitOnly(vector<string> d)
{
        //shuffle the deck
    random_shuffle(d.begin(), d.end());                 //Line 29

    string topCard = d[0];                              //Line 30

    string topCardSuit = topCard.substr
                       (topCard.find("of") + 3);        //Line 31

    string suitValue;

    cout << "Enter the suit: ";                         //Line 32
    cin >> suitValue;                                   //Line 33
    cout << endl;                                       //Line 34
 
    if (topCardSuit == suitValue)                       //Line 35
        cout << "You won!" << endl;                     //Line 36
    else                                                //Line 37
    {
        cout << "You lose!" << endl;                    //Line 38
        cout << "The suit of the card is: "
             << topCardSuit << endl;                    //Line 39
    }
}

void guessFaceAndSuit(vector<string> d)
{
        //shuffle the deck
    random_shuffle(d.begin(), d.end());                 //Line 40

    string faceValue;                                   //Line 41
    string suitValue;                                   //Line 42

    cout << "Enter the face: ";                         //Line 43
    cin >> faceValue;                                   //Line 44
    cout << endl;                                       //Line 45

    cout << "Enter the suit: ";                         //Line 46
    cin >> suitValue;                                   //Line 47
    cout << endl;                                       //Line 48

    string card = faceValue + " of " + suitValue;       //Line 49

    if (d[0] == card)                                   //Line 50
        cout << "You won!" << endl;                     //Line 51
    else                                                //Line 52
    {
        cout << "You lose!" << endl;                    //Line 53
        cout << "The top card is: " << d[0] << endl;    //Line 54
    }
}

void menu()
{
    cout << "To play the game choose one of the following:"
         << endl;
    cout << "1: To guess the face value only." << endl;
    cout << "2: To guess the suit value only." << endl;
    cout << "3: To guess the both the face and suit." << endl;
    cout << "9: To end the game." << endl;
}
