class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int val = num % k;
            vector<long long> next_dp(k, 0);
            
            next_dp[val]++;

            for (int x = 0; x < k; ++x) {
                if (dp[x] > 0) {
                    next_dp[(x * val) % k] += dp[x];
                }
            }

            for (int x = 0; x < k; ++x) {
                result[x] += next_dp[x];
            }

            dp = move(next_dp);
        }

        return result;
    }
};