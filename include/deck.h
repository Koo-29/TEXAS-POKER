#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

extern vector<string> deck;
extern int cardCount;

void initDeck();
void shuffler();
string getCard(int &);
int charToInt(string card);

#endif