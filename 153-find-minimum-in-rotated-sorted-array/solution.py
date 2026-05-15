class Solution:
    def findMin(self, nums: list[int]) -> int:
        left, right = 0, len(nums) - 1

        # Standard Binary Search setup
        while left < right:
            mid = left + (right - left) // 2

            # If the middle element is greater than the rightmost element,
            # it implies the rotation point (and thus the minimum) is to the right.
            if nums[mid] > nums[right]:
                left = mid + 1
            # If the middle element is smaller than the rightmost element,
            # the minimum is either at mid or to the left of mid.
            else:
                right = mid
        
        # After the loop, left == right, pointing to the minimum element.
        return nums[left]