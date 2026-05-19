class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        # Initialize two pointers for both arrays
        i, j = 0, 0
        n, m = len(nums1), len(nums2)
        
        # Iterate while pointers are within the bounds of both arrays
        while i < n and j < m:
            if nums1[i] == nums2[j]:
                # Found the smallest common element
                return nums1[i]
            elif nums1[i] < nums2[j]:
                # Move the pointer of the smaller element forward
                i += 1
            else:
                # Move the pointer of the smaller element forward
                j += 1
                
        # If the loop finishes without returning, no common element exists
        return -1