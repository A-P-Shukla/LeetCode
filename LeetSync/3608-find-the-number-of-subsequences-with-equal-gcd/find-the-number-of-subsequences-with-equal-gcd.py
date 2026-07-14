import math
from functools import lru_cache

class Solution:
    def subsequencePairCount(self, nums: list[int]) -> int:
        n = len(nums)
        MOD = 10**9 + 7

        @lru_cache(None)
        def dp(idx, g1, g2):
            if idx == n:
                return 1 if (g1 > 0 and g1 == g2) else 0
            
            res = dp(idx + 1, g1, g2)
            
            new_g1 = nums[idx] if g1 == 0 else math.gcd(g1, nums[idx])
            res = (res + dp(idx + 1, new_g1, g2)) % MOD
            
            new_g2 = nums[idx] if g2 == 0 else math.gcd(g2, nums[idx])
            res = (res + dp(idx + 1, g1, new_g2)) % MOD
            
            return res
            
        return dp(0, 0, 0)