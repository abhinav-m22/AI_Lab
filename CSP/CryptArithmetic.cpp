#include<bits/stdc++.h>
using namespace std;

#define node pair<char, int>

vector<int> use(10);

bool check(node* nodeArr, string& s1, string& s2, string& s3, int cnt){
    int val1 = 0, val2 = 0, val3 = 0, m = 1, j;
    for(int i = s1.size()-1; i >= 0; i--){
        for(j = 0; j < cnt; j++){
            if(nodeArr[j].first == s1[i]) break;
        }
        val1 += (m*nodeArr[j].second);
        m *= 10;
    }
    m = 1;

    for(int i = s2.size()-1; i >= 0; i--){
        for(j = 0; j < cnt; j++){
            if(nodeArr[j].first == s2[i]) break;
        }
        val2 += (m*nodeArr[j].second);
        m *= 10;
    }
    m = 1;

    for(int i = s3.size()-1; i >= 0; i--){
        for(j = 0; j < cnt; j++){
            if(nodeArr[j].first == s3[i]) break;
        }
        val3 += (m*nodeArr[j].second);
        m *= 10;
    }

    if((val1+val2) == val3){
        return true;
    }
    return false;
}

bool permutation(node* nodeArr, int cnt, int ind, string& s1, string& s2, string& s3){

    if(ind == cnt-1){
        for(int i = 0; i < 10; i++){
            if(use[i] == 0){
                nodeArr[ind].second = i;
                // use[i] = 1;
                if(check(nodeArr, s1, s2, s3, cnt) == true){
                    for(int j = 0; j < cnt; j++){
                        cout << nodeArr[j].first << " = " << nodeArr[j].second << endl;
                    }
                    return true;
                }
            }
        }
        return false;
    }

    for(int i = 0; i < 10; i++){
        if(use[i] == 0){
            nodeArr[ind].second = i;
            use[i] = 1;
            if(permutation(nodeArr, cnt, ind+1, s1, s2, s3) == true) return true;
            use[i] = 0;
        }
    }
    return false;
}

bool cryptArithmetic(string s1, string s2, string s3){
    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    vector<int> freq(26, 0);
    for(int i = 0; i < n1; i++){
        freq[s1[i] - 'A']++;
    }
    for(int i = 0; i < n2; i++){
        freq[s2[i] - 'A']++;
    }
    for(int i = 0; i < n3; i++){
        freq[s3[i] - 'A']++;
    }

    int cnt = 0;
    for(int i = 0; i < 26; i++){
        if(freq[i] > 0) cnt++;
    }

    if(cnt > 10){
        cout << "Invalid strings" << endl;
        return false;
    }

    node nodeArr[cnt];
    for(int i = 0, j = 0; i < 26; i++){
        if(freq[i] > 0){
            nodeArr[j].first = char(i + 'A');
            j++;
        }
    }

    return permutation(nodeArr, cnt, 0, s1, s2, s3);
}

int main(){

    string s1 = "SEND";
    string s2 = "MORE";
    string s3 = "MONEY";

    if(cryptArithmetic(s1, s2, s3) == false){
        cout << "No solution found" << endl;
    }

    return 0;
}