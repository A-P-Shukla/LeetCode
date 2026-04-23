from collections import defaultdict
from typing import List

class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        # Map each number to the list of indices where it appears
        groups = defaultdict(list)
        for i, val in enumerate(nums):
            groups[val].append(i)
            
        for val in groups:
            indices = groups[val]
            k = len(indices)
            if k <= 1:
                continue
            
            # total_sum is used to calculate the sum of indices to the right efficiently
            total_sum = sum(indices)
            left_sum = 0
            
            for m, idx in enumerate(indices):
                # Number of elements to the left of indices[m] is m
                # Number of elements to the right of indices[m] is (k - 1 - m)
                right_sum = total_sum - left_sum - idx
                
                # Sum of (idx - left_indices)
                left_part = m * idx - left_sum
                # Sum of (right_indices - idx)
                right_part = right_sum - (k - 1 - m) * idx
                
                ans[idx] = left_part + right_part
                
                # Update prefix sum for the next index in the group
                left_sum += idx
                
        return ans