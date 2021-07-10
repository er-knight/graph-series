#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Graph Coloring using DFS (Bipartite Graph) 
 * 
 * Bipartite Graph : 
 * ● graph whose vertices can be color using 2 colors,
 *   such that no two adjacent vertices have same color.
 * ● graph that does not contain any odd-length cycles.
 * 
 * Input Format :
 * first line contains 2 space seperated integers n (number of nodes) and m (number of edges).
 * each of next m lines contains u (starting node of edge) and v (ending node of edge).
 * 
 * Note : color of vertices can be 0 (not colored), 1 (first color) and -1 (second color).
 * 
 * Time Complexity  : O(n)
 * 
 * Space Complexity : O(n)  +  O(n)  ≈ O(n) 
 *                     ↑        ↑
 *                   stack    color  
 * 
 * Reference : https://youtu.be/uC884ske2uQ
 **/ 

bool is_bipartite(int n, vector<int> adj_list[]) {
    vector<int> color(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!color[i]) {
            stack<int> s;
            s.push(i);
            color[i] = 1;
            while(!s.empty()) {
                int node = s.top();
                s.pop();
                for (int& k : adj_list[node]) {
                    if (!color[k]) {
                        s.push(k);
                        color[k] = -color[node];
                    }
                    else if (color[k] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
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

    if (is_bipartite(n, adj_list)) {
        cout << "Bipartite Graph\n";
    }
    else {
        cout << "Not Bipartite Graph\n";
    }
}

/**
 * Input :
 * 8 8
 * 1 2
 * 2 3
 * 2 7
 * 3 4
 * 4 5
 * 5 6
 * 5 8
 * 6 7
 * 
 * Output :
 * 1 -> 2 
 * 2 -> 1 3 7 
 * 3 -> 2 4 
 * 4 -> 3 5 
 * 5 -> 4 6 8 
 * 6 -> 5 7 
 * 7 -> 2 6 
 * 8 -> 5 
 * Bipartite Graph
 **/ 