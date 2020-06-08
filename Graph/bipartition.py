"""
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.
"""

from collections import defaultdict
class Solution:
    def possibleBipartition(self, N: int, dislikes: List[List[int]]) -> bool:
        graph=defaultdict(list)
        
        for i,j in dislikes:
            graph[i].append(j)
            graph[j].append(i)
        
        color = {}
        
        def dfs(node,c=0):
            if node in color:
                return color[node]==c
            color[node]=c
            
            return all(dfs(adj,c^1) for adj in graph[node])
        
        return all(dfs(node) for node in range(1,N+1) if node not in color)
