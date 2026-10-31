import sys

# Increase recursion depth for deep mirror resolutions if needed
sys.setrecursionlimit(2000)

class Solution:
    MOD = 1_000_000_007

    def uniquePaths(self, grid: list[list[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        
        # memo[i][j][dir] initialized to (-2, -2)
        memo = [[ [(-2, -2), (-2, -2)] for _ in range(n) ] for _ in range(m)]

        def resolve(i: int, j: int, dir: int) -> tuple[int, int]:
            res = memo[i][j][dir]
            if res[0] != -2:
                return res
            
            ni = i + (1 if dir == 1 else 0)
            nj = j + (1 if dir == 0 else 0)
            
            if ni < 0 or ni >= m or nj < 0 or nj >= n:
                memo[i][j][dir] = (-1, -1)
                return memo[i][j][dir]
            
            if grid[ni][nj] == 0:
                memo[i][j][dir] = (ni, nj)
                return memo[i][j][dir]
            
            memo[i][j][dir] = resolve(ni, nj, 1 - dir)
            return memo[i][j][dir]

        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1

        for i in range(m):
            for j in range(n):
                if dp[i][j] == 0:
                    continue

                # Direction 0: Move right
                r = resolve(i, j, 0)
                if r[0] != -1:
                    dp[r[0]][r[1]] = (dp[r[0]][r[1]] + dp[i][j]) % self.MOD

                # Direction 1: Move down
                d = resolve(i, j, 1)
                if d[0] != -1:
                    dp[d[0]][d[1]] = (dp[d[0]][d[1]] + dp[i][j]) % self.MOD

        return dp[m - 1][n - 1]
