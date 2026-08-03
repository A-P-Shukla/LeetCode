class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        vector<int> dp(4, 0);

        for (int i = n - 1; i >= 0; --i) {
            int maxDiff = INT_MIN;
            int currentTake = 0;

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