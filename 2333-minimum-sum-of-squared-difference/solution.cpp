#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const long long INF = 1e18;
        int n = nums1.size();
        long long K = (long long)k1 + k2;               // total allowed unit moves
        // Compute absolute differences
        vector<int> diff(n);
        int maxDiff = 0;
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }

        // Frequency of each difference value
        vector<long long> cnt(maxDiff + 1, 0);
        for (int d : diff) cnt[d]++;

        long long ops = K;
        // Process from large differences down to 1
        for (int d = maxDiff; d > 0 && ops > 0; --d) {
            long long curCnt = cnt[d];          // number of elements exactly equal to d
            if (curCnt == 0) continue;
            // cumulative count of elements >= d (including those already shifted from higher buckets)
            long long cumulative = curCnt;
            // add any elements that were lifted from higher buckets in previous iterations
            // (cnt[d] already contains them because we always move counts downwards)
            if (ops >= cumulative) {
                // we can reduce all of them by 1
                cnt[d - 1] += cumulative;
                ops -= cumulative;
                cnt[d] = 0;
            } else {
                // only part of them can be reduced
                cnt[d] -= ops;
                cnt[d - 1] += ops;
                ops = 0;
                break;
            }
        }
        // Any remaining ops after all diffs are zero are useless (they would only increase the sum)

        long long answer = 0;
        for (int d = 0; d <= maxDiff; ++d) {
            if (cnt[d]) {
                answer += cnt[d] * (long long)d * (long long)d;
                if (answer > INF) answer = INF; // protect from overflow, though not needed per constraints
            }
        }
        return answer;
    }
};