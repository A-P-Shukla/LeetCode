import math
from typing import List

class Solution:
    def findGCD(self, nums: List[int]) -> int:
        # Find the smallest and largest numbers in the array
        min_val = min(nums)
        max_val = max(nums)
        
        # Calculate and return the greatest common divisor using math.gcd
        return math.gcd(min_val, max_val)