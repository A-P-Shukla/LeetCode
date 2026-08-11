from typing import List

class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        # Step 1: Calculate the sum of the longest sequential prefix
        sum_val = nums[0]
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1] + 1:
                sum_val += nums[i]
            else:
                break
        
        # Step 2: Store elements in a set for O(1) lookups
        num_set = set(nums)
        
        # Step 3: Find the smallest missing integer >= sum_val
        while sum_val in num_set:
            sum_val += 1
            
        return sum_val