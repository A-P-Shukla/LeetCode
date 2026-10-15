class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int MAXV = 100;                 
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            vector<bool> seen(MAXV + 1, false);
            int distinct = 0;
            for (int j = i; j < n; ++j) {
                if (!seen[nums[j]]) {
                    seen[nums[j]] = true;
                    ++distinct;
                }
                ans += 1LL * distinct * distinct;
            }
        }
        return ans;
    }
};