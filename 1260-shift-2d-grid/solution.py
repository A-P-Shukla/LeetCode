from typing import List

class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        total = m * n
        
        # Effective shifts needed
        k %= total
        
        # Create a result grid initialized with zeros
        result = [[0] * n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                # Calculate flattened index
                old_idx = i * n + j
                # Calculate new flattened index after k shifts
                new_idx = (old_idx + k) % total
                
                # Map new flattened index back to 2D coordinates
                new_i, new_j = divmod(new_idx, n)
                
                result[new_i][new_j] = grid[i][j]
                
        return result