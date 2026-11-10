class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        const long long INF = (1LL << 60);
        long long dp[3];
        dp[0] = 0;                
        dp[1] = dp[2] = INF;      

        for (int i = 1; i <= n; ++i) {
            long long best = INF;
            for (int k = 1; k <= 3; ++k) {
                if (i - k < 0) continue;
                long long prev = dp[(i - k) % 3];
                long long cand = prev + static_cast<long long>(costs[i - 1]) + 1LL * k * k;
                if (cand < best) best = cand;
            }
            dp[i % 3] = best;
        }
        return dp[n % 3];
    }
};