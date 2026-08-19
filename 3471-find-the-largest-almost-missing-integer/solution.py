from collections import Counter
from typing import List

class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)
        
        # Case 1: Subarrays of size 1 are just individual elements.
        if k == 1:
            counts = Counter(nums)
            candidates = [x for x, count in counts.items() if count == 1]
            return max(candidates) if candidates else -1
            
        # Case 2: Only one subarray of size n (the whole array).
        if k == n:
            return max(nums)
            
        # Case 3: 1 < k < n. Only boundary elements can be unique to a single subarray.
        counts = Counter(nums)
        candidates = []
        if counts[nums[0]] == 1:
            candidates.append(nums[0])
        if counts[nums[-1]] == 1:
            candidates.append(nums[-1])
            
        return max(candidates) if candidates else -1