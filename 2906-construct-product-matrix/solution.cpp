class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;
        
        vector<vector<int>> p(n, vector<int>(m));
        long long runningProduct = 1;

        // Forward pass: Calculate prefix products
        // p[i][j] will store the product of all elements before grid[i][j] in row-major order
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[i][j] = runningProduct;
                runningProduct = (runningProduct * (grid[i][j] % MOD)) % MOD;
            }
        }

        // Backward pass: Calculate suffix products and multiply with existing prefix products
        runningProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                // Multiply current prefix product by the suffix product accumulated so far
                p[i][j] = (p[i][j] * runningProduct) % MOD;
                // Update the suffix product for the next element
                runningProduct = (runningProduct * (grid[i][j] % MOD)) % MOD;
            }
        }

        return p;
    }
};