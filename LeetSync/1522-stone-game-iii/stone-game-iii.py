class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)

        dp = [0] * 4

        for i in range(n - 1, -1, -1):
            max_diff = float("-inf")
            current_take = 0

            for k in range(1, 4):
                if i + k <= n:
                    current_take += stoneValue[i + k - 1]
                    max_diff = max(max_diff, current_take - dp[(i + k) % 4])

            dp[i % 4] = max_diff

        score_diff = dp[0]
        if score_diff > 0:
            return "Alice"
        elif score_diff < 0:
            return "Bob"
        else:
            return "Tie"
