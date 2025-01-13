#ifndef GAMERULES_H
#define GAMERULES_H

#include "poker_hand.h"
#include "player.h"
using namespace std;

extern int pool_pot;

void allCards(string[], string[], string[]); // combine hand card and community card
int hand_score(const string[]);
void check_winner(vector<player> &, string[]);

#endif