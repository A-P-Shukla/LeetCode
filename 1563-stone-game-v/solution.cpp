#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int stoneGameV(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        std::vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }

        std::vector<std::vector<int>> memo(n, std::vector<int>(n, -1));

        auto getSum = [&](int l, int r) {
            return prefixSum[r + 1] - prefixSum[l];
        };

        auto solve = [&](auto& self, int i, int j) -> int {
            if (i == j) {
                return 0;
            }
            if (memo[i][j] != -1) {
                return memo[i][j];
            }

            int maxScore = 0;
            for (int k = i; k < j; ++k) {
                int leftSum = getSum(i, k);
                int rightSum = getSum(k + 1, j);

                if (leftSum < rightSum) {
                    maxScore = std::max(maxScore, leftSum + self(self, i, k));
                } else if (leftSum > rightSum) {
                    maxScore = std::max(maxScore, rightSum + self(self, k + 1, j));
                } else {
                    int takeLeft = leftSum + self(self, i, k);
                    int takeRight = rightSum + self(self, k + 1, j);
                    maxScore = std::max({maxScore, takeLeft, takeRight});
                }
            }

            return memo[i][j] = maxScore;
        };

        return solve(solve, 0, n - 1);
    }
};