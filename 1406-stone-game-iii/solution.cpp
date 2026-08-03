#include <vector>
#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::string stoneGameIII(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // dp[i % 4] stores the max score difference (current player - opponent)
        // starting from index i to the end of the array.
        std::vector<int> dp(4, 0);

        // Process from right to left (bottom-up DP)
        for (int i = n - 1; i >= 0; --i) {
            int maxDiff = INT_MIN;
            int currentTake = 0;

            // Try taking 1, 2, or 3 stones
            for (int k = 1; k <= 3 && i + k <= n; ++k) {
                currentTake += stoneValue[i + k - 1];
                maxDiff = std::max(maxDiff, currentTake - dp[(i + k) % 4]);
            }
            
            dp[i % 4] = maxDiff;
        }

        int scoreDiff = dp[0];
        if (scoreDiff > 0) return "Alice";
        if (scoreDiff < 0) return "Bob";
        return "Tie";
    }
};