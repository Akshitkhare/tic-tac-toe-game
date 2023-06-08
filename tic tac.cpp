#include <iostream>
#include <cstring>

using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void printBoard() {
    cout << "   1   2   3" << endl;
    cout << "1  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "  ---|---|---" << endl;
    cout << "2  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "  ---|---|---" << endl;
    cout << "3  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool isBoardFull() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool hasWon(char player) {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

void placeMark(int row, int col, char mark) {
    board[row][col] = mark;
}

int main() {
    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "Player 1: X" << endl;
    cout << "Player 2: O" << endl;
    int currentPlayer = 1;
    while(!isBoardFull()) {
        printBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter row (1-3): ";
        cin >> row;
        cout << "Player " << currentPlayer << ", enter column (1-3): ";
        cin >> col;
        row--;
        col--;
        if(board[row][col] != ' ') {
            cout << "That spot is already taken. Please try again." << endl;
            continue;
        }
        char mark = (currentPlayer == 1) ? 'X' : 'O';
        placeMark(row, col, mark);
        if(hasWon(mark)) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            return 0;
        }
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    printBoard();
    cout << "It's a tie!" << endl;
    return 0;
}

