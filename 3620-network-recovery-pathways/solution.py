import heapq

class Solution:
    def solve(self, n: int, edges: list[list[int]], online: list[bool], k: int) -> int:
        adj = [[] for _ in range(n)]
        max_cost = 0
        for u, v, c in edges:
            adj[u].append((v, c))
            max_cost = max(max_cost, c)
            
        def can_reach(min_threshold):
            # Dijkstra to find shortest path given min_threshold constraint
            dist = [-1] * n
            dist[0] = 0
            pq = [(0, 0)]
            
            while pq:
                d, u = heapq.heappop(pq)
                
                if d > dist[u] and dist[u] != -1:
                    continue
                if u == n - 1:
                    return d <= k
                
                for v, cost in adj[u]:
                    if cost >= min_threshold and (v == n - 1 or online[v]):
                        if dist[v] == -1 or dist[v] > d + cost:
                            dist[v] = d + cost
                            heapq.heappush(pq, (dist[v], v))
            return False

        low, high = 0, max_cost
        ans = -1
        
        while low <= high:
            mid = (low + high) // 2
            if can_reach(mid):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1
                
        return ans