#include<bits/stdc++.h>
using namespace std;


void printBoard(vector<vector<char>>& board){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool checkWin(vector<vector<char>>& board, char p){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == p && board[i][1] == p && board[i][2] == p){
            return true;
        }
        if(board[0][i] == p && board[1][i] == p && board[2][i] == p){
            return true;
        }
    }
    
    if(board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;
    if(board[0][2] == p && board[1][1] == p && board[2][0] == p) return true;

    return false;
}

bool isBoardFull(vector<vector<char>>& board){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' ') return false;
        }
    }
    return true;
}

int evaluateBoard(vector<vector<char>>& board){
    if(checkWin(board, 'X')) return 10;
    if(checkWin(board, 'O')) return -10;
    return 0;
}

int minimax(vector<vector<char>>& board, bool maxi){
    int score = evaluateBoard(board);
    if(score == 10 || score == -10) return score;
    if(isBoardFull(board)) return 0;

    if(maxi){
        int best = -1000;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == ' '){
                    board[i][j] = 'X';
                    best = max(best, minimax(board, !maxi));
                    board[i][j] = ' '; 
                }
            }
        }
        return best;
    }
    else{
        int best = 1000;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == ' '){
                    board[i][j] = 'O';
                    best = min(best, minimax(board, !maxi));
                    board[i][j] = ' '; 
                }
            }
        }
        return best;
    }
}

pair<int, int> findBestMove(vector<vector<char>>& board){
    int bestScore = -1000;
    pair<int, int> p = {-1, -1};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                board[i][j] = 'X';
                int moveScore = minimax(board, false);
                board[i][j] = ' ';
                if(moveScore > bestScore){
                    p = {i, j};
                    bestScore = moveScore;
                }
            }
        }
    }
    return p;
}

int main(){

    vector<vector<char>> board(3, vector<char>(3, ' '));

    bool isOTurn = 1;

    while(!checkWin(board, 'X') && !checkWin(board, 'O') && !isBoardFull(board)){
        printBoard(board);
        if(isOTurn){
            int x, y;
            cout << "Enter the position: ";
            cin >> x >> y;

            if(board[x][y] == ' ' && x >= 0 && x < 3 && y >= 0 && y < 3){
                board[x][y] = 'O';
                isOTurn = false;
            }
            else{
                cout << "Invalid move. Try again!" << endl;
            }
        }
        else{
            pair<int, int> p = findBestMove(board);
            cout << "Computer's move: " << endl;
            board[p.first][p.second] = 'X';
            isOTurn = true;
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