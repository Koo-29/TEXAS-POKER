#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

enum PlayerType
{
    HUMAN,
    BOT
};

class player
{
public:
    string name;
    string hand[2];
    int pot = 0;
    int currentBet = 0;
    bool folded = false;
    PlayerType type;

    // constructor
    player(string inputName, int inputPot, PlayerType type);
    // setter
    void set_hand(string getHand[]);

    // getter
    string get_name();
    string get_hand(int card);
    int get_pot();
};

#endif