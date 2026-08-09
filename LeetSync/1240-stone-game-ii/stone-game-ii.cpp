class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));

        auto dp = [&](auto& self, int i, int M) -> int {
            if (i + 2 * M >= n) {
                return suffixSum[i];
            }
            
            if (memo[i][M] != 0) {
                return memo[i][M];
            }

            int maxStones = 0;
            for (int X = 1; X <= 2 * M; ++X) {
                int currentOption = suffixSum[i] - self(self, i + X, std::max(M, X));
                maxStones = max(maxStones, currentOption);
            }

            return memo[i][M] = maxStones;
        };

        return dp(dp, 0, 1);
    }
};