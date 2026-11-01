class Solution:
    def minMoves(self, nums: list[int]) -> int:
        mn = min(nums)
        moves = sum(num - mn for num in nums)
        return moves