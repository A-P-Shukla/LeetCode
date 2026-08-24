class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        n = len(stones)
        
        pref_sum = sum(stones)
        
        dp = pref_sum
        
        for i in range(n - 1, 1, -1):
            pref_sum -= stones[i]
            dp = max(dp, pref_sum - dp)
            
        return dp