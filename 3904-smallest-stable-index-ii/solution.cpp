#include <vector>
#include <algorithm>

class Solution {
public:
    int firstStableIndex(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // suffix_min[i] will store the minimum value in nums[i..n-1]
        std::vector<int> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1];
        
        for (int i = n - 2; i >= 0; --i) {
            suffix_min[i] = std::min(nums[i], suffix_min[i + 1]);
        }
        
        // Track the running maximum of nums[0..i]
        int prefix_max = nums[0];
        for (int i = 0; i < n; ++i) {
            prefix_max = std::max(prefix_max, nums[i]);
            
            // Check if the instability score is <= k
            if (prefix_max - suffix_min[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};