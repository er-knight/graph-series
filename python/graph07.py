from helper import queue
from typing import List

# Graph Coloring using BFS (Bipartite Graph) 
# 
# Bipartite Graph : 
# ● graph whose vertices can be color using 2 colors,
#   such that no two adjacent vertices have same color.
# ● graph that does not contain any odd-length cycles.
# 
# Input Format :
# first line contains 2 space seperated integers n (number of nodes) and m (number of edges).
# each of next m lines contains u (starting node of edge) and v (ending node of edge).
# 
# Note : color of vertices can be 0 (not colored), 1 (first color) and -1 (second color).
# 
# Time Complexity  : O(n)
# 
# Space Complexity : O(n)  +  O(n)  ≈ O(n) 
#                     ↑        ↑
#                   queue    color  
# 
# Reference : https://youtu.be/nbgaEu-pvkU 

def is_bipartite(n: int, adj_list: List[int]) -> List[int]:
    color = [0 for i in range(n)] 

    for i in range(n):
        if not color[i]:
            q = queue()
            q.push(i) 
            color[i] = 1

            while not q.empty(): 
                node = q.front()
                q.pop()

                for k in adj_list[node]:
                    if not color[k]:
                        q.push(k)
                        color[k] = -color[node]

                    elif color[k] == color[node]:
                        return False

    return True

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

    if is_bipartite(n, adj_list):
        print("Bipartite Graph")
    else:
        print("Not Bipartite Graph")

# Input :
# 8 8
# 1 2
# 2 3
# 2 7
# 3 4
# 4 5
# 5 6
# 5 8
# 6 7
# 
# Graph :
# https://github.com/er-knight/graph-series/blob/main/graphs/graph04.png
# 
# Output :
# 1 → 2 
# 2 → 1 3 7 
# 3 → 2 4 
# 4 → 3 5 
# 5 → 4 6 8 
# 6 → 5 7 
# 7 → 2 6 
# 8 → 5 
# Bipartite Graph