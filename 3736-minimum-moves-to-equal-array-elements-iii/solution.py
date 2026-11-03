from typing import List

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        """
        Minimum moves to equalize array elements by only increasing.
        The optimal target is the current maximum.
        """
        max_val = max(nums)                 # O(n) scan for maximum
        # Sum of differences to max_val
        moves = sum(max_val - x for x in nums)
        return moves