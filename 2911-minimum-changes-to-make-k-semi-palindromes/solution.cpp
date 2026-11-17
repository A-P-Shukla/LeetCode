#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // compute minimal changes to make substring s[l..r] a semi‑palindrome
    int semiPalCost(const string& s, int l, int r) {
        int m = r - l + 1;
        const int INF = 1e9;
        int best = INF;
        // enumerate divisors d of m, 1 <= d < m
        vector<int> divs;
        for (int d = 1; d * d <= m; ++d) {
            if (m % d == 0) {
                if (d < m) divs.push_back(d);
                int d2 = m / d;
                if (d2 != d && d2 < m) divs.push_back(d2);
            }
        }
        for (int d : divs) {
            int groups = d;
            int len = m / d;               // length of each group
            int changes = 0;
            for (int offset = 0; offset < groups; ++offset) {
                // compare symmetric positions inside the group
                for (int i = 0; i < len / 2; ++i) {
                    int p1 = l + offset + i * d;
                    int p2 = l + offset + (len - 1 - i) * d;
                    if (s[p1] != s[p2]) ++changes;
                }
            }
            best = min(best, changes);
        }
        return best;
    }

    int minChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;
        // pre‑compute costs
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int l = 0; l < n; ++l) {
            for (int r = l + 1; r < n; ++r) {   // length >= 2, needed for a semi‑palindrome
                cost[l][r] = semiPalCost(s, l, r);
            }
        }

        // dp[i][p] = min cost for prefix length i using p parts
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int p = 1; p <= k && p <= i; ++p) {
                // try all possible previous cuts
                for (int j = p - 1; j < i; ++j) {   // j chars already partitioned
                    if (dp[j][p - 1] == INF) continue;
                    int curCost = cost[j][i - 1];
                    dp[i][p] = min(dp[i][p], dp[j][p - 1] + curCost);
                }
            }
        }
        return dp[n][k];
    }
};