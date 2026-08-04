from typing import List

class Solution:
    def findMissingIntegers(self, nums: List[int]) -> List[int]:
        # Determine the boundaries of the original contiguous range
        min_val, max_val = min(nums), max(nums)
        
        # Store existing numbers in a set for O(1) average lookup time
        present = set(nums)
        
        # Collect and return all numbers in [min_val, max_val] not present in nums
        return [x for x in range(min_val, max_val + 1) if x not in present]