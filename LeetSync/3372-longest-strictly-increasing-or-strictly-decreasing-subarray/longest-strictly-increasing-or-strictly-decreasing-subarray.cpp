class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() == 1) return 1;

        int inc_len = 1;    
        int dec_len = 1;    
        int ans = 1;        

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1])
                ++inc_len;
            else
                inc_len = 1;               

            if (nums[i] < nums[i - 1])
                ++dec_len;
            else
                dec_len = 1;               

            ans = max({ans, inc_len, dec_len});
        }
        return ans;
    }
};