from helper import queue
from typing import List

# Breadth First Search on Undirected Graph 
# 
# Input Format :
# first line contains 2 space seperated integers n (number of nodes) and m (number of edges).
# each of next m lines contains u (starting node of edge) and v (ending node of edge).
# 
# Time Complexity  : O(n) 
# 
# Space Complexity : O(n)   +   O(n)   +   O(n)  ≈ O(n) 
#                     ↑          ↑          ↑
#                   queue  bfs_traversal visited 
# 
# Reference : https://youtu.be/UeE67iCK2lQ

def bfs(n: int, adj_list: List[int]) -> List[int]:
    bfs_traversal = []
    visited = [False for i in range(n)] 

    for i in range(n):
        if not visited[i]:
            q = queue()
            q.push(i)
            visited[i] = True

            while not q.empty(): 
                node = q.front()
                q.pop()
                bfs_traversal.append(node)
                
                for k in adj_list[node]:
                    if not visited[k]:
                        q.push(k)
                        visited[k] = True

    return bfs_traversal

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

    bfs_traversal = bfs(n, adj_list)
    print("BFS : ", end="")
    for i in bfs_traversal:
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
# Graph :
# https://github.com/er-knight/graph-series/blob/main/Graphs/Graph02.png
# 
# Output :
# 1 -> 2 
# 2 -> 1 3 7 
# 3 -> 2 5 
# 4 -> 6 
# 5 -> 3 7 
# 6 -> 4 
# 7 -> 2 5
# BFS : 1 2 3 7 5 4 6 