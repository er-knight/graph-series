from collections import deque as stack
from typing import List

# Depth First Search on Undirected Graph 
# 
# Input Format :
# first line contains 2 space seperated integers n (number of nodes) and m (number of edges).
# each of next m lines contains u (starting node of edge) and v (ending node of edge).
# 
# Time Complexity  : O(n) 
# 
# Space Complexity : O(n)   +   O(n)   +   O(n)  ≈ O(n) 
#                     ↑          ↑          ↑
#                   stack  dfs_traversal visited 
# 
# Reference : https://youtu.be/uDWljP2PGmU

def dfs(n: int, adj_list: List[int]) -> List[int]:
    dfs_traversal = []
    visited = [False for i in range(n)] 
    for i in range(n):
        if not visited[i]:
            s = stack()
            s.append(i) # push
            visited[i] = True
            while s: # q not empty
                node = s.pop() # top
                dfs_traversal.append(node)
                for k in adj_list[node]:
                    if not visited[k]:
                        s.append(k)
                        visited[k] = True

    return dfs_traversal

if __name__ == "__main__":

    n, m = [int(x) for x in input().split()]
    adj_list = [[] for i in range(n)]

    for i in range(m):
        u, v = [int(x) for x in input().split()]
        adj_list[u - 1].append(v - 1)
        adj_list[v - 1].append(u - 1)

    for i in range(n):
        print(f"{i + 1} -> ", end="")
        for j in adj_list[i]:
            print(f"{j + 1} ", end="")
        print()

    dfs_traversal = dfs(n, adj_list)
    print("DFS : ", end="")
    for i in dfs_traversal:
        print(f"{i + 1} ", end="")
    print()

# Input :
# 7 6
# 1 2
# 2 3
# 2 7
# 3 5
# 4 6
# 5 7
# 
# Output :
# 1 -> 2 
# 2 -> 1 3 7 
# 3 -> 2 5 
# 4 -> 6 
# 5 -> 3 7 
# 6 -> 4 
# 7 -> 2 5
# DFS : 1 2 7 5 3 4 6 