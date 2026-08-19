from collections import Counter
from typing import List

class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)
        
        if k == 1:
            counts = Counter(nums)
            candidates = [x for x, count in counts.items() if count == 1]
            return max(candidates) if candidates else -1
            
        if k == n:
            return max(nums)
            
        counts = Counter(nums)
        candidates = []
        if counts[nums[0]] == 1:
            candidates.append(nums[0])
        if counts[nums[-1]] == 1:
            candidates.append(nums[-1])
            
        return max(candidates) if candidates else -1