#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MAXL = 205;                     // max possible balance (m+n <= 200)
        vector<vector<bitset<MAXL>>> dp(m, vector<bitset<MAXL>>(n));

        auto delta = [&](char c) { return c == '(' ? 1 : -1; };

        // start cell
        int d0 = delta(grid[0][0]);
        if (d0 < 0) return false;                  // cannot start with ')'
        dp[0][0][d0] = 1;

        // fill DP
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;   // already initialized
                int d = delta(grid[i][j]);
                bitset<MAXL> cur;

                // from top
                if (i > 0) {
                    for (int bal = 0; bal < MAXL; ++bal) {
                        if (!dp[i-1][j][bal]) continue;
                        int nb = bal + d;
                        if (nb >= 0) cur[nb] = 1;
                    }
                }
                // from left
                if (j > 0) {
                    for (int bal = 0; bal < MAXL; ++bal) {
                        if (!dp[i][j-1][bal]) continue;
                        int nb = bal + d;
                        if (nb >= 0) cur[nb] = 1;
                    }
                }

                // prune balances that cannot be closed in remaining steps
                int stepsRemaining = (m - 1 - i) + (n - 1 - j);
                for (int bal = stepsRemaining + 1; bal < MAXL; ++bal)
                    cur[bal] = 0;

                dp[i][j] = cur;
            }
        }
        return dp[m-1][n-1][0];
    }
};