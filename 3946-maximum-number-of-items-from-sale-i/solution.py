from typing import List

class Solution:
    def maximumItems(self, items: List[List[int]], budget: int) -> int:
        n = len(items)

        # 1. outdegree: number of other items whose factor is a multiple of factor_i
        outdeg = [0] * n
        for i in range(n):
            fi = items[i][0]
            for j in range(n):
                if i == j:
                    continue
                if items[j][0] % fi == 0:
                    outdeg[i] += 1

        # 2. gain_i = 1 (its purchased copy) + outdeg_i
        gain = [1 + outdeg[i] for i in range(n)]
        price = [p for _, p in items]
        min_price = min(price)

        # 3. 0/1 knapsack DP where dp[c] = max total gain achievable with exact cost c
        INF_NEG = -10**9
        dp = [INF_NEG] * (budget + 1)
        dp[0] = 0
        for i in range(n):
            w = price[i]
            v = gain[i]
            for c in range(budget, w - 1, -1):
                if dp[c - w] != INF_NEG:
                    dp[c] = max(dp[c], dp[c - w] + v)

        # 4. Choose the best cost and add cheap extra copies
        ans = 0
        for c in range(budget + 1):
            if dp[c] == INF_NEG:
                continue
            extra = (budget - c) // min_price
            ans = max(ans, dp[c] + extra)

        return ans