#include<bits/stdc++.h>
using namespace std;

#define N 9

bool isSafeInRow(int grid[N][N], int row, int num){
    for(int i = 0; i < N; i++){
        if(grid[row][i] == num){
            return false;
        }
    }
    return true;
}

bool isSafeInColumn(int grid[N][N], int col, int num){
    for(int i = 0; i < N; i++){
        if(grid[i][col] == num){
            return false;
        }
    }
    return true;
}

bool isSafeInGrid(int grid[N][N], int row, int col, int num){
    int rowFactor = row - (row%3);
    int colFactor = col - (col%3);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i+rowFactor][j+colFactor] == num){
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int grid[N][N], int row, int col, int num){
    if(isSafeInRow(grid, row, num) && isSafeInColumn(grid, col, num) && isSafeInGrid(grid, row, col, num)){
        return true;
    }
    return false;
}

bool findEmptyLocation(int grid[N][N], int &row, int &col){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int grid[N][N]){
    int row, col;
    if(!findEmptyLocation(grid, row, col)){
        return true;
    }
    for(int i = 1; i <= N; i++){
        if(isSafe(grid, row, col, i)){
            grid[row][col] = i;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(){

    // int grid[N][N];
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    // for(int i = 0; i < N; i++){
    //     string s;
    //     cin >> s;
    //     for(int j = 0; j < s.length(); j++){
    //         grid[i][j] = s[j] - '0';
    //     }
    // }

    solveSudoku(grid);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}