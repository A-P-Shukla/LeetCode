from typing import List

class Solution:
    def minXorPath(self, grid: List[List[int]]) -> int:
        MAXX = 1024                 # 10‑bit range
        m, n = len(grid), len(grid[0])

        # dp[i][j] is an int mask; bit v set => XOR value v reachable at (i,j)
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1 << grid[0][0]   # start cell

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                mask = 0
                if i > 0:
                    up = dp[i-1][j]
                    while up:
                        v = (up & -up).bit_length() - 1   # index of lowest set bit
                        mask |= 1 << (v ^ grid[i][j])
                        up &= up - 1                      # clear lowest set bit
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
        return -1  # unreachable (theoretically impossible)