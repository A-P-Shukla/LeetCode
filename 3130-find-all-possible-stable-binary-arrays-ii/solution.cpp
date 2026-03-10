#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Finds the total number of stable binary arrays with exactly 'zero' zeros
     * and 'one' ones, where no more than 'limit' identical digits are consecutive.
     */
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        
        // dp[i][j][0] : stable arrays with i zeros, j ones, ending in 0
        // dp[i][j][1] : stable arrays with i zeros, j ones, ending in 1
        // Using vector on heap to prevent stack overflow for 1001x1001x2 array
        vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));
        
        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                // Base Case: No digits
                if (i == 0 && j == 0) continue;
                
                // Base Case: Only zeros (valid only if within limit)
                if (j == 0) {
                    if (i <= limit) dp[i][0][0] = 1;
                    continue;
                }
                
                // Base Case: Only ones (valid only if within limit)
                if (i == 0) {
                    if (j <= limit) dp[0][j][1] = 1;
                    continue;
                }
                
                // Transition for ending in 0:
                // We add a '0' to any sequence of (i-1, j).
                // However, we must subtract sequences that already had 'limit' zeros at the end.
                // Those specific sequences are exactly the ones that ended in '1' at (i-limit-1, j).
                long long val0 = (long long)dp[i - 1][j][0] + dp[i - 1][j][1];
                if (i > limit) {
                    // Subtract the illegal configuration: i-limit-1 zeros, then a 1, then limit zeros.
                    // If i == limit + 1, we subtract dp[0][j][1] (array starting with limit+1 zeros).
                    val0 -= dp[i - limit - 1][j][1];
                }
                dp[i][j][0] = (val0 % MOD + MOD) % MOD;
                
                // Transition for ending in 1:
                // Symmetric logic to the 0 case.
                long long val1 = (long long)dp[i][j - 1][0] + dp[i][j - 1][1];
                if (j > limit) {
                    val1 -= dp[i][j - limit - 1][0];
                }
                dp[i][j][1] = (val1 % MOD + MOD) % MOD;
            }
        }
        
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
