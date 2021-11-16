#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <random>
#include "cardwork.h"

using namespace std;
//int *a = new int[55];
// vector<int> cards(52);

void TwoDFill(vector<vector<int>> &vec)
{
    for(int i = 0; i < 52; i++)
    {
        vec[i][0] = i;
        for(int j = 0; j < 4; j++)
        {
            vec[i][0] = i;
            cout << vec[i][0]<<" "<<vec[i][j] << endl;
        }   
    }  
    //the 2nd part of the array is going past 4
    
}

vector<int> fillDeck(vector<int>&cards)
{
    // vector<int> cards(52);
    for(int i = 0; i < 52;i++)
    {
        cards[i] = i;
        cout << cards[i] << endl;
    }
    return cards;
}

vector<int> shuffleDeck(vector<int>&cards)
{
    random_shuffle(cards.begin(),cards.end());
    cout << "Shuffled: "<<endl;
    for(int i = 0; i < 52;i++)
    {
        // cards[i] = i;
        cout << cards[i]<<endl;
    }
    
    return cards;
}

vector<int> getCardName(vector<int>&cards)
{
    int suit, rank, flag = 1;
    
    cout << "cards[0] = "<<cards[0];

    suit = cards[0]/13;
    rank = cards[0]%13;
    cout << "suit: " << suit <<endl;
    cout << "rank: " << rank << endl;

    



    
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
            cout << "This is a Six of ";
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
    switch(suit)
    {
        case 0:
            cout << "Spade"<<endl;
            break;
        case 1://clubs
            cout << "Clubs"<<endl;
            break;
        case 2://diamond
            cout << "Diamonds"<<endl;
            break;
        case 3://hearts
            cout <<"Hearts"<<endl;
    }

    
    return cards;
}

void TwoDCardName(vector<vector<int>> &vec)
{   
    vec[12][0]=15;

    if(vec[12][0]==15)
    {
        cout << "made it!"<<endl;
    }


}