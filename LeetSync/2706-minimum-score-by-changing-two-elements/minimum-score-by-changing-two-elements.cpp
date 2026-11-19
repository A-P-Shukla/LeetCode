class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return 0;
        sort(nums.begin(), nums.end());

        long long ans = LLONG_MAX;
        if (n - 1 >= 2) ans = min(ans, (long long)nums[n - 1] - nums[2]);
        if (n - 3 >= 0) ans = min(ans, (long long)nums[n - 3] - nums[0]);
        if (n - 2 >= 1) ans = min(ans, (long long)nums[n - 2] - nums[1]);
        ans = min(ans, (long long)nums[n - 1] - nums[1]);
        ans = min(ans, (long long)nums[n - 2] - nums[0]);

        return ans;    
    }
};