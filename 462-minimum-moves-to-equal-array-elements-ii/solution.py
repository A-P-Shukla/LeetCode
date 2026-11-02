from typing import List

class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        """
        Return the minimum number of moves to make all elements equal.
        The optimal target is any median of the sorted array.
        """
        nums.sort()
        n = len(nums)
        median = nums[n // 2]                 # median for both even/odd lengths
        moves: int = 0
        for x in nums:
            moves += abs(x - median)
        return moves