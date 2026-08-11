class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum_val = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum_val += nums[i];
            } else {
                break;
            }
        }
        
        unordered_set<int> num_set(nums.begin(), nums.end());
        
        while (num_set.count(sum_val)) {
            sum_val++;
        }
        
        return sum_val;
    }
};