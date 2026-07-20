class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        k %= total;
        
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int old_idx = i * n + j;
                int new_idx = (old_idx + k) % total;
                
                int new_i = new_idx / n;
                int new_j = new_idx % n;
                
                result[new_i][new_j] = grid[i][j];
            }
        }
        
        return result;
    }
};