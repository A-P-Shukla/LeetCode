class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        total_sum = sum(nums)
        target = total_sum - x
        
        # Edge cases
        if target == 0:
            return len(nums)
        if target < 0:
            return -1
        
        max_len = -1
        current_sum = 0
        left = 0
        n = len(nums)
        
        # Sliding window to find the maximum length subarray that sums to target
        for right in range(n):
            current_sum += nums[right]
            
            # Shrink window if current_sum exceeds target
            while current_sum > target and left <= right:
                current_sum -= nums[left]
                left += 1
                
            # If target sum is reached, record maximum length
            if current_sum == target:
                max_len = max(max_len, right - left + 1)
                
        return -1 if max_len == -1 else n - max_len