#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        // dp[i][j][k] = max coins at (i, j) using k neutralizations
        // Use a small enough value for negative infinity
        long long INF = 1e16;
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, -INF)));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    dp[0][0][0] = coins[0][0];
                    // If the first cell is a robber, we can neutralize it
                    dp[0][0][1] = max((long long)coins[0][0], 0LL);
                    dp[0][0][2] = max((long long)coins[0][0], 0LL);
                    continue;
                }

                for (int k = 0; k < 3; ++k) {
                    long long fromUp = -INF;
                    long long fromLeft = -INF;

                    // Option 1: Move from above
                    if (i > 0) {
                        // Standard move: add current cell value
                        fromUp = dp[i-1][j][k] + coins[i][j];
                        // Neutralization move: if we have k > 0 and current is robber
                        if (k > 0 && coins[i][j] < 0) {
                            fromUp = max(fromUp, dp[i-1][j][k-1]);
                        }
                    }

                    // Option 2: Move from the left
                    if (j > 0) {
                        // Standard move: add current cell value
                        fromLeft = dp[i][j-1][k] + coins[i][j];
                        // Neutralization move: if we have k > 0 and current is robber
                        if (k > 0 && coins[i][j] < 0) {
                            fromLeft = max(fromLeft, dp[i][j-1][k-1]);
                        }
                    }

                    dp[i][j][k] = max(fromUp, fromLeft);
                }
            }
        }

        return dp[m - 1][n - 1][2];
    }
};