#include <iostream>
using namespace std;

void TicTacToe();
void BatTicTacToe();
void choose(int);
void win();
void Newgame();
void alchemist(int playerNumber);
void paladin(int playerNumber);

int grid[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };   // Array for the board
int won = 10;                                   // Winning player
bool W = false;                                 // Winner status
char choice;                                    // Mode selection
char arche1, arche2, ch1, ch2, pick;            // Character choices and abilities

int main() {
top:
    cout << "Welcome to Battle Tic Tac Toe\n";
    cout << "Do you want to play classic or battle Tic Tac Toe?\n";
    cout << "Press 1 for classic or 2 for battle: ";
    cin >> choice;

    if (choice == '1') {
        cout << "Let's Play Classic Tic Tac Toe!\n";
        Newgame();
        TicTacToe();

        for (int i = 0; i < 5; i++) {
            if (!W) {
                choose(0);      // Player 1's move
                TicTacToe();
                win();
                if (W) break;

                if (i == 4) {
                    cout << "\nIt's a tie\n";
                    won = 11;
                    break;
                }

                choose(-1);     // Player 2's move
                TicTacToe();
                win();
                if (W) break;
            }
        }

        cout << "\nPlay again? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') goto top;
        return 0;
    }

    else if (choice == '2') {
        cout << "You have chosen Battle Tic Tac Toe.\n";

        cout << "Player 1, choose an archetype (A for Alchemist, P for Paladin): ";
        cin >> arche1;

        cout << "Player 2, choose an archetype (A for Alchemist, P for Paladin): ";
        cin >> arche2;

        cout << "Player 1, choose a character (A-Z, a-z, ?, !, *, ~, $, %, #): ";
        cin >> ch1;

        cout << "Player 2, choose a character (A-Z, a-z, ?, !, *, ~, $, %, #): ";
        cin >> ch2;

        Newgame();
        BatTicTacToe();

        for (int i = 0; i < 5; i++) {
            if (!W) {
                cout << "\nPlayer 1, enter 'b' to move or 'c' to use ability: \n";
                cin >> pick;

                if (pick == 'b') choose(0);
                else if (pick == 'c') {
                    if (arche1 == 'A') alchemist(1);
                    else if (arche1 == 'P') paladin(1);
                }

                BatTicTacToe();
                win();
                if (W) break;

                if (i == 4) {
                    cout << "\nIt's a tie\n";
                    won = 11;
                    break;
                }

                cout << "\nplayer 2, enter 'b' to move or 'c' to use ability: \n";
                cin >> pick;

                if (pick == 'b') choose(-1);
                else if (pick == 'c') {
                    if (arche2 == 'A') alchemist(2);
                    else if (arche2 == 'P') paladin(2);
                }

                BatTicTacToe();
                win();
                if (W) break;
            }
        }

        cout << "\nPlay again? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') goto top;
        return 0;
    }

    else {
        cout << "\nInvalid input, please try again.\n";
        goto top;
    }
}

void TicTacToe()                                                            // display function
{
    if (grid[1] == 1)								                        // changes number 1 on the board to an O or X depending on which player chooses
        cout << grid[1] << "\t";

    else if (grid[1] == 0) {
        cout << "O\t";
    }
    else if (grid[1] == -1) {
        cout << "X\t";
    }
    if (grid[2] == 2)								                        // changes number 2 on the board to an O or X depending on which player chooses
        cout << grid[2] << "\t";

    else if (grid[2] == 0) {
        cout << "O\t";
    }
    else if (grid[2] == -1) {
        cout << "X\t";
    }
    if (grid[3] == 3)								                        // changes number 3 on the board to an O or X depending on which player chooses
        cout << grid[3] << "\n\n";

    else if (grid[3] == 0) {
        cout << "O\t\n\n";
    }
    else if (grid[3] == -1) {
        cout << "X\t\n\n";
    }
    if (grid[4] == 4)								                        // changes number 4 on the board to an O or X depending on which player chooses
        cout << grid[4] << "\t";

    else if (grid[4] == 0) {
        cout << "O\t";
    }
    else if (grid[4] == -1) {
        cout << "X\t";
    }

    if (grid[5] == 5)								                        // changes number 5 on the board to an O or X depending on which player chooses
        cout << grid[5] << "\t";

    else if (grid[5] == 0) {
        cout << "O\t";
    }
    else if (grid[5] == -1) {
        cout << "X\t";
    }

    if (grid[6] == 6)								                        // changes number 6 on the board to an O or X depending on which player chooses
        cout << grid[6] << "\n\n";

    else if (grid[6] == 0) {
        cout << "O\t\n\n";
    }

    else if (grid[6] == -1) {
        cout << "X\t\n\n";
    }

    if (grid[7] == 7)								                        // changes number 7 on the board to an O or X depending on which player chooses
        cout << grid[7] << "\t";

    else if (grid[7] == 0) {
        cout << "O\t";
    }
    else if (grid[7] == -1) {
        cout << "X\t";
    }

    if (grid[8] == 8)								                        // changes number 8 on the board to an O or X depending on which player chooses
        cout << grid[8] << "\t";

    else if (grid[8] == 0) {
        cout << "O\t";
    }
    else if (grid[8] == -1) {
        cout << "X\t";
    }

    if (grid[9] == 9)								                        // changes number 9 on the board to an O or X depending on which player chooses
        cout << grid[9];

    else if (grid[9] == 0) {
        cout << "O\t";
    }

    else if (grid[9] == -1) {
        cout << "X\t";
    }
}

void BatTicTacToe()    								                        // changes the numbers on the board to a character the players choose from
{
    if (grid[1] == 1)
        cout << grid[1] << "\t";

    else if (grid[1] == 0) {
        cout << ch1 << "\t";
    }
    else if (grid[1] == -1) {
        cout << ch2 << "\t";
    }
    if (grid[2] == 2)
        cout << grid[2] << "\t";

    else if (grid[2] == 0) {
        cout << ch1 << "\t";
    }
    else if (grid[2] == -1) {
        cout << ch2 << "\t";
    }
    if (grid[3] == 3)
        cout << grid[3] << "\n\n";

    else if (grid[3] == 0) {
        cout << ch1 << "\t\n\n";
    }
    else if (grid[3] == -1) {
        cout << ch2 << "\t\n\n";
    }
    if (grid[4] == 4)
        cout << grid[4] << "\t";

    else if (grid[4] == 0) {
        cout << ch1 << "\t";
    }
    else if (grid[4] == -1) {
        cout << ch2 << "\t";
    }

    if (grid[5] == 5)
        cout << grid[5] << "\t";

    else if (grid[5] == 0) {
        cout << ch1 << "\t";
    }
    else if (grid[5] == -1) {
        cout << ch2 << "\t";
    }

    if (grid[6] == 6)
        cout << grid[6] << "\n\n";

    else if (grid[6] == 0) {
        cout << ch1 << "\t\n\n";
    }

    else if (grid[6] == -1) {
        cout << ch2 << "\t\n\n";
    }

    if (grid[7] == 7)
        cout << grid[7] << "\t";

    else if (grid[7] == 0) {
        cout << ch1 << "\t";
    }
    else if (grid[7] == -1) {
        cout << ch2 << "\t";
    }

    if (grid[8] == 8)
        cout << grid[8] << "\t";

    else if (grid[8] == 0) {
        cout << ch1 << "\t";
    }
    else if (grid[8] == -1) {
        cout << ch2 << "\t";
    }

    if (grid[9] == 9)
        cout << grid[9];

    else if (grid[9] == 0) {
        cout << ch1 << "\t";
    }

    else if (grid[9] == -1) {
        cout << ch2 << "\t";
    }
}

void choose(int swap)
{
    int select;										                        // this variable allows for 2 players to input numbers
start:
    cout << "\nChoose a number: ";                                          // prompts user to choose a number
    cin >> select;

    if (grid[1] == 1 && select == 1)				                        // replaces the number with an O or X and displays it
    {
        grid[1] = swap;
    }

    else if (grid[2] == 2 && select == 2)			                        // replaces the number with an O or X and displays it
    {
        grid[2] = swap;
    }

    else if (grid[3] == 3 && select == 3)			                        // replaces the number with an O or X and displays it
    {
        grid[3] = swap;
    }

    else if (grid[4] == 4 && select == 4)			                        // replaces the number with an O or X and displays it
    {
        grid[4] = swap;
    }

    else if (grid[5] == 5 && select == 5)			                        // replaces the number with an O or X and displays it
    {
        grid[5] = swap;
    }

    else if (grid[6] == 6 && select == 6)			                        // replaces the number with an O or X and displays it
    {
        grid[6] = swap;
    }

    else if (grid[7] == 7 && select == 7)			                        // replaces the number with an O or X and displays it
    {
        grid[7] = swap;
    }

    else if (grid[8] == 8 && select == 8)			                        // replaces the number with an O or X and displays it
    {
        grid[8] = swap;
    }

    else if (grid[9] == 9 && select == 9)			                        // replaces the number with an O or X and displays it
    {
        grid[9] = swap;
    }

    else
    {
        cout << "\nThat number is either already chosen or invalid\nTry Again\n";
        goto start;
    }
}


void win(void)
{
    if (grid[1] == grid[2] && grid[1] == grid[3])	                        // displays a 1 2 3 win and the player who won
    {
        W = true;
        cout << "\nWin from 1, 2, and 3 \n";
        if (grid[1] == 0)
            cout << "Player 1 won";
        else if (grid[1] == -1)
            cout << "Player 2 won";
    }
    if (grid[4] == grid[5] && grid[4] == grid[6]) 	                        // displays a 4 5 6 win and the player who won
    {
        W = true;
        cout << "\nWin from 4, 5, and 6 \n";
        if (grid[1] == 0)
            cout << "Player 1 won";
        else if (grid[2] == -1)
            cout << "Player 2 won";
    }
    if (grid[7] == grid[8] && grid[7] == grid[9])	                        // displays a 7 8 9 win and the player who won
    {
        W = true;
        cout << "\nWin from 7, 8, and 9 \n";
        if (grid[1] == 0)
            cout << "Player 1 won";
        else
            cout << "Player 2 won";
    }
    if (grid[1] == grid[5] && grid[1] == grid[9]) 	                        // displays a 1 5 9 win and the player who won
    {
        W = true;
        cout << "\nWin from 1, 5, and 9 \n";
        if (grid[1] == 0)
            cout << "Player 1 won";
        else
            cout << "Player 2 won";
    }
    if (grid[3] == grid[5] && grid[3] == grid[7])	                        // displays a 3 5 7 win and the player who won
    {
        W = true;
        cout << "\nWin from 3, 5, and 7 \n";
        if (grid[3] == 0)
            cout << "Player 1 won";
        else
            cout << "Player 2 won";
    }
    if (grid[1] == grid[4] && grid[1] == grid[7])	                        // displays a 1 4 7 win and the player who won
    {
        W = true;
        cout << "\nWin from 1, 4, and 7 \n";
        if (grid[1] == 0)
            cout << "Player 1 won";
        else
            cout << "Player 2 won";
    }
    if (grid[2] == grid[5] && grid[2] == grid[8])	                        // displays a 2 5 8 win and the player who won
    {
        W = true;
        cout << "\nWin from 2, 5, and 8 \n";
        if (grid[2] == 0)
            cout << "Player 1 won";
        else
            cout << "Player 2 won";
    }
    if (grid[3] == grid[6] && grid[3] == grid[9])	                        // displays a 3 6 9 win and the player who won
    {
        W = true;
        cout << "\nWin from 1, 2, and 3 \n";
        if (grid[3] == 0)
            cout << "Player 1 won";
        else
            cout << "Player 2 won";
    }
}

void Newgame()                                                              // resets board
{
    grid[1] = 1;
    grid[2] = 2;
    grid[3] = 3;
    grid[4] = 4;
    grid[5] = 5;
    grid[6] = 6;
    grid[7] = 7;
    grid[8] = 8;
    grid[9] = 9;
    won = 10;
    W = false;
}

void alchemist(int playerNumber) {
    int opponentPosition;
    cout << "Player " << playerNumber << " (Alchemist), choose a position to swap with your opponent (1-9): ";
    cin >> opponentPosition;

    int opponentMarker = (playerNumber == 1) ? -1 : 0;                                                          // Determine the opponent's marker

    if ((opponentPosition >= 1 && opponentPosition <= 9) && (grid[opponentPosition] == opponentMarker)) {       // Check if the chosen position is occupied by the opponent

        int alchemistPosition = -1;                                                                             // Find the current position of the Alchemist
        for (int i = 1; i <= 9; i++) {
            if (grid[i] == (playerNumber == 1 ? 0 : -1)) {
                alchemistPosition = i;
                break;
            }
        }


        if (alchemistPosition != -1) {                                                                          // Swap positions and values
            grid[alchemistPosition] = opponentMarker;                                                           // Move Alchemist to opponent's position
            grid[opponentPosition] = (playerNumber == 1 ? 0 : -1);                                              // Move opponent to Alchemist's position
            cout << "Alchemist swapped with opponent at position " << opponentPosition << "!\n";
        }
    }
    else {
        cout << "Invalid position or position is not occupied by the opponent. Try again.\n";                  // Retry if the input was invalid
        alchemist(playerNumber);
    }
}

void paladin(int playerNumber) {
    int movefrom, moveto;
    cout << "Player " << playerNumber << " (Paladin), choose your current position (1-9): ";
    cin >> movefrom;


    if (grid[movefrom] == (playerNumber == 1 ? 0 : -1)) {                                                       // Check if the movefrom position is occupied by the Paladin
        cout << "Choose an adjacent position to move to (1-9): ";
        cin >> moveto;


        bool isAdjacent = false;                                                                                // Check if the target position is adjacent and unoccupied
        if ((movefrom == 1 && (moveto == 2 || moveto == 4)) ||
            (movefrom == 2 && (moveto == 1 || moveto == 3 || moveto == 5)) ||
            (movefrom == 3 && (moveto == 2 || moveto == 6)) ||
            (movefrom == 4 && (moveto == 1 || moveto == 5 || moveto == 7)) ||
            (movefrom == 5 && (moveto == 2 || moveto == 4 || moveto == 6 || moveto == 8)) ||
            (movefrom == 6 && (moveto == 3 || moveto == 5 || moveto == 9)) ||
            (movefrom == 7 && (moveto == 4 || moveto == 8)) ||
            (movefrom == 8 && (moveto == 5 || moveto == 7 || moveto == 9)) ||
            (movefrom == 9 && (moveto == 6 || moveto == 8))) {
            isAdjacent = true;
        }

        if (isAdjacent && (grid[moveto] >= 1)) {                                                                // Ensure target position is not occupied
            grid[moveto] = (playerNumber == 1 ? 0 : -1);                                                        // Move Paladin to new position
            grid[movefrom] = (playerNumber == 1 ? 1 : -1);                                                      // Mark original position as free
            cout << "Paladin moved to position " << moveto << "!\n";
        }
        else {
            cout << "Invalid move. Try again.\n";
            paladin(playerNumber);                                                                              // Retry if the input was invalid
        }
    }
    else {
        cout << "You are not in that position. Try again.\n";
        paladin(playerNumber);                                                                                  // Retry if the input was invalid
    }
}