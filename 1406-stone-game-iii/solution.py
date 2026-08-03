class Solution:
    def stoneGameIII(self, stoneValue: list[int]) -> str:
        n = len(stoneValue)
        
        # dp[i % 4] stores the max score difference (current player - opponent)
        # starting from index i to the end of the array.
        dp = [0] * 4

        # Process from right to left (bottom-up DP)
        for i in range(n - 1, -1, -1):
            max_diff = float('-inf')
            current_take = 0
            
            # Try taking 1, 2, or 3 stones
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