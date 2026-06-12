import math

class Solution:
    def countWays(self, n: int, edges: list[list[int]], queries: list[list[int]]) -> list[int]:
        MOD = 10**9 + 7
        LOG = (n).bit_length()
        adj = [[] for _ in range(n + 1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        up = [[1] * LOG for _ in range(n + 1)]
        depth = [0] * (n + 1)
        
        stack = [(1, 1, 0)]
        while stack:
            u, p, d = stack.pop()
            depth[u] = d
            up[u][0] = p
            for i in range(1, LOG):
                up[u][i] = up[up[u][i - 1]][i - 1]
            for v in adj[u]:
                if v != p:
                    stack.append((v, u, d + 1))
        
        def get_lca(u, v):
            if depth[u] < depth[v]:
                u, v = v, u
            for i in range(LOG - 1, -1, -1):
                if depth[u] - (1 << i) >= depth[v]:
                    u = up[u][i]
            if u == v:
                return u
            for i in range(LOG - 1, -1, -1):
                if up[u][i] != up[v][i]:
                    u = up[u][i]
                    v = up[v][i]
            return up[u][0]

        res = []
        for u, v in queries:
            if u == v:
                res.append(0)
            else:
                lca = get_lca(u, v)
                dist = depth[u] + depth[v] - 2 * depth[lca]
                res.append(pow(2, dist - 1, MOD))
        return res