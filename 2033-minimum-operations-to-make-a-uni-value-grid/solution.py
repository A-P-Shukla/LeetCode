class Solution:
    def minOperations(self, grid: list[list[int]], x: int) -> int:
        # Flatten the 2D grid into a 1D list
        nums = []
        for row in grid:
            nums.extend(row)
        
        # Check if it's possible to make all elements equal
        # All elements must have the same remainder when divided by x
        remainder = nums[0] % x
        for val in nums:
            if val % x != remainder:
                return -1
        
        # Sort the numbers to find the median
        nums.sort()
        
        # The target value that minimizes the sum of absolute differences is the median
        n = len(nums)
        median = nums[n // 2]
        
        # Calculate total operations to transform every element into the median
        total_operations = 0
        for val in nums:
            total_operations += abs(val - median) // x
            
        return total_operations