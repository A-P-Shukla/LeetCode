from typing import List

class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        """
        Return the sum of squares of all special elements.
        An element at 1‑based index i is special if n % i == 0.
        """
        n = len(nums)
        total = 0
        for i in range(1, n + 1):          # 1‑based index
            if n % i == 0:                 # special element
                total += nums[i - 1] ** 2
        return total