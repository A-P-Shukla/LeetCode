class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        // prefixSum[i][j] will store the sum of the submatrix from (0,0) to (i,j)
        // Using long long for the prefix sum matrix to prevent overflow,
        // although based on constraints (1000*1000*1000), int (up to 2*10^9) would suffice.
        vector<vector<int>> prefixSum(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int currentVal = grid[i][j];
                int top = (i > 0) ? prefixSum[i - 1][j] : 0;
                int left = (j > 0) ? prefixSum[i][j - 1] : 0;
                int topLeft = (i > 0 && j > 0) ? prefixSum[i - 1][j - 1] : 0;
                
                prefixSum[i][j] = currentVal + top + left - topLeft;
                
                // If current prefix sum is within k, it's a valid submatrix
                if (prefixSum[i][j] <= k) {
                    count++;
                } else {
                    // Optimization: Since grid elements are non-negative,
                    // if prefixSum[i][j] > k, then prefixSum[i][j+1...n-1] will also be > k.
                    break;
                }
            }
        }
        
        return count;
    }
};