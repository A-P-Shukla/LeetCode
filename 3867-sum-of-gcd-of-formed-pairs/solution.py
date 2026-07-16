import math
from typing import List

class Solution:
    def sumOfGcdOfFormedPairs(self, nums: List[int]) -> int:
        n = len(nums)
        prefix_gcd = [0] * n
        current_max = 0
        
        # Construct prefixGcd array
        for i in range(n):
            current_max = max(current_max, nums[i])
            prefix_gcd[i] = math.gcd(nums[i], current_max)
            
        # Sort to facilitate the smallest-largest pairing strategy
        prefix_gcd.sort()
        
        total_sum = 0
        left = 0
        right = n - 1
        
        # Use two pointers to pair smallest and largest
        while left < right:
            total_sum += math.gcd(prefix_gcd[left], prefix_gcd[right])
            left += 1
            right -= 1
            
        return total_sum