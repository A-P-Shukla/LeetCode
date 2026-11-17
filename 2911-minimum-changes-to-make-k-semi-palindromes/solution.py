from math import isqrt
from typing import List

class Solution:
    def _semi_pal_cost(self, s: str, l: int, r: int) -> int:
        """minimum changes to make s[l:r+1] a semi‑palindrome"""
        m = r - l + 1
        best = 10 ** 9
        # collect proper divisors of m (excluding m itself)
        divs: List[int] = []
        for d in range(1, isqrt(m) + 1):
            if m % d == 0:
                if d < m:
                    divs.append(d)
                d2 = m // d
                if d2 != d and d2 < m:
                    divs.append(d2)

        for d in divs:
            groups = d
            length = m // d            # length of each arithmetic progression
            changes = 0
            for offset in range(groups):
                for i in range(length // 2):
                    p1 = l + offset + i * d
                    p2 = l + offset + (length - 1 - i) * d
                    if s[p1] != s[p2]:
                        changes += 1
            best = min(best, changes)
        return best

    def minChanges(self, s: str, k: int) -> int:
        n = len(s)
        INF = 10 ** 9

        # pre‑compute costs for all substrings of length >= 2
        cost = [[0] * n for _ in range(n)]
        for l in range(n):
            for r in range(l + 1, n):
                cost[l][r] = self._semi_pal_cost(s, l, r)

        # dp[i][p] = min cost for prefix s[:i] split into p parts
        dp = [[INF] * (k + 1) for _ in range(n + 1)]
        dp[0][0] = 0

        for i in range(1, n + 1):
            for p in range(1, min(k, i) + 1):
                # try all possible previous cut positions
                for j in range(p - 1, i):
                    if dp[j][p - 1] == INF:
                        continue
                    cur = cost[j][i - 1]   # substring s[j:i]
                    dp[i][p] = min(dp[i][p], dp[j][p - 1] + cur)

        return dp[n][k]