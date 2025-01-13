#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

extern vector<string> deck;

void initDeck();
void shuffler(int &cardCount);
string getCard();
int charToInt(string card);

#endif