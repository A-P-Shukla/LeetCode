class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()
        n = len(nums)
        median = nums[n // 2]                 
        moves: int = 0
        for x in nums:
            moves += abs(x - median)
        return moves