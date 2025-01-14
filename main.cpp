#include "include/player_action.h"
#include "include/poker_hand.h"
#include <iomanip>
#include <fstream>

int initialScreen()
{
    int option;
    cout << setfill('*') << setw(30) << "Welcome to texas poker" << setw(8) << "" << endl;
    cout << setfill(' ') << "1. Start game" << endl;
    cout << "2. View rules" << endl;
    cout << "3. Exit" << endl;
    cout << setfill('*') << setw(38) << "" << endl;
    cout << setfill(' ') << "Please select an option (1-3): ";
    cin >> option;
    return option;
}

void playerInfo(vector<player> &players)
{
    string inputName;
    int pot;
    ifstream getInfo("playerInfo.txt");
    getInfo >> inputName;
    getInfo >> pot;
    if (inputName == "")
    {
        ofstream writeInfo("playerInfo.txt");
        cout << "Since you are a new player, please fill in your name: ";
        cin >> inputName;
        pot = 1000;
        writeInfo << inputName << endl;
        writeInfo << 1000 << endl;
    }
    players = {
        player(inputName, pot, HUMAN),
        player("Bot1", 1000, BOT),
        player("Bot2", 1000, BOT),
        player("Bot3", 1000, BOT),
    };
}

int main()
{
    int option;
    vector<player> players;
    do
    {
        option = initialScreen();
        switch (option)
        {
        case 1:
            playerInfo(players);
            break;

        case 2:
            cout << "Texas Poker Rules:\n";
            cout << "1. Players are dealt two private cards.\n";
            cout << "2. Community cards are revealed over three rounds: the flop, the turn, and the river.\n";
            cout << "3. Players can bet, check, raise, or fold during each round.\n";
            cout << "4. The best 5-card hand wins.\n";
            break;
        case 3:
            cout << "Exiting game... Goodbye!\n";
            break;

        default:
            break;
        }
    } while (option != 3);
}