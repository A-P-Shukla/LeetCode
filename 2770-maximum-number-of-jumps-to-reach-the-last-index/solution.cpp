#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // dp[i] stores the maximum jumps to reach index i.
        // Initialize with -1 to indicate the index is currently unreachable.
        vector<int> dp(n, -1);
        
        // Base case: 0 jumps to reach the starting index.
        dp[0] = 0;
        
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                // Check if index i was reachable and if the jump condition is met.
                if (dp[i] != -1 && abs((long long)nums[j] - nums[i]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        
        // Return the value at the last index.
        return dp[n - 1];
    }
};