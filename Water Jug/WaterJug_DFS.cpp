#include <bits/stdc++.h>
using namespace std;

bool dfs(pair<int, int> curr, pair<int, int> end, vector<pair<int, int>> vec, set<pair<int, int>> &vis, int depth)
{
    // if (depth > 10)
    //     return false;

    bool ans = false;
    int x = curr.first;
    int y = curr.second;
    vis.insert(curr);

    if (curr == end)
    {
        cout << "Possible solution:" << endl;
        for (auto it : vec)
            cout << it.first << " " << it.second << endl;
        return true;
    }
    if (x < 4)
    {
        pair<int, int> node = {4, y};
        if (!vis.count(node))
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1))
                ans = true;
            vec.pop_back();
        }
    }
    if (y < 3)
    {
        pair<int, int> node = {x, 3};
        if (!vis.count(node))
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1))
                ans = true;
            vec.pop_back();
        }
    }
    if (x > 0)
    {
        pair<int, int> node = {0, y};
        if (!vis.count(node))
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1))
                ans = true;
            vec.pop_back();
        }
    }
    if (y > 0)
    {
        pair<int, int> node = {x, 0};
        if (!vis.count(node))
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1))
                ans = true;
            vec.pop_back();
        }
    }
    if (x + y >= 4 && y > 0)
    {
        pair<int, int> node = {4, y - (4 - x)};
        if (!vis.count(node))
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1))
                ans = true;
            vec.pop_back();
        }
    }
    if (x + y >= 3 && x > 0)
    {
        pair<int, int> node = {x - (3 - y), 3};
        if (!vis.count(node))
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1))
                ans = true;
            vec.pop_back();
        }
    }
    if (x + y <= 4 && y > 0)
    {
        pair<int, int> node = {x + y, 0};
        if (!vis.count(node))
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1))
                ans = true;
            vec.pop_back();
        }
    }
    if (x + y <= 3 && x > 0)
    {
        pair<int, int> node = {0, x + y};
        if (!vis.count(node))
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1))
                ans = true;
            vec.pop_back();
        }
    }
    return ans;
}

int main()
{
    pair<int, int> start = {0, 0};
    pair<int, int> end = {2, 0};
    vector<pair<int, int>> ans;
    set<pair<int, int>> vis;
    if (!dfs(start, end, ans, vis, 0))
        cout << "No possible solution." << endl;
    return 0;
}
