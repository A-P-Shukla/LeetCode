class Solution:
    def maxPathScore(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        
        # dp[j][c] stores the max score reaching column j with total cost c
        # Initialized to -1 for unreachable states
        dp = [[-1] * (k + 1) for _ in range(n)]
        
        # Base case: start at (0, 0). grid[0][0] is always 0.
        dp[0][0] = 0
        
        for i in range(m):
            # We must process columns carefully to use current row vs previous row values
            for j in range(n):
                val = grid[i][j]
                cost_inc = 1 if val > 0 else 0
                score_inc = val
                
                # Special skip for the very first cell after initialization
                if i == 0 and j == 0:
                    continue
                
                # Update DP table for current cell (i, j)
                # We iterate backwards if updating in-place to avoid using the same cell twice,
                # but here we need to compare current row left neighbor and previous row top neighbor.
                for c in range(k, cost_inc - 1, -1):
                    res = -1
                    # From top (previous row, same column)
                    if i > 0:
                        res = max(res, dp[j][c - cost_inc])
                    # From left (same row, previous column)
                    if j > 0:
                        res = max(res, dp[j-1][c - cost_inc])
                    
                    if res != -1:
                        dp[j][c] = res + score_inc
                    else:
                        dp[j][c] = -1
                
                # If cost_inc was 1, cost 0 is no longer reachable at this cell
                if cost_inc > 0:
                    dp[j][0] = -1
                    
        ans = max(dp[n-1])
        return ans if ans >= 0 else -1