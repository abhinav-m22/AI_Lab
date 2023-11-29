#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> board(3, vector<char>(3, ' '));

void print(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool checkWin(char c) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c)
            return true;
        if (board[0][i] == c && board[1][i] == c && board[2][i] == c)
            return true;
    }
    
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
        return true;
    if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
        return true;
    
    return false;
}

bool makeMove(int row, int col, char c) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
        return false;
    
    board[row][col] = c;
    return true;
}

bool isBoardFull(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' ') return false;
        }
    }
    return true;
}

void computer() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                if (checkWin('O'))
                    return;
                board[i][j] = ' ';
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                if (checkWin('X')) {
                    board[i][j] = 'O';
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    int row, col;
    while (!makeMove(row, col, 'O')) {
        row = rand() % 3;
        col = rand() % 3;
    }
}

int main() {
    
    char currentPlayer = 'X';
    int row, col;
    
    while (true) {
        print();
            
        if (currentPlayer == 'X') {
            cout << "Player X's turn. Enter row and column: ";
            cin >> row >> col;
            
            if (!makeMove(row, col, currentPlayer)) {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
        } else {
            cout << "Player O's turn" << endl;
            computer();
        }
        
        if (checkWin(currentPlayer)) {
            print();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        
        if (isBoardFull()) {
            print();
            cout << "It's a draw!" << endl;
            break;
        }
        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    return 0;
}
