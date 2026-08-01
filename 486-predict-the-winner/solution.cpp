#include <vector>
#include <algorithm>

class Solution {
public:
    bool predictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        // dp[j] will store the maximum score difference for subarray nums[i...j]
        std::vector<int> dp(n, 0);

        // Fill DP table bottom-up
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = nums[i]; // Base case: single element subarray
            for (int j = i + 1; j < n; ++j) {
                // dp[j] on LHS is dp[i][j]
                // dp[j] on RHS is dp[i+1][j]
                // dp[j-1] on RHS is dp[i][j-1]
                dp[j] = std::max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }

        // If score difference for whole array is >= 0, Player 1 wins or ties
        return dp[n - 1] >= 0;
    }
};