class Solution:
    def minimumDeletions(self, nums: list[int]) -> int:
        n = len(nums)
        if n <= 2:
            return n

        min_idx = nums.index(min(nums))
        max_idx = nums.index(max(nums))

        # Order the indices such that i is the leftmost and j is the rightmost
        i = min(min_idx, max_idx)
        j = max(min_idx, max_idx)

        # Evaluate the 3 possible deletion strategies
        return min(
            j + 1,             # Remove both from front
            n - i,             # Remove both from back
            (i + 1) + (n - j)  # Remove from both ends
        )
      
