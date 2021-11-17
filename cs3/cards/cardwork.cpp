#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <random>
#include "cardwork.h"

using namespace std;

char suitCheck(vector<int>&cards)
{   
    // string answerString;
    char answerChar[20];

    int suit = 0;
    for(int i = 0; i < 52; i ++)
    {
        suit = cards[0]/13;

        // suit = suit/13;
        switch(suit)
        {
            case 0:
                strcpy(answerChar,"This will be a spade or:");
                break;
                
        }
    }
    return *answerChar;
}

vector<int> fillDeck(vector<int>&cards)
{
    // vector<int> cards(52);
    for(int i = 0; i < 52;i++)
    {
        cards[i] = i;
        //cout << cards[i] << endl;
    }
    return cards;
}

vector<int> shuffleDeck(vector<int>&cards)
{
    random_shuffle(cards.begin(),cards.end());
    //cout << "Shuffled: "<<endl;
    // for(int i = 0; i < 52;i++)
    // {
    //     // cards[i] = i;
    //     cout << cards[i]<<endl;
    // }
    
    return cards;
}

string getCardRank(vector<int>&cards)
{
    string rankAnswer;

    int suit, rank, flag = 1;
    
    //cout << "cards[0] = "<<cards[0];

    // suit = cards[0]/13;
    rank = cards[0]%13;
    // cout << "suit: " << suit <<endl;
    //cout << "rank: " << rank << endl;
    
    switch(rank)
    {
        case 0: //a two
            //cout << "made it!:"<<endl;
            
            break;
        case 1:
            //three
            cout << "This is a Three of ";
            
            break;
        case 2:
            cout << "This is a Four of ";
            break;
        case 3:
            cout << "This is a Five of ";
            break;
        case 4:
            //cout << "This is a Six of ";
            rankAnswer = "Six";
            break;
        case 5:
            cout << "This is a Seven of ";
            break;
        case 6:
            cout << "This is a Eight of ";
            break;
        case 7:
            cout << "This is a Nine of ";
            break;
        case 8:
            cout << "This is a Ten of ";
            break;
        case 9:
            //jack of
            cout << "This is a Jack of ";
            break;
        case 10:
            //queen of
            cout << "This is a Queen of ";
            break;
        case 11:
            cout << "This is a King of ";
            break;
        case 12:
            cout << "This is a Ace of ";
            break;
             
    }
    
    
    return rankAnswer;
}
string getCardSuit(vector<int>&cards)
{
    string suitAnswer;
    int suit = cards[0]%13;
    //cout <<"suit = "<<suit;
    switch(suit)
    {
        case 1:
            cout << "Spade"<<endl;
            suitAnswer = "Spade";
            break;
        case 2://clubs
            // cout << "Clubs"<<endl;
            suitAnswer = "Clubs";
            break;
        case 3://diamond
            // cout << "Diamonds"<<endl;
            suitAnswer = "Diamonds";
            break;
        case 4://hearts
            // cout <<"Hearts"<<endl;
            suitAnswer = "Hearts";
            break;
    }
    return suitAnswer;
}

void TwoDCardName(vector<vector<int>> &vec)
{   
    vec[12][0]=15;

    if(vec[12][0]==15)
    {
        cout << "made it!"<<endl;
    }


}