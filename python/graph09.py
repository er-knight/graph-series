from helper import stack
from typing import List

# Cycle Detection in Directed Graph using DFS
# 
# Input Format :
# first line contains 2 space seperated integers n (number of nodes) and m (number of edges).
# each of next m lines contains u (starting node of edge) and v (ending node of edge).
# 
# Time Complexity  : O(n)
# 
# Space Complexity : O(n)  +  O(n)  +  O(n)   ≈ O(n) 
#                     ↑        ↑        ↑
#                   stack   visited  on_stack  
# 
# Reference : https://youtu.be/uzVUw90ZFIg

def is_cycle(n: int, adj_list: List[int]) -> List[int]:
    visited  = [False for i in range(n)]
    on_stack = [False for i in range(n)]

    for i in range(n):
        if not visited[i]:
            s = stack()
            s.push(i)

            while not s.empty():
                node = s.top()

                if not visited[node]:
                    visited[node]  = True 
                    on_stack[node] = True
                else:
                    on_stack[node] = False
                    s.pop()

                for k in adj_list[node]:
                    if not visited[k]:
                        s.push(k)
                    elif on_stack[k]:
                        return True

    return False

if __name__ == "__main__":

    n, m = [int(x) for x in input().split()]
    adj_list = [[] for i in range(n)]

    for i in range(m):
        u, v = [int(x) for x in input().split()]
        adj_list[u - 1].append(v - 1)

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
# https://github.com/er-knight/graph-series/blob/main/graphs/graph05.png
# 
# Output :
# 1 → 2 3 4 
# 2 → 5 
# 3 → 6 
# 4 → 6 
# 5 → 1 
# 6 → 
# Cycle Detected