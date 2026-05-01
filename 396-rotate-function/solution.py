class Solution:
    def maxRotateFunction(self, nums: list[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        
        # Calculate the total sum of elements in the array
        total_sum = sum(nums)
        
        # Calculate the initial rotation function F(0)
        # F(0) = 0*nums[0] + 1*nums[1] + ... + (n-1)*nums[n-1]
        current_f = sum(i * val for i, val in enumerate(nums))
        
        max_f = current_f
        
        # Use the recurrence relation to find F(k) for k from 1 to n-1:
        # F(k) = F(k-1) + total_sum - n * nums[n-k]
        # We iterate backwards from the end of the array to pick nums[n-k]
        for k in range(1, n):
            current_f = current_f + total_sum - n * nums[n - k]
            if current_f > max_f:
                max_f = current_f
                
        return max_f