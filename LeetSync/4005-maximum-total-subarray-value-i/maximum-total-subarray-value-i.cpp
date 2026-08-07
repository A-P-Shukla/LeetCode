class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int max_val = nums[0];
        int min_val = nums[0];

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max_val)
                max_val = nums[i];
            
            if(nums[i] < min_val)
                min_val = nums[i];
        }

        return 1LL * (max_val - min_val) * k;
    }
};