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

void solve(vector<vector<int>> &initial, vector<vector<int>> &goal){
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    queue<pair<vector<vector<int>>, vector<vector<vector<int>>>>> q;
    vector<vector<vector<int>>> ans;
    q.push({initial, ans});

    while (!q.empty()){
        vector<vector<int>> curr = q.front().first;
        vector<vector<vector<int>>> currGoal = q.front().second;
        q.pop();

        if (curr == goal){
            for (auto v : currGoal){
                printBoard(v);
            }
            cout << "Goal State Reached" << endl;
            return;
        }
        int x, y;
        findZero(curr, x, y);

        for (int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < curr.size() && newY >= 0 && newY < curr.size()){
                swap(curr[x][y], curr[newX][newY]);
                currGoal.push_back(curr);
                q.push({curr, currGoal});
                swap(curr[x][y], curr[newX][newY]);
                currGoal.pop_back();
            }
        }
    }
}

int main(){
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

    solve(initial, goal);

    return 0;
}