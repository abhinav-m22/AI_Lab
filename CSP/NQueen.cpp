#include<bits/stdc++.h>
using namespace std;

// Solution 1:
int board[11][11] = {0};

bool isPossible(int n, int row, int col){

    // Same Column
    for(int i = row-1; i >= 0; i--){
        if(board[i][col] == 1){
            return false;
        }
    }

    // Upper Left Diagonal
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    // Upper Right Diagonal
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
        if(board[i][j] == 1){
            return false;
        }
    }

    return true;
}

void nQueenHelper(int n, int row){
    if(row == n){
        // We have reached some solution
        // Print the solution
        // return

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // Place at possible locations and move to smaller problem
    for(int j = 0; j < n; j++){
        if(isPossible(n, row, j)){
            board[row][j] = 1;
            nQueenHelper(n,row+1);
            board[row][j] = 0;
        }
    }
}

void placeNQueens(int n){
    nQueenHelper(n, 0);    
}

int main(){
    int n;
    cin >> n;
    if(n <= 3){
        cout << "No Solution Exists" << endl;
        return 0;
    }
    placeNQueens(n);
    return 0;
}

// // Solution 2:
// class Solution {
    
//     bool isSafe(int row, int col, vector<string>& board, int n){
//         int dupRow = row;
//         int dupCol = col;
        
//         // Upper left diagonal
//         while(row >= 0 && col >= 0){
//             if(board[row][col]=='Q'){
//                 return false;
//             }
//             row--;
//             col--;
//         }
        

//         row = dupRow;
//         col = dupCol;
//         // Left row
//         while(col >= 0){
//             if(board[row][col]=='Q'){
//                 return false;
//             }
//             col--;
//         }
        
//         row = dupRow;
//         col = dupCol;
//         // Down left diagonal
//         while(row < n && col >= 0){
//             if(board[row][col]=='Q'){
//                 return false;
//             }
//             row++;
//             col--;
//         }
//         return true;
//     }
    
//     void helper(int col, vector<vector<string>>& ans, vector<string>& board, int n){
//         if(col == n){
//             ans.push_back(board);
//             return;
//         }
//         for(int row = 0; row < n; row++){
//             if(isSafe(row, col, board, n)){
//                 board[row][col] = 'Q';
//                 helper(col+1, ans, board, n);
//                 board[row][col] = '.';
//             }
//         }
//     }
    
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n);
//         string s(n, '.');
//         for(int i = 0; i < n; i++){
//             board[i] = s;
//         }
//         helper(0, ans, board, n);
//         return ans;
//     }
// };

// // Solution 3:
// class Solution {
    
//     void helper(int col, vector<vector<string>>& ans, vector<string>& board, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n){
        
//         if(col == n){
//             ans.push_back(board);
//             return;
//         }
//         for(int row = 0; row < n; row++){
//             if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[(n-1)+(col-row)] == 0){
//                 board[row][col] = 'Q';
//                 leftRow[row] = 1;
//                 upperDiagonal[(n-1) + (col-row)] = 1;
//                 lowerDiagonal[row+col] = 1;
//                 helper(col+1, ans, board, leftRow, upperDiagonal, lowerDiagonal, n);
//                 board[row][col] = '.';
//                 leftRow[row] = 0;
//                 upperDiagonal[(n-1) + (col-row)] = 0;
//                 lowerDiagonal[row+col] = 0;
//             }
//         }
//     }
    
// public:
    
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n);
//         string s(n, '.');
//         for(int i = 0; i < n; i++){
//             board[i] = s;
//         }
        
//         vector<int> leftRow(n, 0);
//         vector<int> upperDiagonal(2*n - 1, 0);
//         vector<int> lowerDiagonal(2*n - 1, 0);
//         helper(0, ans, board, leftRow, upperDiagonal, lowerDiagonal, n);
//         return ans;
//     }
// };