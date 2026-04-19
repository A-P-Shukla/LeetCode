class Solution:
    def maxDistance(self, nums1: list[int], nums2: list[int]) -> int:
        """
        Calculates the maximum distance j - i using a two-pointer technique.
        """
        i, j = 0, 0
        max_dist = 0
        n1, n2 = len(nums1), len(nums2)

        while i < n1 and j < n2:
            # Check the validity of the current pair (i, j)
            if nums1[i] <= nums2[j]:
                # Update max_dist if the current distance is larger
                # Python's max handles the case where j < i (negative result)
                if j >= i:
                    max_dist = max(max_dist, j - i)
                
                # Try expanding j to the right for a larger distance
                j += 1
            else:
                # nums1[i] is too large for the current nums2[j].
                # Move i to a smaller value (arrays are non-increasing).
                i += 1
                
        return max_dist