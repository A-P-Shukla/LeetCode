class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        ALL_BITS = (1 << 30) - 1          
        k = ALL_BITS
        has_misplaced = False
        for i, val in enumerate(nums):
            if val != i:                  
                has_misplaced = True
                k &= i                    
                k &= val                  
        return 0 if not has_misplaced else k