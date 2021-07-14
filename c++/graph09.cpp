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
 * Space Complexity : O(n)  +  O(n)   +   O(n)   ≈ O(n) 
 *                     ↑        ↑          ↑
 *                   stack   visited  dfs_visited
 * 
 * Reference : https://youtu.be/uzVUw90ZFIg
 **/

bool is_cycle(int n, vector<int> adj_list[]) {
    vector<int> visited(n, 0), dfs_visited(n, 0); 

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            stack<int> s;
            s.push(i);

            while(!s.empty()) {
                int node = s.top();

                if (!visited[node]) {
                    visited[node] = 1;
                    dfs_visited[node] = 1;
                }
                else {
                    dfs_visited[node] = 0;
                    s.pop();
                }

                for (int& k : adj_list[node]) {
                    if (!visited[k]) {
                        s.push(k);
                    }
                    else if (dfs_visited[k]) {
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
 * 6 7
 * 1 2
 * 1 3
 * 1 4
 * 2 5
 * 3 6
 * 4 6
 * 5 1
 * 
 * Graph : 
 * https://github.com/er-knight/graph-series/blob/main/Graphs/Graph05.png
 * 
 * Output :
 * 1 -> 2 3 4
 * 2 -> 5 
 * 3 -> 6 
 * 4 -> 6 
 * 5 -> 1 
 * 6 ->  
 * Cycle Detected
 **/ 