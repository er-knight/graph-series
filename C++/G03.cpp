#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Breadth First Search on Undirected Graph 
 * 
 * Input Format :
 * first line contains 2 space seperated integers n (number of nodes) and m (number of edges).
 * each of next m lines contains u (starting node of edge) and v (ending node of edge).
 * 
 * Time Complexity  : O(n) 
 * 
 * Space Complexity : O(n)   +   O(n)   +   O(n)  ≈ O(n) 
 *                     ↑          ↑          ↑
 *                   queue  bfs_traversal visited 
 * 
 * Reference : https://youtu.be/UeE67iCK2lQ
 **/

vector<int> bfs(int n, vector<int> adj_list[]) {
    vector<int> bfs_traversal;
    vector<int> visited(n, 0); 
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                bfs_traversal.emplace_back(node);
                for (int& k : adj_list[node]) {
                    if (!visited[k]) {
                        q.push(k);
                        visited[k] = 1;
                    }
                }
            }
        }
    }
    return bfs_traversal;
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

    vector<int> bfs_traversal = bfs(n, adj_list);
    cout << "BFS : ";
    for (int& i : bfs_traversal) {
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
 * BFS : 1 2 3 7 5 4 6 
 **/