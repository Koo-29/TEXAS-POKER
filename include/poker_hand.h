#ifndef POKER_HAND_H
#define POKER_HAND_H

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "deck.h"
using namespace std;
extern int const NUM_CARDS;

string high_card(const string[]);
bool a_pair(const string[]);
bool two_pair(const string[]);
bool threekind(const string[]);
bool fullhouse(const string[]);
bool fourkind(const string[]);
bool straight(const string[]);
bool flush(const string[]);
bool straightFlush(const string[]);
bool royalFlush(const string[]);

#endif