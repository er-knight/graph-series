# Adjacency Matrix Representation of Undirected Graph 
# 
# Input Format :
# first line contains 2 space seperated integers n (number of nodes) and m (number of edges).
# each of next m lines contains u (starting node of edge) and v (ending node of edge).
# 
# Space Complexity : O(n²)
# 
# Reference : https://youtu.be/bTtm2ky7I3Y

if __name__ == "__main__":
    
    n, m = [int(x) for x in input().split()]
    adj_matrix = [[0 for j in range(n)] for i in range(n)]

    for i in range(m):
        u, v = [int(x) for x in input().split()]
        adj_matrix[u - 1][v - 1] = 1
        adj_matrix[v - 1][u - 1] = 1

    for i in range(n):
        print(f"{i + 1} -> ", end="")
        for j in range(n):
            if adj_matrix[i][j] == 1:
                print(f"{j + 1} ", end="")
        print()

# Input :
# 5 7
# 1 2
# 2 4
# 2 3
# 1 3
# 3 4
# 1 5
# 5 3
# 
# Graph :
# https://github.com/er-knight/graph-series/blob/main/Graphs/Graph01.png
# 
# Output :
# 1 -> 2 3 5 
# 2 -> 1 3 4 
# 3 -> 1 2 4 5 
# 4 -> 2 3 
# 5 -> 1 3