class Solution:
    def missingMultiple(self, nums: list[int], k: int) -> int:
        # Convert list to set for O(1) average time lookup
        num_set = set(nums)
        
        # Start checking from the first positive multiple of k
        multiple = k
        
        # Increment by k until a missing multiple is found
        while multiple in num_set:
            multiple += k
            
        return multiple