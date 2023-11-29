// #include <bits/stdc++.h>
// using namespace std;

// // Function to calculate heuristic value
// int heuristic(int x, int y, int target) {
//     return abs(x - target) + abs(y - target);
// }

// // Function to print the path
// void printPath(const vector<pair<int, int>>& path) {
//     for (const auto& state : path) {
//         cout << "(" << state.first << ", " << state.second << ") -> ";
//     }
//     cout << "Goal" << endl;
// }

// // Function to solve Water Jug problem using A* algorithm
// int waterJugAStar(int capacityX, int capacityY, int target, vector<pair<int, int>>& path) {
//     priority_queue<pair<int, int>> q;  // Queue for BFS
//     set<pair<int, int>> visited;  // Set to track visited states

//     q.push({0, 0});
//     visited.insert({0, 0});

//     while (!q.empty()) {
//         auto current = q.top();
//         q.pop();

//         int x = current.first;
//         int y = current.second;

//         path.push_back({x, y});  // Add the current state to the path

//         if (x == target || y == target) {
//             // Goal state reached
//             return 0;  // We are not tracking steps in this simplified version
//         }

//         // Pour water from jug X to jug Y
//         if (x > 0) {
//             int pourXToY = min(x, capacityY - y);
//             if (visited.insert({x - pourXToY, y + pourXToY}).second) {
//                 q.push({x - pourXToY, y + pourXToY});
//             }
//         }

//         // Pour water from jug Y to jug X
//         if (y > 0) {
//             int pourYToX = min(y, capacityX - x);
//             if (visited.insert({x + pourYToX, y - pourYToX}).second) {
//                 q.push({x + pourYToX, y - pourYToX});
//             }
//         }

//         // Empty jug X
//         if (x > 0) {
//             if (visited.insert({0, y}).second) {
//                 q.push({0, y});
//             }
//         }

//         // Empty jug Y
//         if (y > 0) {
//             if (visited.insert({x, 0}).second) {
//                 q.push({x, 0});
//             }
//         }

//         // Fill jug X
//         if (x < capacityX) {
//             if (visited.insert({capacityX, y}).second) {
//                 q.push({capacityX, y});
//             }
//         }

//         // Fill jug Y
//         if (y < capacityY) {
//             if (visited.insert({x, capacityY}).second) {
//                 q.push({x, capacityY});
//             }
//         }
//     }

//     // If the goal state is not reachable
//     return -1;
// }

// int main() {
//     int capacityX = 4;
//     int capacityY = 3;
//     int target = 2;

//     vector<pair<int, int>> path;
//     int result = waterJugAStar(capacityX, capacityY, target, path);

//     if (result != -1) {
//         cout << "Goal state is reachable. Path:" << endl;
//         printPath(path);
//     } else {
//         cout << "Goal state is not reachable." << endl;
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

// Function to calculate heuristic value
int heuristic(int x, int y, int target) {
    return abs(x - target) + abs(y - target);
}

// Function to print the path
void printPath(const vector<pair<int, int>>& path) {
    for (const auto& state : path) {
        cout << "(" << state.first << ", " << state.second << ") -> ";
    }
    cout << "Goal" << endl;
}

// Function to solve Water Jug problem using A* algorithm
int waterJugAStar(int capacityX, int capacityY, int target, vector<pair<int, int>>& path) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;  // Priority queue for A*
    set<pair<int, int>> visited;  // Set to track visited states

    q.push({heuristic(0, 0, target), {0, 0}});
    visited.insert({0, 0});

    while (!q.empty()) {
        auto current = q.top();
        q.pop();

        int x = current.second.first;
        int y = current.second.second;

        path.push_back({x, y});  // Add the current state to the path

        if (x == target || y == target) {
            // Goal state reached
            return 0;  // We are not tracking steps in this simplified version
        }

        // Pour water from jug X to jug Y
        if (x > 0) {
            int pourXToY = min(x, capacityY - y);
            if (visited.insert({x - pourXToY, y + pourXToY}).second) {
                q.push({heuristic(x - pourXToY, y + pourXToY, target) + 1, {x - pourXToY, y + pourXToY}});
            }
        }

        // Pour water from jug Y to jug X
        if (y > 0) {
            int pourYToX = min(y, capacityX - x);
            if (visited.insert({x + pourYToX, y - pourYToX}).second) {
                q.push({heuristic(x + pourYToX, y - pourYToX, target) + 1, {x + pourYToX, y - pourYToX}});
            }
        }

        // Empty jug X
        if (x > 0) {
            if (visited.insert({0, y}).second) {
                q.push({heuristic(0, y, target) + 1, {0, y}});
            }
        }

        // Empty jug Y
        if (y > 0) {
            if (visited.insert({x, 0}).second) {
                q.push({heuristic(x, 0, target) + 1, {x, 0}});
            }
        }

        // Fill jug X
        if (x < capacityX) {
            if (visited.insert({capacityX, y}).second) {
                q.push({heuristic(capacityX, y, target) + 1, {capacityX, y}});
            }
        }

        // Fill jug Y
        if (y < capacityY) {
            if (visited.insert({x, capacityY}).second) {
                q.push({heuristic(x, capacityY, target) + 1, {x, capacityY}});
            }
        }
    }

    // If the goal state is not reachable
    return -1;
}

int main() {
    int capacityX = 4;
    int capacityY = 3;
    int target = 2;

    vector<pair<int, int>> path;
    int result = waterJugAStar(capacityX, capacityY, target, path);

    if (result != -1) {
        cout << "Goal state is reachable. Path:" << endl;
        printPath(path);
    } else {
        cout << "Goal state is not reachable." << endl;
    }

    return 0;
}
