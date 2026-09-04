class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        // suff_min[i] stores the minimum value in nums[i..n-1]
        std::vector<int> suff_min(n);
        suff_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suff_min[i] = std::min(nums[i], suff_min[i + 1]);
        }

        int curr_max = nums[0];
        
        for (int i = 0; i < n; ++i) {
            curr_max = max(curr_max, nums[i]);
            
            if (curr_max - suff_min[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};