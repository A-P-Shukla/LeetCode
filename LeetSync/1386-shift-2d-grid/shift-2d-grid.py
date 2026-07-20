from typing import List

class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        total = m * n
        
        k %= total
        
        result = [[0] * n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                old_idx = i * n + j
                new_idx = (old_idx + k) % total
                
                new_i, new_j = divmod(new_idx, n)
                
                result[new_i][new_j] = grid[i][j]
                
        return result