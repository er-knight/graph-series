from collections import deque as stack
from typing import List

# Cycle Detection in Directed Graph using DFS
# 
# Input Format :
# first line contains 2 space seperated integers n (number of nodes) and m (number of edges).
# each of next m lines contains u (starting node of edge) and v (ending node of edge).
# 
# Time Complexity  : O(n)
# 
# Space Complexity : O(n)  +  O(n)   +   O(n)   ≈ O(n) 
#                     ↑        ↑          ↑
#                   stack   visited  dfs_visited  
# 
# Reference : https://youtu.be/uzVUw90ZFIg

def is_cycle(n: int, adj_list: List[int]) -> List[int]:
    visited     = [False for i in range(n)]
    dfs_visited = [False for i in range(n)]

    for i in range(n):
        if not visited[i]:
            s = stack()
            s.append(i) # push

            while s: # stack is not empty
                node = s[-1] # top

                if not visited[node]:
                    visited[node] = True 
                    dfs_visited[node] = True
                else:
                    dfs_visited[node] = False
                    _ = s.pop() # pop

                for k in adj_list[node]:
                    if not visited[k]:
                        s.append(k)
                    elif dfs_visited[k]:
                        return True

    return False

if __name__ == "__main__":

    n, m = [int(x) for x in input().split()]
    adj_list = [[] for i in range(n)]

    for i in range(m):
        u, v = [int(x) for x in input().split()]
        adj_list[u - 1].append(v - 1)

    for i in range(n):
        print(f"{i + 1} -> ", end="")
        for j in adj_list[i]:
            print(f"{j + 1} ", end="")
        print()

    if is_cycle(n, adj_list):
        print("Cycle Detected")
    else:
        print("No Cycle Detected")

# Input :
# 6 7
# 1 2
# 1 3
# 1 4
# 2 5
# 3 6
# 4 6
# 5 1
# 
# Graph :
# https://github.com/er-knight/graph-series/blob/main/Graphs/Graph05.png
# 
# Output :
# 1 -> 2 3 4
# 2 -> 5 
# 3 -> 6 
# 4 -> 6 
# 5 -> 1 
# 6 ->  
# Cycle Detected