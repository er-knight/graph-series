from helper import queue
from typing import List

# Cycle Detection in Undirected Graph using BFS
# 
# Input Format :
# first line contains 2 space seperated integers n (number of nodes) and m (number of edges).
# each of next m lines contains u (starting node of edge) and v (ending node of edge).
# 
# Time Complexity  : O(n)
# 
# Space Complexity : O(n)  +  O(n)  ≈ O(n) 
#                     ↑        ↑
#                   queue   visited  
# 
# Reference : https://youtu.be/A8ko93TyOns

def is_cycle(n: int, adj_list: List[int]) -> List[int]:
    visited = [False for i in range(n)] 

    for i in range(n):
        if not visited[i]:
            q = queue()
            q.push((i, -1)) 
            visited[i] = True
            
            while not q.empty(): 
                node, prev = q.front() 
                q.pop()
                
                for k in adj_list[node]:
                    if not visited[k]:
                        q.push((k, node))
                        visited[k] = True
                        
                    elif k != prev:
                        return True

    return False

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

    if is_cycle(n, adj_list):
        print("Cycle Detected")
    else:
        print("No Cycle Detected")

# Input :
# 8 7
# 1 3
# 2 5
# 3 4
# 5 6
# 5 8
# 6 7
# 7 8
# 
# Graph :
# https://github.com/er-knight/graph-series/blob/main/graphs/graph03.png
# 
# Output :
# 1 → 3 
# 2 → 5 
# 3 → 1 4 
# 4 → 3 
# 5 → 2 6 8 
# 6 → 5 7 
# 7 → 6 8 
# 8 → 5 7 
# Cycle Detected