#include <bits/stdc++.h>
using namespace std;

#define state pair<vector<int>, vector<int>>
#define path vector<pair<vector<int>, vector<int>>>

bool isFinal(vector<int> &x, vector<int> &y, state &goal)
{
    return (x == goal.first && y == goal.second);
}

int heuristic(state curr, state goal)
{
    vector<int> r1 = curr.second;
    vector<int> r2 = goal.second;
    return (abs(r2[0] - r1[0]) + abs(r2[1] - r1[1]));
}

void bfs(state initial, state goal, int depth)
{
    path v;
    // int g = depth;
    int h = heuristic(initial, goal);
    priority_queue<pair<int, state>, vector<pair<int, state>>, greater<>> q;
    q.push({h, initial});

    while (!q.empty())
    {
        vector<int> x = q.top().second.first;
        vector<int> y = q.top().second.second;
        q.pop();

        for (auto it : x)
        {
            cout << it << " ";
        }
        cout << " | ";
        for (auto it : y)
        {
            cout << it << " ";
        }
        cout << endl;

        int n1 = x[0], m1 = x[1], b1 = x[2];
        int n2 = y[0], m2 = y[1], b2 = y[2];

        if (isFinal(x, y, goal))
        {
            cout << "Solution found" << endl;
            break;
        }
        if (b1 == 1)
        {
            if (n1 >= 2)
            {
                vector<int> left = {n1 - 2, m1, 1 - b1};
                vector<int> right = {n2 + 2, m2, 1 - b2};
                if ((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0))
                {
                    // g = depth + 1;
                    h = heuristic({left, right}, goal);
                    q.push({h, {left, right}});
                }
            }
            if (n1 >= 1 && m1 >= 1)
            {
                vector<int> left = {n1 - 1, m1 - 1, 1 - b1};
                vector<int> right = {n2 + 1, m2 + 1, 1 - b2};
                if ((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0))
                {
                    // g = depth + 1;
                    h = heuristic({left, right}, goal);
                    q.push({h, {left, right}});
                }
            }
            if (m1 >= 2)
            {
                vector<int> left = {n1, m1 - 2, 1 - b1};
                vector<int> right = {n2, m2 + 2, 1 - b2};
                if ((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0))
                {
                    // g = depth + 1;
                    h = heuristic({left, right}, goal);
                    q.push({h, {left, right}});
                }
            }
            if (n1 >= 1)
            {
                vector<int> left = {n1 - 1, m1, 1 - b1};
                vector<int> right = {n2 + 1, m2, 1 - b2};
                if ((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0))
                {
                    // g = depth + 1;
                    h = heuristic({left, right}, goal);
                    q.push({h, {left, right}});
                }
            }
            if (m1 >= 1)
            {
                vector<int> left = {n1, m1 - 1, 1 - b1};
                vector<int> right = {n2, m2 + 1, 1 - b2};
                if ((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0))
                {
                    // g = depth + 1;
                    h = heuristic({left, right}, goal);
                    q.push({h, {left, right}});
                }
            }
        }
        else
        {
            if (n2 >= 2)
            {
                // g = depth + 1;
                vector<int> left = {n1 + 2, m1, 1 - b1};
                vector<int> right = {n2 - 2, m2, 1 - b2};
                if ((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0))
                {
                    // g = depth + 1;
                    h = heuristic({left, right}, goal);
                    q.push({h, {left, right}});
                }
            }
            if (n2 >= 1 && m2 >= 1)
            {
                vector<int> left = {n1 + 1, m1 + 1, 1 - b1};
                vector<int> right = {n2 - 1, m2 - 1, 1 - b2};
                if ((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0))
                {
                    // g = depth + 1;
                    h = heuristic({left, right}, goal);
                    q.push({h, {left, right}});
                }
            }
            if (m2 >= 2)
            {
                vector<int> left = {n1, m1 + 2, 1 - b1};
                vector<int> right = {n2, m2 - 2, 1 - b2};
                if ((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0))
                {
                    // g = depth + 1;
                    h = heuristic({left, right}, goal);
                    q.push({h, {left, right}});
                }
            }
            if (n2 >= 1)
            {
                vector<int> left = {n1 + 1, m1, 1 - b1};
                vector<int> right = {n2 - 1, m2, 1 - b2};
                if ((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0))
                {
                    // g = depth + 1;
                    h = heuristic({left, right}, goal);
                    q.push({h, {left, right}});
                }
            }
            if (m2 >= 1)
            {
                vector<int> left = {n1, m1 + 1, 1 - b1};
                vector<int> right = {n2, m2 - 1, 1 - b2};
                if ((left[0] >= left[1] || left[0] == 0) && (right[0] >= right[1] || right[0] == 0))
                {
                    // g = depth + 1;
                    h = heuristic({left, right}, goal);
                    q.push({h, {left, right}});
                }
            }
        }
    }
}

int main()
{

    state initialState = {{3, 3, 1}, {0, 0, 0}};
    state finalState = {{0, 0, 0}, {3, 3, 1}};

    bfs(initialState, finalState, 0);

    return 0;
}
