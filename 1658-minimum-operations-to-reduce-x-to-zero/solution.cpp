#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int x) {
        // Calculate the total sum of the array
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        // Target sum for the inner contiguous subarray
        long long target = total_sum - x;
        
        // Edge cases
        if (target == 0) {
            return nums.size(); // Must remove all elements
        }
        if (target < 0) {
            return -1; // Sum of elements is strictly less than x
        }
        
        int n = nums.size();
        int max_len = -1;
        long long current_sum = 0;
        int left = 0;
        
        // Sliding window to find the longest subarray summing to 'target'
        for (int right = 0; right < n; ++right) {
            current_sum += nums[right];
            
            // Shrink window from the left if current sum exceeds target
            while (current_sum > target && left <= right) {
                current_sum -= nums[left];
                left++;
            }
            
            // Check if valid subarray found
            if (current_sum == target) {
                max_len = std::max(max_len, right - left + 1);
            }
        }
        
        return (max_len == -1) ? -1 : (n - max_len);
    }
};