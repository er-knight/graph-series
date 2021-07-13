#include <iostream>
using namespace std;

/**
 * Adjacency Matrix Representation of Undirected Graph 
 * 
 * Input Format :
 * first line contains 2 space seperated integers n (number of nodes) and m (number of edges).
 * each of next m lines contains u (starting node of edge) and v (ending node of edge).
 * 
 * Space Complexity : O(n²)
 * 
 * Reference : https://youtu.be/bTtm2ky7I3Y
 **/

int main() {
    int n, m;
    cin >> n >> m;

    int adj_matrix[n][n];

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj_matrix[u - 1][v - 1] = 1;
        adj_matrix[v - 1][u - 1] = 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << i + 1 << " -> ";
        for (int j=0; j < n; ++j) {
            if (adj_matrix[i][j] == 1) {
                cout << j + 1 << " ";
            }
        }
        cout << "\n";
    }
}

/**
 * Input :
 * 5 7
 * 1 2
 * 2 4
 * 2 3
 * 1 3
 * 3 4
 * 1 5
 * 5 3
 * 
 * Graph :
 * https://github.com/er-knight/graph-series/blob/main/Graphs/Graph01.png
 * 
 * Output :
 * 1 -> 2 3 5 
 * 2 -> 1 3 4 
 * 3 -> 1 2 4 5 
 * 4 -> 2 3 
 * 5 -> 1 3
 **/ 