#ifndef PLAYER_ACTION_H
#define PLAYER_ACTION_H

#include "gameRules.h"
#include "player.h"
#include <iostream>
using namespace std;

extern bool err;
extern bool checkRaise;

void fold(player &);
void check(player &);
void raise(player &, int, int &, int &, vector<player>);
void call(player &, int &, int &);

#endif