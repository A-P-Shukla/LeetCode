#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[j][c] stores the maximum score at column j with cost c
        // Initializing with -1 to represent unreachable states
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        // Starting point (0, 0) is guaranteed to be grid[0][0] == 0
        dp[0][0] = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int score_inc = grid[i][j];
                int cost_inc = (grid[i][j] > 0) ? 1 : 0;

                for (int c = k; c >= 0; --c) {
                    int prev_max = -1;

                    // Case 1: Coming from the top (same column, previous row)
                    // The value dp[j][c] currently holds the value from the previous row
                    if (i > 0 && c >= cost_inc) {
                        prev_max = max(prev_max, dp[j][c - cost_inc]);
                    }

                    // Case 2: Coming from the left (previous column, same row)
                    // The value dp[j-1][c] has already been updated for the current row
                    if (j > 0 && c >= cost_inc) {
                        prev_max = max(prev_max, dp[j - 1][c - cost_inc]);
                    }
                    
                    // Specific logic for (0,0) as it has no neighbors
                    if (i == 0 && j == 0) {
                        // dp[0][0] is already set to 0, which is correct
                        continue; 
                    }

                    if (prev_max != -1) {
                        dp[j][c] = prev_max + score_inc;
                    } else {
                        dp[j][c] = -1;
                    }
                }
            }
        }

        int max_score = -1;
        for (int c = 0; c <= k; ++c) {
            max_score = max(max_score, dp[n - 1][c]);
        }

        return max_score;
    }
};