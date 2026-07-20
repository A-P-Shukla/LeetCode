#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        // Effective shifts needed
        k %= total;
        
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Calculate flattened index
                int old_idx = i * n + j;
                // Calculate new flattened index after k shifts
                int new_idx = (old_idx + k) % total;
                
                // Map new flattened index back to 2D coordinates
                int new_i = new_idx / n;
                int new_j = new_idx % n;
                
                result[new_i][new_j] = grid[i][j];
            }
        }
        
        return result;
    }
};