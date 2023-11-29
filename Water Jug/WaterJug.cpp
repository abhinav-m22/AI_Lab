#include<bits/stdc++.h>
using namespace std;

bool isFinal(pair<int, int>& final, int x, int y){
	return final.first == x && final.second == y;
}

void bfs(pair<int, int>& initial, pair<int, int>& final){
	vector<pair<int, int>> v;
	queue<pair<pair<int, int>, vector<pair<int, int>>>> q;
	q.push({initial, v});
	bool flag = 0;
	
	while(!q.empty()){
		int size = q.size();
		for(int i = 0; i < size; i++){
			int x = q.front().first.first;
			int y = q.front().first.second;
			vector<pair<int, int>> v = q.front().second;
			q.pop();

			if(isFinal(final, x, y)){
				for(auto p : v){
					cout << p.first << " " << p.second << endl;
				}
				flag = 1;
				break;
			}
			if(x < 4){
				v.push_back({4, y});
				q.push({{4, y}, v});
				v.pop_back();
			}
			if(y < 3){
				v.push_back({x, 3});
				q.push({{x, 3}, v});
				v.pop_back();
			}
			if(x > 0){
				v.push_back({0, y});
				q.push({{0, y}, v});
				v.pop_back();
			}
			if(y > 0){
				v.push_back({x, 0});
				q.push({{x, 0}, v});
				v.pop_back();
			}
			if(x + y >= 4 && y > 0){
				v.push_back({4, y - (4 - x)});
				q.push({{4, y - (4 - x)}, v});
				v.pop_back();
			}
			if(x + y >= 3 && x > 0){
				v.push_back({x - (3 - y), 3});
				q.push({{x - (3 - y), 3}, v});
				v.pop_back();
			}
			if(x + y <= 4 && y > 0){
				v.push_back({x + y, 0});
				q.push({{x + y, 0}, v});
				v.pop_back();
			}
			if(x + y <= 3 && x > 0){
				v.push_back({0, x + y});
				q.push({{0, x + y}, v});
				v.pop_back();
			}
		}
		if(flag){
			break;
		}
	}
}

int main(){
						  // {4, 3}
	pair<int, int> initial = {0, 0};
	pair<int, int> final = {2, 0};

	bfs(initial, final);

	return 0;
}