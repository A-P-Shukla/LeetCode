class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> occur;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                occur.push_back(i);
        }

        int n = occur.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + occur[i];
        }

        long long left = k / 2;
        long long right = k - 1 - left;

        long long saves = left * (left + 1) / 2 + right * (right + 1) / 2;

        long long ans = LLONG_MAX;

        for (int i = 0; i <= n - k; i++) {
            int j = i + k - 1;
            int mid = i + k / 2;

            long long left_sum = (long long)(mid - i) * occur[mid] - (prefix[mid] - prefix[i]);

            long long right_sum = (prefix[j + 1] - prefix[mid + 1]) - (long long)(j - mid) * occur[mid];

            long long res = left_sum + right_sum - saves;

            ans = min(ans, res);
        }

        return (int)ans;
    }
};