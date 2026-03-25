class Solution {
public:
    bool equalSumPartition(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long totalSum = 0;

        // Calculate the total sum of the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                totalSum += grid[i][j];
            }
        }

        // If the total sum is odd, we cannot split it into two equal integer sums
        if (totalSum % 2 != 0) {
            return false;
        }

        long long target = totalSum / 2;

        // Check for Horizontal Cuts
        // We sum row by row and see if we hit exactly half the total sum
        long long horizontalRunningSum = 0;
        for (int i = 0; i < m - 1; ++i) { // m-1 because sections must be non-empty
            for (int j = 0; j < n; ++j) {
                horizontalRunningSum += grid[i][j];
            }
            if (horizontalRunningSum == target) {
                return true;
            }
        }

        // Check for Vertical Cuts
        // We calculate column sums first to iterate through them efficiently
        vector<long long> colSums(n, 0);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                colSums[j] += grid[i][j];
            }
        }

        long long verticalRunningSum = 0;
        for (int j = 0; j < n - 1; ++j) { // n-1 because sections must be non-empty
            verticalRunningSum += colSums[j];
            if (verticalRunningSum == target) {
                return true;
            }
        }

        return false;
    }
};