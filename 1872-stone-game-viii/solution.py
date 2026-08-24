class Solution:
    def stoneGameVIII(self, stones: list[int]) -> int:
        n = len(stones)
        
        # Calculate total sum of all stones (which represents pref[n-1])
        pref_sum = sum(stones)
        
        # Base case: dp[n-1] = pref[n-1]
        dp = pref_sum
        
        # Iterate backwards from index n-1 down to 2
        # In each step, adjust pref_sum to represent pref[i-1]
        for i in range(n - 1, 1, -1):
            pref_sum -= stones[i]
            dp = max(dp, pref_sum - dp)
            
        return dp