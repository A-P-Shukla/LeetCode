class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        
        # suff_min[i] stores the minimum value in nums[i..n-1]
        suff_min = [0] * n
        suff_min[-1] = nums[-1]
        
        for i in range(n - 2, -1, -1):
            suff_min[i] = min(nums[i], suff_min[i + 1])
            
        curr_max = nums[0]
        
        # Traverse left-to-right to maintain prefix maximum and check stability
        for i in range(n):
            curr_max = max(curr_max, nums[i])
            
            # Instability score: max(nums[0..i]) - min(nums[i..n-1])
            if curr_max - suff_min[i] <= k:
                return i
                
        return -1