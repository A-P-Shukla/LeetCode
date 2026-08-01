class Solution:
    def predictTheWinner(self, nums: list[int]) -> bool:
        n = len(nums)
        # dp[j] stores max relative score difference for subarray nums[i...j]
        dp = [0] * n

        # Fill DP table bottom-up from end to start
        for i in range(n - 1, -1, -1):
            dp[i] = nums[i]  # Base case: single element subarray
            for j in range(i + 1, n):
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1])

        # If relative score for the full array is >= 0, Player 1 wins
        return dp[n - 1] >= 0