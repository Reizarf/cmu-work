//  Edited by Peyton Grattino on 10/3/20.//  Copyright © 2020 Peyton Grattino. All rights reserved.//  I declare that all material in this assessment task is my work except where there is clear acknowledge-mentorreferencetotheworkofothers. I further declare that I have complied and agreed to the CMU Academic Integrity Policy at the University website. http://www.coloradomesa.edu/student-services/documents// I worked very closely with Simon Fedderson, Sebastian Medina, and Lauren Lewis. Any similarities in my code would be due to inspiration and colaboration on this assignment.//  Author’s Name: Peyton Grattino  UID(700#): 700492650 Date: 10/3/20#include <cstdlib>#include <string>#include "subs.h"using namespace std;int GetCardName(int cardNo, char cardName[]){    int suit, rank, flag = 1;    if (cardNo > -1 && cardNo < 52)    {        suit = cardNo / 13;        rank = cardNo % 13;        switch(rank)        {             case 0: // a two                strcpy(cardName, "Two of ");                break;                     case 1: // a three                strcpy(cardName, "Three of ");                break;                     case 2: // a four                strcpy(cardName, "Four of ");                break;                     case 3: // a five                strcpy(cardName, "Five of ");                break;                     case 4: // a six                strcpy(cardName, "Six of ");                break;                     case 5: // a seven                strcpy(cardName, "Seven of ");                break;                     case 6: // a eight                strcpy(cardName, "Eight of ");                break;                     case 7: // a nine                strcpy(cardName, "Nine of ");                break;                     case 8: // a 10                strcpy(cardName, "Ten of ");                break;                     case 9: // a jack                strcpy(cardName, "Jack of ");                break;                     case 10: // a queen                strcpy(cardName, "Queen of ");                break;             case 11: // a king                strcpy(cardName, "King of ");                break;             case 12: // a ace                strcpy(cardName, "Ace of ");                break;        }        switch(suit)        {            case 0: //spades                strcat(cardName, "Spade");                break;            case 1: //clubs                strcat(cardName, "Clubs");                break;                    case 2: //Diamond                strcat(cardName, "Diamond");                break;            case 3: //hearts                strcat(cardName, "Heart");                break;        }    }    else        flag = 0;    return flag;}//This is the shuffling of the deckvoid ShuffleDeck(int deck[]){    int tempNums;    //This is making the deck    for (int i = 0; i < 52; i++){        deck[i] = i;    }    //this is shuffling the deck    for(int i = 0; i < 52; i++){        int ranNum = rand() % 52;        tempNums = deck[i];        deck[i] = deck[ranNum];        deck[ranNum] = tempNums;            }}void DealPokerHands(int deck[], int hand1[], int hand2 []){    ShuffleDeck(deck); //this is calling the deck    int tempDeck[52]; // this will make a deck that can be destroyed    int place = 0; int j = 0; //this is holding the place in the deck and counting where we are in loops    for(int i = 0; i < 10; i++){ //this will make the hands exist and deal the cards, to eatch person one at a time        hand1[j] = deck[i];        i++;        hand2[j] = deck[i];        j++;    }}int HandValue(int hand[], char type[]){    int i, n, count[13], isflush, suit, maxcnt, high, low, quality = 10;    for (i = 0; i < 13; i++)        count[i] = 0;    isflush =1;    suit = hand[0]/13;    for(i = 0; i < 5; i++){        count[hand[i] % 13]++;        if (hand[i] / 13 != suit) isflush = 0;    }    maxcnt = count[0];    for (i = 0; i < 13; i++)        if(count[i] > maxcnt) maxcnt = count[i];    i = 0;    while(count[i] == 0) i++;    low = i;    i = 12;    while (count[i] == 0) i++;    high = i;    quality = 10;    if (isflush){        if (maxcnt != 1){            quality = 4;            strcpy(type, "Flush");        }        else if (high - low == 4){            quality = 1;            strcpy(type, "Straight Flush");        }        else if (count[0] + count [1] + count[2] + count[3] + count[12] == 5){            quality = 1;            strcpy(type, "Straight Flush");        }    }    else if (maxcnt == 1){        if (high - low == 4 || count[0] + count [1] + count[2] + count[3] + count[12] == 5){            quality = 5; //straight            strcpy(type, "Straight");        }        else {            quality = 9; //high card            strcpy(type, "High Card");        }    }    else if (maxcnt == 4){        quality = 2; // four of a kind        strcpy(type, "Four of a Kind");    }    else if (maxcnt == 3){        i = low;        while (i <= high && count[i] != 2) i++;        if (i > high){            quality = 6; //3 of a kind            strcpy(type, "Three of a kind");        }        else {            quality = 3; // full house            strcpy(type, "Full house");        }    }    else{        n = 0;        for (i = low; i <= high; i++)            if (count [i] == 2) n++;        if (n == 1){            quality = 8; // two of a kind            strcpy(type, "A pair");        }        else {            quality = 7; //two pairs            strcpy(type, "Two Pairs");        }    }    return quality;}int WhoWins(int hand1[],int v1,int hand2[],int v2){    if (v1 > v2){ //If player two wins then it will return 2        return 2;    }    if (v1 < v2){ //if player one wins then it will return 1        return 1;    }    if (v1 == v2){ //Matt helpped me and showed me how to sort        for (int j = 0; j < 5; j++){            for(int i = 0; i < 5; i++){                if (hand1[i] % 13 < hand1[i+1] % 13)                    swap(hand1[i],hand1[i+1]);                if (hand1[i] % 13 == hand1[i+1] %13){                    if (hand1[i] < hand1[i+1])                        swap(hand1[i],hand1[i+1]);                }            }        }        for (int j = 0; j < 5; j++){            for(int i = 0; i < 5; i++){                if (hand2[i] % 13 < hand2[i+1] % 13)                    swap(hand2[i], hand2[i+1]);                if (hand2[i] % 13 == hand2[i+1] % 13){                    if (hand2[i] < hand2[i+1])                        swap(hand2[i],hand2[i+1]);                }            }        }    }       /*    //This is just checking if the whole thing is sorted    char temp[20];    cout << "Hand 1:" << endl; //output of hand 1    for (int i = 0; i < 5; i++){        GetCardName(hand1[i],temp);        cout << temp << endl;    }    cout << "Hand 2:" << endl; //output of hand 2    for (int i = 0; i < 5; i++){        GetCardName(hand2[i],temp);        cout << temp << endl;    }     */    if (hand1[0] > hand2[0])        return 1;    if (hand1[0] < hand2[0])        return 2;         return 0;}