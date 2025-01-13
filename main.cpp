#include "include/player_action.h"
#include "include/poker_hand.h"
#include <iomanip>

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

int main()
{
    int option = initialScreen();
}