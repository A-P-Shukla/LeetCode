#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    long long MOD = 1e9 + 7;

public:
    int countStableArrays(int zero, int one, int limit) {
        // DP[z][o][0]: Number of stable arrays using exactly z zeros and o ones, ending with 0.
        // DP[z][o][1]: Number of stable arrays using exactly z zeros and o ones, ending with 1.
        // The dimensions are (zero + 1) x (one + 1) x 2.
        vector<vector<vector<long long>>> dp(zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2, 0)));

        // Base Cases: Arrays consisting only of 0s or only of 1s.
        // These are valid only if their length <= limit.
        for (int z = 1; z <= zero; ++z) {
            if (z <= limit) {
                dp[z][0][0] = 1;
            }
        }
        for (int o = 1; o <= one; ++o) {
            if (o <= limit) {
                dp[0][o][1] = 1;
            }
        }

        // Iterate through all possible counts (z, o)
        for (int z = 0; z <= zero; ++z) {
            for (int o = 0; o <= one; ++o) {
                if (z == 0 && o == 0) continue;

                // --- Calculate DP[z][o][0] (Ending in 0) ---
                // This sequence of 0s must be preceded by a sequence ending in 1,
                // OR it is a sequence of 0s starting the array (handled by base cases when o=0).
                if (o > 0) {
                    // Recurrence derived from prefix sums:
                    // DP[z][o][0] = Sum_{m=1 to min(z, limit)} DP[z-m][o][1]
                    
                    // 1. Start with the previous state DP[z-1][o][0]
                    if (z >= 1) {
                        // DP[z-1][o][0] covers sums up to m=limit-1 previously.
                        dp[z][o][0] = dp[z-1][o][0];
                    }
                    
                    // 2. Add the contribution from sequences ending in 1 that allowed extending to z:
                    // DP[z-1][o][1] represents the count where the sequence of 0s starts with length 1.
                    if (z >= 1) {
                        dp[z][o][0] = (dp[z][o][0] + dp[z-1][o][1]) % MOD;
                    }

                    // 3. Subtract the state that violates the limit (run length z > limit)
                    // The term DP[z-limit-1][o][1] corresponds to the count that forces a run of length limit+1.
                    if (z > limit) {
                        dp[z][o][0] = (dp[z][o][0] - dp[z - limit - 1][o][1] + MOD) % MOD;
                    }
                }


                // --- Calculate DP[z][o][1] (Ending in 1) ---
                // Symmetric calculation for sequences ending in 1.
                if (z > 0) {
                    // Recurrence derived from prefix sums:
                    // DP[z][o][1] = Sum_{m=1 to min(o, limit)} DP[z][o-m][0]
                    
                    // 1. Start with the previous state DP[z][o-1][1]
                    if (o >= 1) {
                        dp[z][o][1] = dp[z][o-1][1];
                    }

                    // 2. Add contribution from sequences ending in 0 that allowed extending to o:
                    if (o >= 1) {
                        dp[z][o][1] = (dp[z][o][1] + dp[z][o-1][0]) % MOD;
                    }

                    // 3. Subtract the state that violates the limit (run length o > limit)
                    if (o > limit) {
                        dp[z][o][1] = (dp[z][o][1] - dp[z][o - limit - 1][0] + MOD) % MOD;
                    }
                }
            }
        }

        // The total count is the sum of arrays ending in 0 and arrays ending in 1, using exact counts.
        long long result = (dp[zero][one][0] + dp[zero][one][1]) % MOD;
        
        return (int)result;
    }
};