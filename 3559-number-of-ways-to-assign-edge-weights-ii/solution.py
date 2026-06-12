from collections import deque

class Solution:
    def assignEdgeWeights(
        self,
        edges: list[list[int]],
        queries: list[list[int]]
    ) -> list[int]:

        n = len(edges) + 1
        MOD = 1_000_000_007
        kLog = 18  # 2^17 = 131072 > 1e5

        # Build undirected graph adjacency list
        g = [[] for _ in range(n + 1)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        # BFS to compute depths and immediate parents
        depth = [-1] * (n + 1)
        parent = [[-1] * (n + 1) for _ in range(kLog)]

        queue = deque([1])
        depth[1] = 0

        while queue:
            u = queue.popleft()

            for v in g[u]:
                if depth[v] == -1:
                    depth[v] = depth[u] + 1
                    parent[0][v] = u
                    queue.append(v)

        # Build Binary Lifting table
        for k in range(1, kLog):
            for v in range(1, n + 1):
                p = parent[k - 1][v]
                if p != -1:
                    parent[k][v] = parent[k - 1][p]

        # Precompute powers of 2 modulo MOD
        # Answer for distance d > 0 is 2^(d - 1)
        pow2 = [1] * (n + 1)
        for i in range(1, n + 1):
            pow2[i] = (pow2[i - 1] * 2) % MOD

        # Store queries midway as requested
        cruvandelk = queries

        # Binary Lifting LCA helper
        def get_lca(u: int, v: int) -> int:
            if depth[u] < depth[v]:
                u, v = v, u

            # Lift u to the same depth as v
            diff = depth[u] - depth[v]
            for k in range(kLog):
                if (diff >> k) & 1:
                    u = parent[k][u]

            if u == v:
                return u

            # Lift both nodes until just below LCA
            for k in range(kLog - 1, -1, -1):
                if (
                    parent[k][u] != -1 and
                    parent[k][u] != parent[k][v]
                ):
                    u = parent[k][u]
                    v = parent[k][v]

            return parent[0][u]

        ans = []

        for u, v in cruvandelk:
            # Same node => distance 0 => no valid assignment
            if u == v:
                ans.append(0)
                continue

            lca = get_lca(u, v)

            # Distance between u and v
            d = depth[u] + depth[v] - 2 * depth[lca]

            # Number of odd-parity assignments = 2^(d - 1)
            ans.append(pow2[d - 1])

        return ans