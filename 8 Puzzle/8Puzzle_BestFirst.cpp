#include<bits/stdc++.h>
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

bool isReachable(vector<vector<int>> &initial, vector<vector<int>> &goal) {
    vector<int> initialArray;
    vector<int> goalArray;

    for (int i = 0; i < initial.size(); i++) {
        for (int j = 0; j < initial[i].size(); j++) {
            initialArray.push_back(initial[i][j]);
            goalArray.push_back(goal[i][j]);
        }
    }

    int initialInversions = 0;
    int goalInversions = 0;

    for (int i = 0; i < initialArray.size(); i++) {
        for (int j = i + 1; j < initialArray.size(); j++) {
            if (initialArray[i] != 0 && initialArray[j] != 0 && initialArray[i] > initialArray[j]) {
                initialInversions++;
            }
            if (goalArray[i] != 0 && goalArray[j] != 0 && goalArray[i] > goalArray[j]) {
                goalInversions++;
            }
        }
    }

    return (initialInversions % 2 == goalInversions % 2);
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

int findMisplacedTiles(vector<vector<int>> &board, vector<vector<int>> &goal){
    int count = 0;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board.size(); j++){
            if (board[i][j] != goal[i][j])
                count++;
        }
    }
    return count;
}

void bestFirst(vector<vector<int>> &board, vector<vector<int>> &goal, int depth, int x, int y, vector<vector<vector<int>>>& ans){
    priority_queue<pair<int, vector<vector<int>>>, vector<pair<int, vector<vector<int>>>>, greater<pair<int, vector<vector<int>>>>> pq;

    int h = findMisplacedTiles(board, goal);
    pq.push({h, board});

    while(!pq.empty()){
        vector<vector<int>> curr = pq.top().second;
        pq.pop();
        int x, y;
        findZero(curr, x, y);
        if(isGoalState(curr, goal)){
            for(auto v : ans){
                printBoard(v);
            }
            printBoard(curr);
            cout << "Goal State Reached" << endl;
            return;
        }
        ans.push_back(curr);

        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board.size()){
                vector<vector<int>> temp = curr;
                swap(temp[x][y], temp[nx][ny]);
                int h = findMisplacedTiles(temp, goal);
                pq.push({h, temp});
            }
        }
    }
}

int main(){

    vector<vector<int>> initial = {
        {8, 1, 2},
        {0, 4, 3},
        {7, 6, 5}
    };

    vector<vector<int>> goal = {
        {8, 2, 1},
        {4, 3, 5},
        {0, 7, 6}
    };

    if(!isReachable(initial, goal)){
        cout << "Goal State is not reachable" << endl;
        return 0;
    }

    int x, y;
    findZero(initial, x, y);
    vector<vector<vector<int>>> ans;
    bestFirst(initial, goal, 0, x, y, ans);

    return 0;
}