#include <bits/stdc++.h>
using namespace std;

#define state pair<vector<int>, vector<int>>
#define path vector<pair<vector<int>, vector<int>>>

set<state> vis;

bool isFinal(state curr, state goal)
{
    // cout << (curr.first == goal.first) << endl;
    return (curr.first == goal.first && curr.second == goal.second);
}

void printPath(path p)
{
    for (auto s : p)
    {
        vector<int> left = s.first;
        vector<int> right = s.second;
        for (auto it : left)
        {
            cout << it << " ";
        }
        cout << " | ";
        for (auto it : right)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<int> left, vector<int> right)
{
    return ((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0));
}

void dfs(state curr, state &goal, path &p)
{
    vis.insert(curr);
    if (isFinal(curr, goal))
    {
        printPath(p);
        return;
    }
    vector<int> left = curr.first;
    vector<int> right = curr.second;
    int n1 = left[0], m1 = left[1], b1 = left[2];
    int n2 = right[0], m2 = right[1], b2 = right[2];
    if (b1 == 1)
    {
        if (n1 >= 2)
        {
            vector<int> l = {n1 - 2, m1, 1 - b1};
            vector<int> r = {n2 + 2, m2, 1 - b2};
            if (!vis.count({l, r}) && isSafe(l, r))
            {
                state s = {l, r};
                p.push_back(s);
                dfs(s, goal, p);
                p.pop_back();
            }
        }
        if (n1 >= 1 && m1 >= 1)
        {
            vector<int> l = {n1 - 1, m1 - 1, 1 - b1};
            vector<int> r = {n2 + 1, m2 + 1, 1 - b2};
            if (!vis.count({l, r}) && isSafe(l, r))
            {
                state s = {l, r};
                p.push_back(s);
                dfs(s, goal, p);
                p.pop_back();
            }
        }
        if (m1 >= 2)
        {
            vector<int> l = {n1, m1 - 2, 1 - b1};
            vector<int> r = {n2, m2 + 2, 1 - b2};
            if (!vis.count({l, r}) && isSafe(l, r))
            {
                state s = {l, r};
                p.push_back(s);
                dfs(s, goal, p);
                p.pop_back();
            }
        }
        if (n1 >= 1)
        {
            vector<int> l = {n1 - 1, m1, 1 - b1};
            vector<int> r = {n2 + 1, m2, 1 - b2};
            if (!vis.count({l, r}) && isSafe(l, r))
            {
                state s = {l, r};
                p.push_back(s);
                dfs(s, goal, p);
                p.pop_back();
            }
        }
        if (m1 >= 1)
        {
            vector<int> l = {n1, m1 - 1, 1 - b1};
            vector<int> r = {n2, m2 + 1, 1 - b2};
            if (!vis.count({l, r}) && isSafe(l, r))
            {
                state s = {l, r};
                p.push_back(s);
                dfs(s, goal, p);
                p.pop_back();
            }
        }
    }
    else
    {
        if (n2 >= 2)
        {
            vector<int> l = {n1 + 2, m1, 1 - b1};
            vector<int> r = {n2 - 2, m2, 1 - b2};
            if (!vis.count({l, r}) && isSafe(l, r))
            {
                state s = {l, r};
                p.push_back(s);
                dfs(s, goal, p);
                p.pop_back();
            }
        }
        if (n2 >= 1 && m2 >= 1)
        {
            vector<int> l = {n1 + 1, m1 + 1, 1 - b1};
            vector<int> r = {n2 - 1, m2 - 1, 1 - b2};
            if (!vis.count({l, r}) && isSafe(l, r))
            {
                state s = {l, r};
                p.push_back(s);
                dfs(s, goal, p);
                p.pop_back();
            }
        }
        if (m2 >= 2)
        {
            vector<int> l = {n1, m1 + 2, 1 - b1};
            vector<int> r = {n2, m2 - 2, 1 - b2};
            if (!vis.count({l, r}) && isSafe(l, r))
            {
                state s = {l, r};
                p.push_back(s);
                dfs(s, goal, p);
                p.pop_back();
            }
        }
        if (n2 >= 1)
        {
            vector<int> l = {n1 + 1, m1, 1 - b1};
            vector<int> r = {n2 - 1, m2, 1 - b2};
            if (!vis.count({l, r}) && isSafe(l, r))
            {
                state s = {l, r};
                p.push_back(s);
                dfs(s, goal, p);
                p.pop_back();
            }
        }
        if (m2 >= 1)
        {
            vector<int> l = {n1, m1 + 1, 1 - b1};
            vector<int> r = {n2, m2 - 1, 1 - b2};
            if (!vis.count({l, r}) && isSafe(l, r))
            {
                state s = {l, r};
                p.push_back(s);
                dfs(s, goal, p);
                p.pop_back();
            }
        }
    }
}

int main()
{
    state initial = {{3, 3, 1}, {0, 0, 0}};
    state goal = {{0, 0, 0}, {3, 3, 1}};
    path ans;

    dfs(initial, goal, ans);
    return 0;
}
