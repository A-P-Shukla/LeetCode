from typing import List

class Solution:
    def maximumK(self, nums: List[int]) -> int:
        ALL_BITS = (1 << 30) - 1          # covers the maximum possible value (n ≤ 1e5)
        k = ALL_BITS
        has_misplaced = False
        for i, val in enumerate(nums):
            if val != i:                  # position i is not correct
                has_misplaced = True
                k &= i                    # include the correct value for this index
                k &= val                  # include the current value at this index
        return 0 if not has_misplaced else k