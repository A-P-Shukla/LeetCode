class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const long long INF = 1e18;
        int n = nums1.size();
        long long K = (long long)k1 + k2; 
        vector<int> diff(n);
        int maxDiff = 0;
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }

        vector<long long> cnt(maxDiff + 1, 0);
        for (int d : diff) cnt[d]++;

        long long ops = K;
        for (int d = maxDiff; d > 0 && ops > 0; --d) {
            long long curCnt = cnt[d];          
            if (curCnt == 0) continue;
            long long cumulative = curCnt;
            if (ops >= cumulative) {
                cnt[d - 1] += cumulative;
                ops -= cumulative;
                cnt[d] = 0;
            } else {
                cnt[d] -= ops;
                cnt[d - 1] += ops;
                ops = 0;
                break;
            }
        }

        long long answer = 0;
        for (int d = 0; d <= maxDiff; ++d) {
            if (cnt[d]) {
                answer += cnt[d] * (long long)d * (long long)d;
                if (answer > INF) answer = INF; 
            }
        }
        return answer;
    }
};