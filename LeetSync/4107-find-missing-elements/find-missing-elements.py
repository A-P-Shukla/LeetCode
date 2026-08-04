class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        min_val, max_val = min(nums), max(nums)
        
        present = set(nums)
        
        return [x for x in range(min_val, max_val + 1) if x not in present]