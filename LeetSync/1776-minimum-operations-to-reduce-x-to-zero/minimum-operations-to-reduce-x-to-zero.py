class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        total_sum = sum(nums)
        target = total_sum - x
        
        if target == 0:
            return len(nums)
        if target < 0:
            return -1
        
        max_len = -1
        current_sum = 0
        left = 0
        n = len(nums)
        
        for right in range(n):
            current_sum += nums[right]
            
            while current_sum > target and left <= right:
                current_sum -= nums[left]
                left += 1
                
            if current_sum == target:
                max_len = max(max_len, right - left + 1)
                
        return -1 if max_len == -1 else n - max_len