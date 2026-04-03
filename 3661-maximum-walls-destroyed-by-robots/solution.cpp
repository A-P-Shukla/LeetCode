#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> r(n);
        for (int i = 0; i < n; ++i) {
            r[i] = {robots[i], distance[i]};
        }
        sort(r.begin(), r.end());
        sort(walls.begin(), walls.end());

        auto countInRange = [&](int low, int high) {
            if (low > high) return 0;
            auto it1 = lower_bound(walls.begin(), walls.end(), low);
            auto it2 = upper_bound(walls.begin(), walls.end(), high);
            return (int)distance(it1, it2);
        };

        // Walls at robot positions are always destroyed.
        int wallsAtRobots = 0;
        for (int i = 0; i < n; ++i) {
            if (binary_search(walls.begin(), walls.end(), r[i].first)) {
                wallsAtRobots++;
            }
        }

        // dp[i][0]: robot i fires Left
        // dp[i][1]: robot i fires Right
        vector<vector<int>> dp(n, vector<int>(2, 0));

        // Base case: first robot
        dp[0][0] = countInRange(r[0].first - r[0].second, r[0].first - 1);
        dp[0][1] = 0;

        for (int i = 0; i < n - 1; ++i) {
            int r_idx = r[i].first;
            int r_dist = r[i].second;
            int next_r_idx = r[i+1].first;
            int next_r_dist = r[i+1].second;

            // Walls in the gap (R_i, R_{i+1})
            int gap_low = r_idx + 1;
            int gap_high = next_r_idx - 1;

            // Only robot i+1 fires into gap (Left)
            int wL = countInRange(max(next_r_idx - next_r_dist, gap_low), gap_high);
            // Only robot i fires into gap (Right)
            int wR = countInRange(gap_low, min(r_idx + r_dist, gap_high));
            
            // Both fire into gap: Union of ranges
            int intersect_low = max(next_r_idx - next_r_dist, gap_low);
            int intersect_high = min(r_idx + r_dist, gap_high);
            int wBoth = wL + wR - countInRange(intersect_low, intersect_high);

            // dp[i+1][0] (next fires Left)
            dp[i+1][0] = max(dp[i][0] + wL, dp[i][1] + wBoth);
            // dp[i+1][1] (next fires Right)
            dp[i+1][1] = max(dp[i][0] + 0, dp[i][1] + wR);
        }

        int last_r_idx = r[n-1].first;
        int last_r_dist = r[n-1].second;
        int last_right_hit = countInRange(last_r_idx + 1, last_r_idx + last_r_dist);

        return wallsAtRobots + max(dp[n-1][0], dp[n-1][1] + last_right_hit);
    }
};