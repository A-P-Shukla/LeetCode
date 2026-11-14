#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPositiveSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        // Prefix sums: pref[i] = sum of first i elements (0‑based, pref[0]=0)
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + nums[i];

        const int INF = INT_MAX;
        int answer = INF;

        // j is the exclusive end index of the subarray
        for (int j = l; j <= n; ++j) {
            // length ranges from l to r, ensure i = j - len >= 0
            int minLen = l;
            int maxLen = min(r, j); // cannot exceed j
            for (int len = minLen; len <= maxLen; ++len) {
                int i = j - len;            // start index (inclusive)
                int sum = pref[j] - pref[i];
                if (sum > 0 && sum < answer) answer = sum;
            }
        }
        return (answer == INF) ? -1 : answer;
    }
};