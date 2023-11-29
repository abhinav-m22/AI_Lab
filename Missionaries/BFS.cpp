#include<bits/stdc++.h>
using namespace std;

#define state pair<vector<int>, vector<int>>
#define path vector<pair<vector<int>, vector<int>>>

bool isFinal(vector<int>& x, vector<int>& y, state& goal){
    return (x == goal.first && y == goal.second);
}

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
                if(n1 >= 2){
                    vector<int> left = {n1 - 2, m1, 1 - b1};
                    vector<int> right = {n2 + 2, m2, 1 - b2};
                    if((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0)){
                        p.push_back({left, right});
                        q.push({{left, right}, p});
                        p.pop_back();

                    }
                }
                if(n1 >= 1 && m1 >= 1){
                    vector<int> left = {n1 - 1, m1 - 1, 1 - b1};
                    vector<int> right = {n2 + 1, m2 + 1, 1 - b2};
                    if((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0)){
                        p.push_back({left, right});
                        q.push({{left, right}, p});
                        p.pop_back();

                    }
                        
                }
                if(m1 >= 2){
                    vector<int> left = {n1, m1 - 2, 1 - b1};
                    vector<int> right = {n2, m2 + 2, 1 - b2};
                    if((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0)){
                        p.push_back({left, right});
                        q.push({{left, right}, p});
                        p.pop_back();

                    }
                }
                if(n1 >= 1){
                    vector<int> left = {n1 - 1, m1, 1 - b1};
                    vector<int> right = {n2 + 1, m2, 1 - b2};
                    if((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0)){
                        p.push_back({left, right});
                        q.push({{left, right}, p});
                        p.pop_back();

                    }
                }
                if(m1 >= 1){
                    vector<int> left = {n1, m1 - 1, 1 - b1};
                    vector<int> right = {n2, m2 + 1, 1 - b2};
                    if((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0)){
                        p.push_back({left, right});
                        q.push({{left, right}, p});
                        p.pop_back();

                    }
                }
            }
            else{
                if(n2 >= 2){
                    vector<int> left = {n1 + 2, m1, 1 - b1};
                    vector<int> right = {n2 - 2, m2, 1 - b2};
                    if((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0)){
                        p.push_back({left, right});
                        q.push({{left, right}, p});
                        p.pop_back();
                    }
                }
                if(n2 >= 1 && m2 >= 1){
                    vector<int> left = {n1 + 1, m1 + 1, 1 - b1};
                    vector<int> right = {n2 - 1, m2 - 1, 1 - b2};
                    if((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0)){
                        p.push_back({left, right});
                        q.push({{left, right}, p});
                        p.pop_back();
                    }
                }
                if(m2 >= 2){
                    vector<int> left = {n1, m1 + 2, 1 - b1};
                    vector<int> right = {n2, m2 - 2, 1 - b2};
                    if((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0)){
                        p.push_back({left, right});
                        q.push({{left, right}, p});
                        p.pop_back();
                    }
                }
                if(n2 >= 1){
                    vector<int> left = {n1 + 1, m1, 1 - b1};
                    vector<int> right = {n2 - 1, m2, 1 - b2};
                    if((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0)){
                        p.push_back({left, right});
                        q.push({{left, right}, p});
                        p.pop_back();
                    }
                }
                if(m2 >= 1){
                    vector<int> left = {n1, m1 + 1, 1 - b1};
                    vector<int> right = {n2, m2 - 1, 1 - b2};
                    if((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0)){
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