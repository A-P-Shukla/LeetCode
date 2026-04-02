class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        m, n = len(coins), len(coins[0])
        
        # dp[i][j][k] represents the max coins at cell (i, j) with k neutralizations used.
        # Initialize with negative infinity
        dp = [[[-float('inf')] * 3 for _ in range(n)] for _ in range(m)]
        
        # Base case: Starting cell
        dp[0][0][0] = coins[0][0]
        # At (0,0), we can use one neutralization if it's a robber
        dp[0][0][1] = max(coins[0][0], 0)
        dp[0][0][2] = max(coins[0][0], 0)
        
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                
                for k in range(3):
                    res = -float('inf')
                    
                    # Option 1: Arrive from Top
                    if i > 0:
                        # Case: Don't neutralize current cell
                        res = max(res, dp[i-1][j][k] + coins[i][j])
                        # Case: Neutralize current cell (if it's a robber and we have k left)
                        if k > 0 and coins[i][j] < 0:
                            res = max(res, dp[i-1][j][k-1])
                            
                    # Option 2: Arrive from Left
                    if j > 0:
                        # Case: Don't neutralize current cell
                        res = max(res, dp[i][j-1][k] + coins[i][j])
                        # Case: Neutralize current cell
                        if k > 0 and coins[i][j] < 0:
                            res = max(res, dp[i][j-1][k-1])
                            
                    dp[i][j][k] = res
                    
        # Return the max value reaching the bottom-right corner with at most 2 neutralizations
        return int(dp[m-1][n-1][2])