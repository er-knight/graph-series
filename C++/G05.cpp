#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Cycle Detection in Undirected Graph using BFS
 * 
 * Input Format :
 * first line contains 2 space seperated integers n (number of nodes) and m (number of edges).
 * each of next m lines contains u (starting node of edge) and v (ending node of edge).
 * 
 * Time Complexity  : O(n)
 * 
 * Space Complexity : O(n)  +  O(n)  ≈ O(n) 
 *                     ↑        ↑
 *                   queue   visited  
 * 
 * Reference : https://youtu.be/A8ko93TyOns
 **/ 

bool is_cycle(int n, vector<int> adj_list[]) {
    vector<int> visited(n, 0); 
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            queue<pair<int, int>> q;
            q.push({i, -1});
            visited[i] = 1;
            while(!q.empty()) {
                int node = q.front().first;
                int prev = q.front().second;
                q.pop();
                for (int& k : adj_list[node]) {
                    if (!visited[k]) {
                        q.push({k, node});
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
        adj_list[v - 1].emplace_back(u - 1);
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
 * 8 7
 * 1 3
 * 3 4
 * 2 5
 * 5 6
 * 5 8
 * 6 7
 * 7 8
 * 
 * Output :
 * 1 -> 3 
 * 2 -> 5 
 * 3 -> 1 4 
 * 4 -> 3 
 * 5 -> 2 6 8 
 * 6 -> 5 7 
 * 7 -> 6 8 
 * 8 -> 5 7 
 * Cycle Detected
 **/ 