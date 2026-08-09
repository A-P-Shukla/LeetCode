#include <vector>
#include <algorithm>

class Solution {
public:
    int stoneGameII(std::vector<int>& piles) {
        int n = piles.size();
        
        // Compute suffix sums: suffixSum[i] holds the total stones from piles[i] to piles[n-1]
        std::vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // Memoization table initialized to 0
        std::vector<std::vector<int>> memo(n + 1, std::vector<int>(n + 1, 0));

        // Recursive helper function using lambda for state (i, M)
        auto dp = [&](auto& self, int i, int M) -> int {
            // Base case: if remaining piles can all be taken, take all
            if (i + 2 * M >= n) {
                return suffixSum[i];
            }
            
            // Return cached result if available
            if (memo[i][M] != 0) {
                return memo[i][M];
            }

            int maxStones = 0;
            // Try taking X piles where 1 <= X <= 2 * M
            for (int X = 1; X <= 2 * M; ++X) {
                // Stones current player gets = total remaining stones - optimal stones opponent gets next
                int currentOption = suffixSum[i] - self(self, i + X, std::max(M, X));
                maxStones = std::max(maxStones, currentOption);
            }

            return memo[i][M] = maxStones;
        };

        return dp(dp, 0, 1);
    }
};