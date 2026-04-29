#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        // P[j][h] stores the sum of grid[0...h-1][j]
        vector<vector<long long>> P(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                P[j][i + 1] = P[j][i] + grid[i][j];
            }
        }

        // dp[h_curr][h_prev] = max score for columns 0 to j-1
        // where H_{j} = h_curr and H_{j-1} = h_prev
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

        // Base case: H_{-1} = 0. All H_0 are initialized with 0 score.
        // After j=0 loop, dp will store max score for column 0 given H_1 and H_0.
        
        for (int j = 0; j < n; ++j) {
            vector<vector<long long>> next_dp(n + 1, vector<long long>(n + 1, 0));
            for (int h_j = 0; h_j <= n; ++h_j) {
                // Precompute prefix and suffix maximums to transition H_{j-1} in O(1)
                // prefix_max_dp[k] = max_{h_prev <= k} dp[h_j][h_prev]
                vector<long long> prefix_max_dp(n + 1, 0);
                prefix_max_dp[0] = dp[h_j][0];
                for (int k = 1; k <= n; ++k) prefix_max_dp[k] = max(prefix_max_dp[k - 1], dp[h_j][k]);

                // suffix_max_dp_plus_P[k] = max_{h_prev >= k} (dp[h_j][h_prev] + P[j][h_prev])
                vector<long long> suffix_max_dp_plus_P(n + 2, -1);
                for (int k = n; k >= 0; --k) {
                    suffix_max_dp_plus_P[k] = max(suffix_max_dp_plus_P[k + 1], dp[h_j][k] + P[j][k]);
                }

                for (int h_next = 0; h_next <= n; ++h_next) {
                    long long current_score = 0;
                    if (h_j >= h_next) {
                        // Gain from H_{j-1} only if H_{j-1} > h_j
                        long long val1 = prefix_max_dp[h_j]; 
                        long long val2 = suffix_max_dp_plus_P[h_j + 1] - P[j][h_j];
                        current_score = max(val1, val2);
                    } else {
                        // Gain from H_{j+1} (which is h_next) OR H_{j-1}
                        long long val1 = prefix_max_dp[h_next] + P[j][h_next] - P[j][h_j];
                        long long val2 = suffix_max_dp_plus_P[h_next + 1] - P[j][h_j];
                        current_score = max(val1, val2);
                    }
                    next_dp[h_next][h_j] = current_score;
                }
            }
            dp = move(next_dp);
        }

        // Final answer: H_n is effectively 0
        long long ans = 0;
        for (int h = 0; h <= n; ++h) {
            ans = max(ans, dp[0][h]);
        }
        return ans;
    }
};