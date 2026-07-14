class Solution {
    long long memo[201][201][201];
    int n;
    const int MOD = 1e9 + 7;

    long long solve(int idx, int g1, int g2, const vector<int>& nums) {
        if (idx == n) {
            return (g1 > 0 && g1 == g2) ? 1 : 0;
        }
        if (memo[idx][g1][g2] != -1) return memo[idx][g1][g2];

        long long res = solve(idx + 1, g1, g2, nums);

        res = (res + solve(idx + 1, g1 == 0 ? nums[idx] : gcd(g1, nums[idx]), g2, nums)) % MOD;

        res = (res + solve(idx + 1, g1, g2 == 0 ? nums[idx] : gcd(g2, nums[idx]), nums)) % MOD;

        return memo[idx][g1][g2] = res;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(memo, -1, sizeof(memo));
        return (int)solve(0, 0, 0, nums);
    }
};