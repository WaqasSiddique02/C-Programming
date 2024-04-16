#include <iostream>

using namespace std;

class TicTacToe {
private:
    char board[3][3];
    int movesMade;

public:
    TicTacToe() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = '*';
            }
        }
        movesMade = 0;
    }

    void print() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                cout << board[i][j] << "|";
            cout << endl;
        }
    }

    int checkWinner(char player) {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return 1;
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
                return 1;
        }
        // Check diagonals
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return 1;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return 1;

        return 0;
    }

    void move() {
        int check = -1;
        int rows = 0;
        int columns = 0;

        for (int i = 0; i < 9; i++) {
            cout << "Player " << ((i % 2 == 0) ? "one" : "two") << ", enter your move (row column): ";
            cin >> rows >> columns;
            while (rows < 0 || rows > 2 || columns < 0 || columns > 2 || board[rows][columns] != '*') {
                cout << "Invalid move! Try again (row column): ";
                cin >> rows >> columns;
            }

            board[rows][columns] = (i % 2 == 0) ? 'X' : 'O';
            print();
            movesMade++;

            check = checkWinner((i % 2 == 0) ? 'X' : 'O');

            if (check == 1) {
                cout << "Player " << ((i % 2 == 0) ? "one" : "two") << " has won!";
                return;
            }
        }
        if (movesMade == 9) {
            cout << "It's a tie!";
            return;
        }
    }
};

int main() {
    TicTacToe game;
    game.print();
    game.move();

    return 0;
}
