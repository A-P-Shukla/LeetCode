from collections import deque

class Solution:
    def findSafeWalk(self, grid: list[list[int]], health: int) -> bool:
        m, n = len(grid), len(grid[0])
        
        # min_lost[i][j] stores the minimum unsafe cells encountered to reach (i, j)
        min_lost = [[float('inf')] * n for _ in range(m)]
        
        # Check start cell
        if grid[0][0] >= health:
            return False
            
        min_lost[0][0] = grid[0][0]
        queue = deque([(0, 0)])
        
        while queue:
            r, c = queue.popleft()
            
            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nr, nc = r + dr, c + dc
                
                if 0 <= nr < m and 0 <= nc < n:
                    cost = grid[nr][nc]
                    if min_lost[r][c] + cost < health and min_lost[r][c] + cost < min_lost[nr][nc]:
                        min_lost[nr][nc] = min_lost[r][c] + cost
                        # 0-1 BFS: push 0-cost edges to front, 1-cost to back
                        if cost == 0:
                            queue.appendleft((nr, nc))
                        else:
                            queue.append((nr, nc))
                            
        return min_lost[m - 1][n - 1] < health