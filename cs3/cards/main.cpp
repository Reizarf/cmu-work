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

int main()
{
    

    fillDeck(cards);//to fill the deck full of cards
    shuffleDeck(cards);
    getCardName(cards);

    // shuffleDeck();
    



    
    
    return 0;

}