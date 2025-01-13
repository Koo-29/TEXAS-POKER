#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class player
{
public:
    string name;
    string hand[2];
    int pot;
    int currentBet;
    bool folded = false;

    // constructor
    player(string inputName, int inputPot);
    // setter
    void set_hand(string getHand[]);

    // getter
    string get_name();
    string get_hand(int card);
    int get_pot();
};

#endif