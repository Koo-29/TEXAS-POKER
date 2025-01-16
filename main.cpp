#include "include/player_action.h"
#include "include/poker_hand.h"
#include "include/bot_behavior.h"
#include <iomanip>
#include <fstream>
#include <windows.h>

string board[5];

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
void bettingRound(vector<player> &players, int &currentBet, int &pot)
{
    int activePlayers = players.size(), playerCount = 0;
    int currentPlayerIndex = 0;
    bool bettingRoundActive = true;

    while (bettingRoundActive)
    {
        player &currentPlayer = players[currentPlayerIndex];

        Sleep(1000);
        if (currentPlayer.type == HUMAN)
        {
            if (!currentPlayer.folded)
            {
                cout << currentPlayer.name << "'s turn. Current bet: " << currentBet << ". Chips: " << currentPlayer.pot << "\n";
                cout << "Your hand: " << currentPlayer.hand[0] << " " << currentPlayer.hand[1] << endl;
                cout << "Choose action: 1) Check  2) Call  3) Raise  4) Fold\n";

                int action;
                cin >> action;

                switch (action)
                {
                case 1:
                    check(currentPlayer);
                    break;

                case 2:
                    call(currentPlayer, currentBet, currentPlayerIndex);
                    break;

                case 3:
                {
                    playerCount = 1;
                    cout << "Enter raise amount: ";
                    int raiseAmount;
                    cin >> raiseAmount;
                    raise(currentPlayer, raiseAmount, currentBet, currentPlayerIndex, players);
                    continue;
                }

                case 4:
                    fold(currentPlayer);
                    activePlayers--;
                    break;

                default:
                    cout << "Invalid action. Try again.\n";
                    continue;
                }
            }
        }
        else
        {
            decideAction(currentPlayer, currentBet, currentPlayer.hand, currentPlayerIndex, players, playerCount);
        }

        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
        playerCount++;

        if (playerCount >= players.size())
        {
            bettingRoundActive = false;
            checkRaise = false;
        }

        if (activePlayers <= 1)
        {
            bettingRoundActive = false;
            checkRaise = false;
        }
    }

    cout << "Betting round ended. Pot: " << pot << "\n";
}

void preFlop(vector<player> &players, int &currentBet)
{
    initDeck();
    shuffler();
    cout << "Dealing cards to players...";
    for (int i = 0; i < players.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            players[i].hand[j] = getCard(cardCount);
        }

        players[i].currentBet += 10;
        players[i].pot -= 10;
        pool_pot += players[i].currentBet;
    }
    Sleep(1000);
    cout << "\n\n";

    currentBet += 10;

    cout << "Minimum bet is 10, you can check or raise.\n";
    bettingRound(players, currentBet, pool_pot);
}

void flop(vector<player> &players, int &currentBet)
{
    cout << "Dealing 3 community cards...";
    Sleep(1000);
    cout << "\n\n";
    board[0] = getCard(cardCount);
    board[1] = getCard(cardCount);
    board[2] = getCard(cardCount);
    cout << "The board: " << board[0] << " " << board[1] << " " << board[2] << endl;
    bettingRound(players, currentBet, pool_pot);
}

int main()
{
    int option, currentBet;
    vector<player> players;
    do
    {
        pool_pot = 0;
        currentBet = 0;
        option = initialScreen();
        switch (option)
        {
        case 1:
            playerInfo(players);
            preFlop(players, currentBet);
            flop(players, currentBet);
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