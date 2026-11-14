class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + nums[i];

        const int INF = INT_MAX;
        int answer = INF;

        for (int j = l; j <= n; ++j) {
            int minLen = l;
            int maxLen = min(r, j); 
            for (int len = minLen; len <= maxLen; ++len) {
                int i = j - len;
                int sum = pref[j] - pref[i];
                if (sum > 0 && sum < answer) answer = sum;
            }
        }
        return (answer == INF) ? -1 : answer;
    }
};