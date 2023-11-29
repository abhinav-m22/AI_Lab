#include<bits/stdc++.h>
using namespace std;

bool isSafe(int col, int row, int n, vector<vector<int>>& v){
    for(int i = row-1; i >= 0; i--){
        if(v[i][col] == 1) return false;
    }
    
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
        if(v[i][j] == 1) return false;
    }

    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++){
        if(v[i][j] == 1) return false;
    }
    return true;
}

void placeNQueens(int n, int row, vector<vector<int>>& v){
    if(row == n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for(int j = 0; j < n; j++){
        if(isSafe(j, row, n, v)){
            v[row][j] = 1;
            placeNQueens(n, row+1, v);
            v[row][j] = 0;
        }
    }
}

int main(){

    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    if(n < 4){
        cout << "Solution does not exist for this input!" << endl;
        return 0;
    }

    placeNQueens(n, 0, v);
    return 0;
}