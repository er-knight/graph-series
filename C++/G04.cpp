#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Depth First Search on Undirected Graph 
 * 
 * Note : DFS uses stack while BFS uses queue.
 * 
 * Input Format :
 * first line contains 2 space seperated integers n (number of nodes) and m (number of edges).
 * each of next m lines contains u (starting node of edge) and v (ending node of edge).
 * 
 * Time Complexity  : O(n) 
 * 
 * Space Complexity : O(n)   +   O(n)   +   O(n)  ≈ O(n) 
 *                     ↑          ↑          ↑
 *                   stack  dfs_traversal visited  
 * 
 * Reference : https://youtu.be/uDWljP2PGmU
 **/

vector<int> dfs(int n, vector<int> adj_list[]) {
    vector<int> dfs_traversal;
    vector<int> visited(n, 0); 
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            stack<int> s;
            s.push(i);
            visited[i] = 1;
            while(!s.empty()) {
                int node = s.top();
                s.pop();
                dfs_traversal.emplace_back(node);
                for (int& k : adj_list[node]) {
                    if (!visited[k]) {
                        s.push(k);
                        visited[k] = 1;
                    }
                }
            }
        }
    }
    return dfs_traversal;
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

    vector<int> dfs_traversal = dfs(n, adj_list);
    cout << "DFS : ";
    for (int& i : dfs_traversal) {
        cout << i + 1 << " ";
    }
    cout << "\n";
}

/**
 * Input :
 * 7 6
 * 1 2
 * 2 3
 * 2 7
 * 3 5
 * 4 6
 * 5 7
 * 
 * Output :
 * 1 -> 2 
 * 2 -> 1 3 7 
 * 3 -> 2 5 
 * 4 -> 6 
 * 5 -> 3 7 
 * 6 -> 4 
 * 7 -> 2 5
 * DFS : 1 2 7 5 3 4 6
 **/