#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        const int INF_NEG = -1e9;

        // 1. pre‑compute outdegree for each item
        vector<int> outdeg(n, 0);
        for (int i = 0; i < n; ++i) {
            int fi = items[i][0];
            for (int j = 0; j < n; ++j) if (i != j) {
                int fj = items[j][0];
                if (fj % fi == 0) ++outdeg[i];
            }
        }

        // 2. gain_i = 1 (the purchased copy) + outdeg_i
        vector<int> gain(n);
        vector<int> price(n);
        int minPrice = INT_MAX;
        for (int i = 0; i < n; ++i) {
            gain[i] = 1 + outdeg[i];
            price[i] = items[i][1];
            minPrice = min(minPrice, price[i]);
        }

        // 3. 0/1 knapsack DP over purchase cost
        vector<int> dp(budget + 1, INF_NEG);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int w = price[i];
            int v = gain[i];
            for (int c = budget; c >= w; --c) {
                dp[c] = max(dp[c], dp[c - w] + v);
            }
        }

        // 4. evaluate best total copies
        int best = 0;
        for (int c = 0; c <= budget; ++c) if (dp[c] != INF_NEG) {
            int extra = (budget - c) / minPrice;          // cheap copies after activation
            best = max(best, dp[c] + extra);
        }
        return best;
    }
};