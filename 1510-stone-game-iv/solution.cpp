#include <vector>

class Solution {
public:
    bool winnerSquareGame(int n) {
        // dp[i] will store whether the current player can win with i stones remaining
        std::vector<bool> dp(n + 1, false);
        
        for (int i = 1; i <= n; ++i) {
            // Try all possible square numbers k^2 <= i
            for (int k = 1; k * k <= i; ++k) {
                // If removing k^2 stones leaves the next player in a losing state,
                // then the current player wins from state i.
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; // No need to check further moves for state i
                }
            }
        }
        
        return dp[n];
    }
};