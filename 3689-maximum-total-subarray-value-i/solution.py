from typing import List

class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        if not nums:
            return 0
        
        # The optimal strategy is to choose the subarray containing both 
        # the global maximum and global minimum, and repeat it k times.
        return (max(nums) - min(nums)) * k