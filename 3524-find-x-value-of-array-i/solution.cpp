#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int val = num % k;
            vector<long long> next_dp(k, 0);
            
            // Single-element subarray starting and ending at current index
            next_dp[val]++;

            // Extend existing subarrays ending at previous index
            for (int x = 0; x < k; ++x) {
                if (dp[x] > 0) {
                    next_dp[(x * val) % k] += dp[x];
                }
            }

            // Accumulate counts for all valid remainders ending at current index
            for (int x = 0; x < k; ++x) {
                result[x] += next_dp[x];
            }

            dp = move(next_dp);
        }

        return result;
    }
};