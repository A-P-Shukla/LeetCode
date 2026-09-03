class Solution:
    def canConstructArray(self, nums1: list[int]) -> bool:
        min_val = min(nums1)
        all_even = all(x % 2 == 0 for x in nums1)
        
        # We can succeed if the minimum element is odd (making all elements odd)
        # or if all elements are already even (making all elements even).
        return (min_val % 2 != 0) or all_even