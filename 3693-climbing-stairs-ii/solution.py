from typing import List

class Solution:
    def minCost(self, n: int, costs: List[int]) -> int:
        """
        Dynamic programming with O(1) auxiliary space.
        dp[i] = min cost to reach step i (0-indexed for step number).
        """
        INF = 10 ** 18
        dp = [0, INF, INF]  # dp[i % 3] stores cost for step i
        for i in range(1, n + 1):
            best = INF
            for k in (1, 2, 3):
                if i - k < 0:
                    continue
                prev = dp[(i - k) % 3]
                cand = prev + costs[i - 1] + k * k
                if cand < best:
                    best = cand
            dp[i % 3] = best
        return dp[n % 3]