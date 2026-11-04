class Solution:
    def minMoves(self, nums: List[int]) -> int:
        max_val = max(nums)            
        moves = sum(max_val - x for x in nums)
        return moves