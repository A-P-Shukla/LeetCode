from typing import List

class Solution:
    def hasValidPath(self, grid: List[List[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        MAXL = 205                     # m + n <= 200
        # dp[i][j] is a boolean list of possible balances
        dp = [[ [False] * MAXL for _ in range(n)] for _ in range(m)]

        def delta(c: str) -> int:
            return 1 if c == '(' else -1

        d0 = delta(grid[0][0])
        if d0 < 0:                     # cannot start with ')'
            return False
        dp[0][0][d0] = True

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                d = delta(grid[i][j])
                cur = [False] * MAXL

                # from top
                if i > 0:
                    for bal, ok in enumerate(dp[i-1][j]):
                        if ok:
                            nb = bal + d
                            if nb >= 0:
                                cur[nb] = True

                # from left
                if j > 0:
                    for bal, ok in enumerate(dp[i][j-1]):
                        if ok:
                            nb = bal + d
                            if nb >= 0:
                                cur[nb] = True

                # prune impossible balances
                steps_remain = (m - 1 - i) + (n - 1 - j)
                for bal in range(steps_remain + 1, MAXL):
                    cur[bal] = False

                dp[i][j] = cur

        return dp[m-1][n-1][0]