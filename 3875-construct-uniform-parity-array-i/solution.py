class Solution:
    def canMake(self, nums1: list[int]) -> bool:
        # Mathematically, it is always possible to construct such an array:
        # 1. If there are no odd numbers, all elements are already even.
        # 2. If there is at least one odd number, any even number can subtract 
        #    that odd number to become odd, making all elements in nums2 odd.
        return True