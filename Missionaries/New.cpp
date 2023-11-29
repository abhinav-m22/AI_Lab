#include<bits/stdc++.h>
using namespace std;

#define state pair<vector<int>, vector<int>>
#define path vector<pair<vector<int>, vector<int>>>

bool isFinal(vector<int>& x, vector<int>& y, state& goal){
    return (x == goal.first && y == goal.second);
}

bool isValid(vector<int>& left, vector<int>& right){
    return (left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0) && (left[0] >= 0 && left[1] >= 0 && left[0] >= 0 && right[1] >= 0  && right[0] >= 0);
}

vector<pair<int, int>> del = {{2, 0}, {1, 1}, {0, 2}, {1, 0}, {0, 1}};

void bfs(state initial, state goal){
    path v;
    queue<pair<state, path>> q;
    q.push({initial, v});
    bool flag = 0;

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            vector<int> x = q.front().first.first;
            vector<int> y = q.front().first.second;
            path p = q.front().second;
            q.pop();

            int n1 = x[0], m1 = x[1], b1 = x[2];
            int n2 = y[0], m2 = y[1], b2 = y[2];

            if(isFinal(x, y, goal)){
                for(auto pair : p){
                    vector<int> left = pair.first;
                    vector<int> right = pair.second;
                    for(auto it : left){
                        cout << it << " ";
                    }
                    cout << " | ";
                    for(auto it : right){
                        cout << it << " ";
                    }
                    cout << endl;
                }
                flag = 1;
                break;
            }

            if(b1 == 1){
                for(auto it : del){
                    int nx = n1 - it.first; 
                    int ny = n2 + it.first;
                    int mx = m1 - it.second;
                    int my = m2 + it.second;

                    vector<int> left = {nx, mx, 1-b1};
                    vector<int> right = {ny, my, 1-b2};
                    if(isValid(left, right)){
                        p.push_back({left, right});
                        q.push({{left, right}, p});
                        p.pop_back();
                    }
                }
            }
            else{
                for(auto it : del){
                    int nx = n1 + it.first; 
                    int ny = n2 - it.first;
                    int mx = m1 + it.second;
                    int my = m2 - it.second;
                    vector<int> left = {nx, mx, 1-b1};
                    vector<int> right = {ny, my, 1-b2};
                    if(isValid(left, right)){
                        p.push_back({left, right});
                        q.push({{left, right}, p});
                        p.pop_back();
                    }
                }
            }
        }
        if(flag){
			break;
		}
    }

}

int main(){
                        // {left, Right}
                        // {{M, C, B}, {M, C, B}}
    state initialState = {{3, 3, 1}, {0, 0, 0}};
    state finalState = {{0, 0, 0}, {3, 3, 1}};

    bfs(initialState, finalState);

    return 0;
}