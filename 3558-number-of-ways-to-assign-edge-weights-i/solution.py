import sys

# Increase recursion depth for deep trees
sys.setrecursionlimit(200000)

class Solution:
    def countWays(self, edges: list[list[int]]) -> int:
        n = len(edges) + 1
        adj = [[] for _ in range(n + 1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            
        max_depth = 0
        
        # DFS to find the maximum depth
        def dfs(u, p, d):
            nonlocal max_depth
            max_depth = max(max_depth, d)
            for v in adj[u]:
                if v != p:
                    dfs(v, u, d + 1)
        
        dfs(1, -1, 0)
        
        # The number of ways is 2^(L-1) where L is the path length (max_depth)
        MOD = 10**9 + 7
        return pow(2, max_depth - 1, MOD)