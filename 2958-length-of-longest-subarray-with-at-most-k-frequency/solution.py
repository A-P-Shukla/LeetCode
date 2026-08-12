from collections import defaultdict

class Solution:
    def maxSubarrayLength(self, nums: list[int], k: int) -> int:
        freq = defaultdict(int)
        max_len = 0
        left = 0
        
        for right in range(len(nums)):
            # Include nums[right] in the current window
            freq[nums[right]] += 1
            
            # Shrink the window from the left until nums[right] frequency is at most k
            while freq[nums[right]] > k:
                freq[nums[left]] -= 1
                left += 1
            
            # Record the maximum length seen so far
            max_len = max(max_len, right - left + 1)
            
        return max_len