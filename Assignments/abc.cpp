#include <bits/stdc++.h>
using namespace std;

void findZero(vector<vector<int>> board, int &x, int &y){
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board.size(); j++){
            if (board[i][j] == 0){
                x = i;
                y = j;
                return;
            }
        }
    }
}

void printBoard(vector<vector<int>> board){
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board.size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isGoalState(vector<vector<int>> &board, vector<vector<int>> &goal) {
    return board == goal;
}

bool dfs(vector<vector<int>> &board, vector<vector<int>> &goal, int depth, int x, int y, vector<vector<vector<int>>>& ans) {
    if (depth > 10) 
        return false;

    if (isGoalState(board, goal)) {
        for (auto v : ans) {
            printBoard(v);
        }
        cout << "Goal State Reached" << endl;
        return true;
    }

    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board.size()) {
            swap(board[x][y], board[newX][newY]);
            ans.push_back(board);
            if (dfs(board, goal, depth + 1, newX, newY, ans))
                return true;
            ans.pop_back();
            swap(board[x][y], board[newX][newY]); 
        }
    }

    return false;
}

int main() {
    vector<vector<int>> initial = {
        {2, 8, 3},
        {1, 6, 4},
        {7, 0, 5}
    };

    vector<vector<int>> goal = {
        {1, 2, 3},
        {8, 0, 4},
        {7, 6, 5}
    };

    int x, y;
    findZero(initial, x, y);
    vector<vector<vector<int>>> ans;
    if (!dfs(initial, goal, 0, x, y, ans))
        cout << "Goal state not reachable." << endl;

    return 0;
}
