#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        
        // Compute the total sum of the array (which is pref[n-1])
        long long pref_sum = 0;
        for (int stone : stones) {
            pref_sum += stone;
        }

        // dp stores the maximum score difference starting from the current index.
        // Base case: dp[n-1] = pref[n-1]
        long long dp = pref_sum;

        // Traverse backwards from index n-1 down to 2
        // Update pref_sum to be pref[i-1] for each step
        for (int i = n - 1; i >= 2; --i) {
            pref_sum -= stones[i];
            dp = std::max(dp, pref_sum - dp);
        }

        return dp;
    }
};