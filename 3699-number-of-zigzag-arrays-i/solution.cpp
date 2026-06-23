#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int countZigzagArrays(int n, int l, int r) {
        int S = r - l + 1;
        int MOD = 1e9 + 7;

        // dp[val][0]: last step was up (prev < current)
        // dp[val][1]: last step was down (prev > current)
        vector<vector<long long>> dp(S, vector<long long>(2, 0));

        // Base case: length 2
        for (int i = 0; i < S; ++i) {
            for (int j = 0; j < S; ++j) {
                if (i < j) dp[j][0] = (dp[j][0] + 1) % MOD;
                else if (i > j) dp[j][1] = (dp[j][1] + 1) % MOD;
            }
        }

        for (int i = 3; i <= n; ++i) {
            vector<vector<long long>> next_dp(S, vector<long long>(2, 0));
            vector<long long> pref(S + 1, 0), suff(S + 1, 0);

            for (int v = 0; v < S; ++v) pref[v + 1] = (pref[v] + dp[v][1]) % MOD;
            for (int v = S - 1; v >= 0; --v) suff[v] = (suff[v + 1] + dp[v][0]) % MOD;

            for (int v = 0; v < S; ++v) {
                // To have state 0 (current > prev), prev must be < v, so sum dp[prev][1] for prev < v
                next_dp[v][0] = pref[v];
                // To have state 1 (current < prev), prev must be > v, so sum dp[prev][0] for prev > v
                next_dp[v][1] = suff[v + 1];
            }
            dp = next_dp;
        }

        long long ans = 0;
        for (int v = 0; v < S; ++v) {
            ans = (ans + dp[v][0] + dp[v][1]) % MOD;
        }
        return (int)ans;
    }
};