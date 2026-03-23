#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;

        // Use long long to prevent overflow during intermediate calculations.
        // max_dp[i][j] stores the maximum product to reach cell (i, j).
        // min_dp[i][j] stores the minimum product to reach cell (i, j).
        vector<vector<long long>> max_dp(m, vector<long long>(n));
        vector<vector<long long>> min_dp(m, vector<long long>(n));

        // Initialize starting point
        max_dp[0][0] = min_dp[0][0] = grid[0][0];

        // Initialize first column (only one way: from above)
        for (int i = 1; i < m; ++i) {
            max_dp[i][0] = min_dp[i][0] = max_dp[i - 1][0] * grid[i][0];
        }

        // Initialize first row (only one way: from left)
        for (int j = 1; j < n; ++j) {
            max_dp[0][j] = min_dp[0][j] = max_dp[0][j - 1] * grid[0][j];
        }

        // Fill the DP table for the rest of the grid
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                long long val = grid[i][j];
                
                // Calculate possible products from top and left neighbors
                long long a = max_dp[i - 1][j] * val;
                long long b = min_dp[i - 1][j] * val;
                long long c = max_dp[i][j - 1] * val;
                long long d = min_dp[i][j - 1] * val;

                // max_dp[i][j] is the maximum of all four potential products
                max_dp[i][j] = max({a, b, c, d});
                // min_dp[i][j] is the minimum of all four potential products
                min_dp[i][j] = min({a, b, c, d});
            }
        }

        long long result = max_dp[m - 1][n - 1];

        // If the maximum product is negative, the problem requires returning -1.
        // Otherwise, return the product modulo 10^9 + 7.
        return result < 0 ? -1 : result % MOD;
    }
};