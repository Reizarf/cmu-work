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
    // for(int cardNo = 0; cardNo < cards.size(); cardNo++)
    // {
    //     cards[cardNo] = cardNo;
    //     cout << "cardNo: " << cardNo<<endl;
    //     for(int i = 0; i < cardNo;i++)
    //     {
    //         suit = cardNo/13;

    //     }
    // }

    // cout << cards.at(0);
    // cout << cards[2];
    
    cout << "cards[0] = "<<cards[0];

    suit = cards[0]/13;
    rank = cards[0]%13;
    cout << "suit: " << suit <<endl;
    cout << "rank: " << rank << endl;

    



    
    switch(rank)
    {
        case 0: //a two
            cout << "made it!:"<<endl;
        case 4:
            cout << "This is a 4 card: " <<endl;
    } 

    
    return cards;
}