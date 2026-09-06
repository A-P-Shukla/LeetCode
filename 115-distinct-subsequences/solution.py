class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        
        # If s is shorter than t, it cannot contain t as a subsequence
        if m < n:
            return 0
        
        # dp[j] represents the number of subsequences of s matching t[:j]
        dp = [0] * (n + 1)
        dp[0] = 1  # Base case: empty string t can always be formed in 1 way
        
        for char_s in s:
            # Iterate backwards to reuse dp array from previous row
            for j in range(n, 0, -1):
                if char_s == t[j - 1]:
                    dp[j] += dp[j - 1]
                    
        return dp[n]