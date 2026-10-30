import heapq
from typing import List

class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], labels: str, k: int) -> int:
        INF = 10**18
        adj: List[List[tuple[int, int]]] = [[] for _ in range(n)]
        for u, v, w in edges:
            adj[u].append((v, w))

        # dist[node][run]  run ranges 1..k
        dist = [[INF] * (k + 1) for _ in range(n)]
        dist[0][1] = 0
        pq: List[tuple[int, int, int]] = [(0, 0, 1)]  # (dist, node, run)

        while pq:
            d, u, run = heapq.heappop(pq)
            if d != dist[u][run]:
                continue
            for v, w in adj[u]:
                new_run = run + 1 if labels[v] == labels[u] else 1
                if new_run > k:
                    continue
                nd = d + w
                if nd < dist[v][new_run]:
                    dist[v][new_run] = nd
                    heapq.heappush(pq, (nd, v, new_run))

        ans = min(dist[n - 1][1:])  # ignore index 0
        return -1 if ans == INF else ans