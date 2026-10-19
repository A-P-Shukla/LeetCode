from bisect import bisect_left, bisect_right
from typing import List

class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        # 1. Sort the array.
        nums.sort()
        # 2. Find leftmost index where target could be inserted.
        left = bisect_left(nums, target)
        # 3. Verify that target exists at that position.
        if left == len(nums) or nums[left] != target:
            return []
        # 4. Find rightmost exclusive index.
        right = bisect_right(nums, target)
        # 5. Return all indices in the inclusive range [left, right-1].
        return list(range(left, right))