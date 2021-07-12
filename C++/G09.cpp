#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Cycle Detection in Directed Graph using DFS
 * 
 * Input Format :
 * first line contains 2 space seperated integers n (number of nodes) and m (number of edges).
 * each of next m lines contains u (starting node of edge) and v (ending node of edge).
 * 
 * Time Complexity  : O(n)
 * 
 * Space Complexity : O(n)  +  O(n)  ≈ O(n) 
 *                     ↑        ↑
 *                   stack   visited  
 * 
 * Reference : https://youtu.be/uzVUw90ZFIg
 **/

bool is_cycle(int n, vector<int> adj_list[]) {
    vector<int> visited(n, 0); 
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            stack<pair<int, int>> s;
            s.push({i, -1});
            visited[i] = 1;
            while(!s.empty()) {
                int node = s.top().first;
                int prev = s.top().second;
                s.pop();
                for (int& k : adj_list[node]) {
                    if (!visited[k]) {
                        s.push({k, node});
                        visited[k] = 1;
                    }
                    else if (k != prev) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj_list[n];

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj_list[u - 1].emplace_back(v - 1);
    }

    for (int i = 0; i < n; ++i) {
        cout << i + 1 << " -> ";
        for (int& j : adj_list[i]) {
            cout << j + 1 << " ";
        }
        cout << "\n";
    }

    if (is_cycle(n, adj_list)) {
        cout << "Cycle Detected\n";
    }
    else {
        cout << "No Cycle Detected\n";
    }
}

/**
 * Input :
 * 7 7
 * 2 3
 * 3 1
 * 3 4
 * 4 5
 * 5 2
 * 5 7
 * 6 5
 * 
 * Output :
 * 1 -> 
 * 2 -> 3 
 * 3 -> 1 4 
 * 4 -> 5 
 * 5 -> 2 7 
 * 6 -> 5 
 * 7 -> 
 * Cycle Detected
 **/ 