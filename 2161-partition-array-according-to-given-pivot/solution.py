class Solution:
    def pivotArray(self, nums: list[int], pivot: int) -> list[int]:
        n = len(nums)
        result = [0] * n
        left = 0
        right = n - 1
        
        # Pass 1: Fill elements smaller than pivot from left to right
        for num in nums:
            if num < pivot:
                result[left] = num
                left += 1
                
        # Pass 2: Fill elements larger than pivot from right to left
        for i in range(n - 1, -1, -1):
            if nums[i] > pivot:
                result[right] = nums[i]
                right -= 1
                
        # Pass 3: Fill the remaining middle section with the pivot
        while left <= right:
            result[left] = pivot
            left += 1
            
        return result