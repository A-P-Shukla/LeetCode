class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        MAXX = 1024                 
        m, n = len(grid), len(grid[0])

        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1 << grid[0][0]   

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                mask = 0
                if i > 0:
                    up = dp[i-1][j]
                    while up:
                        v = (up & -up).bit_length() - 1   
                        mask |= 1 << (v ^ grid[i][j])
                        up &= up - 1                      
                if j > 0:
                    left = dp[i][j-1]
                    while left:
                        v = (left & -left).bit_length() - 1
                        mask |= 1 << (v ^ grid[i][j])
                        left &= left - 1
                dp[i][j] = mask

        final_mask = dp[m-1][n-1]
        for v in range(MAXX):
            if final_mask >> v & 1:
                return v
        return -1  