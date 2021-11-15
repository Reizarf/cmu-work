#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <random>
#include "cardwork.h"
//#include "main.cpp"

using namespace std;

vector<int> fillDeck(cards(52))
{
    vector<int> cards(52);
    for(int i = 0; i < 52;i++)
    {
        cards[i] = i;
        cout << cards[i];
    }
    return cards;
}

vector<int> shuffleDeck(cards(52))
{
    //dre rng(rd());
    int size = cards.size();

    for(int i = 0; i < size-1; i++)
    {
        int j = i + rand() % (size-i)
        swap(cards[i],cards[j]);
        cout << cards[i];
    }
    
    // shuffle(cards.begin(),card.end(),dre);
    // //need ending parameter
    // printVectorElements(cards);//stl print function?

    return cards;
}