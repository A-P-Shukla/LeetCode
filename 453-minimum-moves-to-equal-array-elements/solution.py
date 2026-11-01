from typing import List

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        """
        Return the minimal number of moves to make all elements equal,
        where each move increments n-1 elements by 1.
        """
        # Minimum element is the target final value.
        mn = min(nums)
        # Sum of differences to the minimum.
        moves = sum(num - mn for num in nums)
        return moves