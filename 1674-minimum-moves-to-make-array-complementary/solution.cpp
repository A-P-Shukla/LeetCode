#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        // diff[i] stores the difference in moves required for target sum i.
        // The range of possible sums is [2, 2 * limit].
        vector<int> diff(2 * limit + 2, 0);
        int n = nums.size();

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            // For a target sum S in [2, 2 * limit]:
            // 1. Default: 2 moves for every pair.
            // 2. 1 move if min(a, b) + 1 <= S <= max(a, b) + limit.
            // 3. 0 moves if S == a + b.

            int min_val = min(a, b);
            int max_val = max(a, b);

            // Initially, assume 2 moves for the entire range [2, 2 * limit]
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // Range [min_val + 1, max_val + limit] only needs 1 move (subtract 1 from 2)
            diff[min_val + 1] -= 1;
            diff[max_val + limit + 1] += 1;

            // Point S = a + b needs 0 moves (subtract another 1 from 1)
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int min_moves = n; // Max possible moves is n
        int current_moves = 0;
        // Traverse the difference array to find the minimum prefix sum
        for (int i = 2; i <= 2 * limit; ++i) {
            current_moves += diff[i];
            min_moves = min(min_moves, current_moves);
        }

        return min_moves;
    }
};