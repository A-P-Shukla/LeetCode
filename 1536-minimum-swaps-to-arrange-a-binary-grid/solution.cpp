class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeros(n, 0);

        // Precompute trailing zeros for each row
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) {
                    count++;
                } else {
                    break;
                }
            }
            trailingZeros[i] = count;
        }

        int totalSwaps = 0;
        for (int i = 0; i < n; ++i) {
            // Requirement for row i: at least (n - 1 - i) trailing zeros
            int required = n - 1 - i;
            int foundIdx = -1;

            // Find the first row that satisfies the requirement
            for (int j = i; j < n; ++j) {
                if (trailingZeros[j] >= required) {
                    foundIdx = j;
                    break;
                }
            }

            // If no such row is found, it's impossible
            if (foundIdx == -1) return -1;

            // Move the found row to position i using adjacent swaps
            totalSwaps += (foundIdx - i);
            
            // Simulating the swaps by shifting the values in our count array
            int val = trailingZeros[foundIdx];
            for (int k = foundIdx; k > i; --k) {
                trailingZeros[k] = trailingZeros[k - 1];
            }
            trailingZeros[i] = val;
        }

        return totalSwaps;
    }
};