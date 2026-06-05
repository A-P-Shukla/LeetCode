#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
private:
    struct DPResult {
        long long count;
        long long sum_waviness;
    };

    // memo[idx][prev1 + 1][prev2 + 1][is_started]
    DPResult memo[17][12][12][2];

    DPResult dp(const string& S, int idx, int prev1, int prev2, bool is_less, bool is_started) {
        // Base case: if we've processed all digits
        if (idx == S.length()) {
            return is_started ? DPResult{1, 0} : DPResult{0, 0};
        }

        // Return memoized result if available (only cache states where we are already strictly less than S)
        if (is_less && memo[idx][prev1 + 1][prev2 + 1][is_started].count != -1) {
            return memo[idx][prev1 + 1][prev2 + 1][is_started];
        }

        int limit = is_less ? 9 : (S[idx] - '0');
        long long total_count = 0;
        long long total_waviness = 0;

        for (int d = 0; d <= limit; ++d) {
            bool next_is_less = is_less || (d < limit);
            bool next_is_started = is_started || (d > 0);
            int next_prev1 = -1;
            int next_prev2 = -1;
            long long waviness_add = 0;

            if (next_is_started) {
                if (!is_started) {
                    // First digit placed
                    next_prev1 = d;
                    next_prev2 = -1;
                    waviness_add = 0;
                } else {
                    next_prev1 = d;
                    next_prev2 = prev1;
                    if (prev2 != -1) {
                        // We have 3 digits to check if prev1 is a peak or valley
                        bool is_peak = (prev1 > prev2) && (prev1 > d);
                        bool is_valley = (prev1 < prev2) && (prev1 < d);
                        waviness_add = (is_peak || is_valley) ? 1 : 0;
                    }
                }
            }

            DPResult res = dp(S, idx + 1, next_prev1, next_prev2, next_is_less, next_is_started);
            total_count += res.count;
            total_waviness += res.sum_waviness + waviness_add * res.count;
        }

        if (is_less) {
            memo[idx][prev1 + 1][prev2 + 1][is_started] = {total_count, total_waviness};
        }

        return {total_count, total_waviness};
    }

    long long solve(long long N) {
        if (N <= 0) return 0;
        string S = to_string(N);
        memset(memo, -1, sizeof(memo));
        return dp(S, 0, -1, -1, false, false).sum_waviness;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};