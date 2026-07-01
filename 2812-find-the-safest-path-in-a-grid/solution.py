import heapq
from collections import deque

class Solution:
    def maximumSafenessFactor(self, grid: list[list[int]]) -> int:
        n = len(grid)
        if grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return 0
            
        # Multi-source BFS to calculate distance from each cell to nearest thief
        dist = [[-1] * n for _ in range(n)]
        queue = deque()
        for r in range(n):
            for c in range(n):
                if grid[r][c] == 1:
                    dist[r][c] = 0
                    queue.append((r, c))
                    
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        while queue:
            r, c = queue.popleft()
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and dist[nr][nc] == -1:
                    dist[nr][nc] = dist[r][c] + 1
                    queue.append((nr, nc))
        
        # Priority Queue to find the path with max-min safeness (Dijkstra-like)
        # Store as (-safeness, r, c) for Max-Heap behavior
        pq = [(-dist[0][0], 0, 0)]
        visited = [[False] * n for _ in range(n)]
        visited[0][0] = True
        
        while pq:
            d, r, c = heapq.heappop(pq)
            d = -d
            
            if r == n - 1 and c == n - 1:
                return d
                
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and not visited[nr][nc]:
                    visited[nr][nc] = True
                    heapq.heappush(pq, (-min(d, dist[nr][nc]), nr, nc))
                    
        return 0