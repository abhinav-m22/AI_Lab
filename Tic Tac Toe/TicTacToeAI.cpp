#include<bits/stdc++.h>
using namespace std;

int n = 3;

void printBoard(vector<vector<char>>& board){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool checkWin(vector<vector<char>>& board, char c) {
    for (int i = 0; i < n; i++) {
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

bool isBoardFull(vector<vector<char>>& board) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int evaluateBoard(vector<vector<char>>& board) {
    if (checkWin(board, 'X')) 
        return 10;
    if (checkWin(board, 'O')) 
        return -10;
    return 0;
}

int minimax(vector<vector<char>>& board, bool maxi) {
    int score = evaluateBoard(board);

    if (score == 10 || score == -10)
        return score;

    if (isBoardFull(board))
        return 0;

    if (maxi) {
        int bestScore = -1000;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    bestScore = max(bestScore, minimax(board, !maxi));
                    board[i][j] = ' ';
                }
            }
        }
        return bestScore;
    }
    else {
        int bestScore = 1000;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    bestScore = min(bestScore, minimax(board, !maxi));
                    board[i][j] = ' ';
                }
            }
        }
        return bestScore;
    }
}

pair<int, int> findBestMove(vector<vector<char>>& board) {
    int bestScore = -1000;
    pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                int moveScore = minimax(board, false);
                board[i][j] = ' ';

                if (moveScore > bestScore) {
                    bestScore = moveScore;
                    bestMove = {i, j};
                }
            }
        }
    }

    return bestMove;
}

int main() {
    
    vector<vector<char>> board(n, vector<char>(n, ' '));

    bool isXTurn = true;

    while (!checkWin(board, 'X') && !checkWin(board, 'O') && !isBoardFull(board)){
        printBoard(board);

        if (isXTurn) {
            int row, col;
            cout << "Player 0 (User): ";
            cin >> row >> col;

            if (row >= 0 && row < n && col >= 0 && col < n && board[row][col] == ' ') {
                board[row][col] = 'O';
                isXTurn = false;
            } else {
                cout << "Invalid move. Try again!" << endl;
            }

        } 
        else {
            cout << "Player X (Computer)" << endl;
            pair<int, int> aiMove = findBestMove(board);
            board[aiMove.first][aiMove.second] = 'X';
            isXTurn = true;
        }
    }

    if (checkWin(board, 'X'))
        cout << "AI wins!" << endl;
    else if (checkWin(board, 'O'))
        cout << "You win!" << endl;
    else
        cout << "It's a draw!" << endl;

    return 0;
}