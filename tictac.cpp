#include <iostream>
#include <string>

using namespace std;

class Game {
public:
    char gameboard[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    string s1, s2;
    int row, column;
    char token = '*';
    bool tie = false;

    void playerdata() {
        cout << "Enter the name of the first player: ";
        cin >> s1;
        cout << "Enter the name of the second player: ";
        cin >> s2;
        cout << endl;
        cout << s1 << " you are assigned to token *" << endl;
        cout << s2 << " you are assigned to token 0" << endl;
        cout << s1 << " will play first" << endl;
    }

    void drawboard() {
        cout << gameboard[0][0] << " | " << gameboard[0][1] << " | " << gameboard[0][2] << endl;
        cout << "--|---|--" << endl;
        cout << gameboard[1][0] << " | " << gameboard[1][1] << " | " << gameboard[1][2] << endl;
        cout << "--|---|--" << endl;
        cout << gameboard[2][0] << " | " << gameboard[2][1] << " | " << gameboard[2][2] << endl;
    }

    void getMove() {
        int digit;
        cout << (token == '*' ? s1 : s2) << " it's your turn, enter the number of the cell: ";
        cin >> digit;

        if (digit < 1 || digit > 9) {
            cout << "Invalid input. Please enter a number between 1 and 9." << endl;
            getMove();
            return;
        }

        if (digit == 1) { row = 0; column = 0; }
        else if (digit == 2) { row = 0; column = 1; }
        else if (digit == 3) { row = 0; column = 2; }
        else if (digit == 4) { row = 1; column = 0; }
        else if (digit == 5) { row = 1; column = 1; }
        else if (digit == 6) { row = 1; column = 2; }
        else if (digit == 7) { row = 2; column = 0; }
        else if (digit == 8) { row = 2; column = 1; }
        else if (digit == 9) { row = 2; column = 2; }

        if (gameboard[row][column] != '*' && gameboard[row][column] != '0') {
            gameboard[row][column] = token;
            token = (token == '*') ? '0' : '*';
        } else {
            cout << "Cell already occupied. Try again." << endl;
            getMove();
        }
    }

    bool checkWin() {
        // Check rows and columnsr
        
        for (int i = 0; i < 3; i++) {
            if ((gameboard[i][0] == gameboard[i][1] && gameboard[i][1] == gameboard[i][2]) ||
                (gameboard[0][i] == gameboard[1][i] && gameboard[1][i] == gameboard[2][i])) {
                return true;
            }
        }

        // Check diagonals
        if ((gameboard[0][0] == gameboard[1][1] && gameboard[1][1] == gameboard[2][2]) ||
            (gameboard[0][2] == gameboard[1][1] && gameboard[1][1] == gameboard[2][0])) {
            return true;
        }

        return false;
    }

    bool checkTie() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gameboard[i][j] != '*' && gameboard[i][j] != '0') {
                    return false;
                }
            }
        }
        tie = true;
        return true;
    }

    void run() {
        while (!checkWin() && !checkTie()) {
            drawboard();
            getMove();
        }
        drawboard();
        if (checkWin()) {
            if (token == '*') {
                cout << s2 << " wins!" << endl;
            } else {
                cout << s1 << " wins!" << endl;
            }
        } else if (tie) {
            cout << "It's a tie!" << endl;
        }
    }
};

int main() {
    Game g;
    g.playerdata();
    g.run();
    return 0;
}
