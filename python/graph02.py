# Adjacency List Representation of Undirected Graph 
# 
# Input Format :
# first line contains 2 space seperated integers n (number of nodes) and m (number of edges).
# each of next m lines contains u (starting node of edge) and v (ending node of edge).
# 
# Space Complexity : O(n+2×m) ≈ O(n+m) 
# 
# Note : 2×m is number of edges
# 
# Reference : https://youtu.be/bTtm2ky7I3Y

if __name__ == "__main__":

    n, m = [int(x) for x in input().split()]
    adj_list = [[] for i in range(n)]

    for i in range(m):
        u, v = [int(x) for x in input().split()]
        adj_list[u - 1].append(v - 1)
        adj_list[v - 1].append(u - 1)

    for i in range(n):
        print(f"{i + 1} → ", end="")
        for j in adj_list[i]:
            print(f"{j + 1} ", end="")
        print()

# Input :
# 5 7
# 1 2
# 1 3
# 1 5
# 2 3
# 2 4
# 3 4
# 3 5
# 
# Graph :
# https://github.com/er-knight/graph-series/blob/main/Graphs/Graph01.png
# 
# Output :
# 1 → 2 3 5 
# 2 → 1 3 4 
# 3 → 1 2 4 5 
# 4 → 2 3 
# 5 → 1 3 