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
    cout << setfill('=') << setw(38) << "" << endl;
    cout << setfill(' ') << setw(30) << "Welcome to texas poker" << endl;
    cout << setfill('=') << setw(38) << "" << endl;
    cout << setfill(' ') << "1. Start game" << endl;
    cout << "2. View rules" << endl;
    cout << "3. Exit" << endl;
    cout << setfill('-') << setw(38) << "" << endl;
    cout << setfill(' ') << "Please select an option (1-3): ";
    cin >> option;
    return option;
}

void playerInfo(vector<player> &players)
{
    string inputName;
    int pot;
    ifstream getInfo("playerInfo.txt");
    getInfo >> inputName >> pot;
    getInfo.close();
    if (inputName == "")
    {
        ofstream writeInfo("playerInfo.txt");
        cout << "Since you are a new player, please fill in your name: ";
        cin >> inputName;
        pot = 1000;
        writeInfo << inputName << endl;
        writeInfo << 1000 << endl;
        writeInfo.close();
    }
    players.push_back(player(inputName, pot, HUMAN));

    ifstream getBotInfo("botInfo.txt");
    while (getBotInfo >> inputName >> pot)
    {
        if (!inputName.empty())
            players.push_back(player(inputName, pot, BOT));
    }
    getBotInfo.close();
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
                do
                {
                    cout << currentPlayer.name << "'s turn:" << endl;
                    cout << "Current Bet: " << currentBet << endl;
                    cout << "Your hand: " << currentPlayer.hand[0] << " " << currentPlayer.hand[1] << endl;
                    cout << "Your pot: " << currentPlayer.pot << "\n\n";
                    cout << "Choose action:\n";
                    cout << "1. Check \n2. Call \n3. Raise \n4. Fold\n\n";
                    cout << "Choose your action: ";

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
                        playerCount = 0;
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
                } while (err);
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
    cout << setfill('=') << setw(38) << "" << endl;
    cout << setfill(' ') << setw(22) << "Pre Flop" << endl;
    cout << setfill('=') << setw(38) << "" << endl;
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
    cout << "\n";

    currentBet += 10;

    cout << "Minimum bet is 10, you can check or raise.\n\n";
    bettingRound(players, currentBet, pool_pot);
}

void flop(vector<player> &players, int &currentBet)
{
    cout << setfill('=') << setw(38) << "" << endl;
    cout << setfill(' ') << setw(22) << "The Flop" << endl;
    cout << setfill('=') << setw(38) << "" << endl;
    cout << "Dealing 3 community cards...";
    Sleep(1000);
    cout << "\n\n";
    board[0] = getCard(cardCount);
    board[1] = getCard(cardCount);
    board[2] = getCard(cardCount);
    cout << "The board: " << board[0] << " " << board[1] << " " << board[2] << endl;
    bettingRound(players, currentBet, pool_pot);
}

void turn(vector<player> &players, int &currentBet)
{
    cout << setfill('=') << setw(38) << "" << endl;
    cout << setfill(' ') << setw(22) << "The Turn" << endl;
    cout << setfill('=') << setw(38) << "" << endl;
    cout << "Dealing 1 community cards...";
    Sleep(1000);
    cout << "\n\n";
    board[3] = getCard(cardCount);
    cout << "The board: " << board[0] << " " << board[1] << " " << board[2] << " " << board[3] << endl;
    bettingRound(players, currentBet, pool_pot);
}

void river(vector<player> &players, int &currentBet)
{
    cout << setfill('=') << setw(38) << "" << endl;
    cout << setfill(' ') << setw(23) << "The river" << endl;
    cout << setfill('=') << setw(38) << "" << endl;
    cout << "Dealing 1 community cards...";
    Sleep(1000);
    cout << "\n\n";
    board[4] = getCard(cardCount);
    cout << "The board: " << board[0] << " " << board[1] << " " << board[2] << " " << board[3] << " " << board[4] << endl;
    bettingRound(players, currentBet, pool_pot);
}

void updateInfo(vector<player> &players)
{
    ofstream updatePlayer("playerInfo.txt", ios::trunc);
    ofstream updateBot("botInfo.txt", ios::trunc);
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i].type == HUMAN)
            updatePlayer << players[i].name << " " << players[i].pot << endl;
        else
            updateBot << players[i].name << " " << players[i].pot << endl;
    }
    updatePlayer.close();
    updateBot.close();
}

int main()
{
    int option, currentBet;
    vector<player> players;
    do
    {
        pool_pot = 0;
        currentBet = 0;
        players.clear();
        option = initialScreen();
        switch (option)
        {
        case 1:
            playerInfo(players);
            preFlop(players, currentBet);
            flop(players, currentBet);
            turn(players, currentBet);
            river(players, currentBet);
            cout << setfill('=') << setw(38) << "" << endl;
            cout << setfill(' ') << setw(22) << "Showdown" << endl;
            cout << setfill('=') << setw(38) << "" << endl;
            check_winner(players, board);
            updateInfo(players);
            break;

        case 2:
            cout << "Texas Poker Rules:\n";
            cout << "1. Players are dealt two private cards.\n";
            cout << "2. Community cards are revealed over three rounds: the flop, the turn, and the river.\n";
            cout << "3. Players can bet, check, raise, or fold during each round.\n";
            cout << "4. The best 5-card hand wins.\n";
            Sleep(2000);
            break;
        case 3:
            cout << "Exiting game... Goodbye!\n";
            break;

        default:
            break;
        }
    } while (option != 3);
}