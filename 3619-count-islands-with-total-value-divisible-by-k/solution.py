from collections import deque
from typing import List

class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]

        def bfs(sr: int, sc: int) -> int:
            """Return total sum of the island starting at (sr, sc)."""
            q = deque()
            q.append((sr, sc))
            visited[sr][sc] = True
            total = 0
            while q:
                r, c = q.popleft()
                total += grid[r][c]
                for dr, dc in ((-1,0),(1,0),(0,-1),(0,1)):
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < m and 0 <= nc < n:
                        if grid[nr][nc] > 0 and not visited[nr][nc]:
                            visited[nr][nc] = True
                            q.append((nr, nc))
            return total

        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0 and not visited[i][j]:
                    island_sum = bfs(i, j)
                    if island_sum % k == 0:
                        ans += 1
        return ans