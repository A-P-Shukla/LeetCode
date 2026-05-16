class Solution:
    def findMin(self, nums: list[int]) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            mid = left + (right - left) // 2

            if nums[mid] > nums[right]:
                # The minimum must be in the right side of the pivot
                left = mid + 1
            elif nums[mid] < nums[right]:
                # The minimum is mid or to the left of mid
                right = mid
            else:
                # nums[mid] == nums[right]. 
                # We can't be sure which side contains the minimum.
                # However, since nums[mid] is the same as nums[right], 
                # we can safely reduce the search space by 1 from the right.
                right -= 1
        
        return nums[left]