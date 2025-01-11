#include <iostream>
using namespace std;

class player
{
private:
    string name;
    string hand[2];
    int pot;
    bool folded;
public:
    // constructor
    player(string inputName, int inputPot);
    // setter
    void set_hand(string getHand[]);

    // getter
    string get_name();
    string get_hand(int card);
    int get_pot();
};