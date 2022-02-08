//
//  CardGame.h
//
//  Created by Antoun, Sherine on 11/15/21.
//  Copyright © 2021 Antoun, Sherine. All rights reserved.
//

/*
 
 Card Guessing Game
 Menu driven
 A- Guess only face value of card
 B- Guess only the suit of the card
 C- Guess face and suit
 Shuffle the deck before you start.
 
 */


#ifndef CardGame_h
#define CardGame_h

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>


void guessFaceOnly(vector<string> d);
void guessSuitOnly(vector<string> d);
void guessFaceAndSuit(vector<string> d);
void menu();


#endif /* CardGame_h */
