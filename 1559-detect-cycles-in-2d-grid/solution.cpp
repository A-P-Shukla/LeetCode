#include <vector>

using namespace std;

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        
        // Helper function for DFS
        auto dfs = [&](auto self, int r, int c, int pr, int pc, char target) -> bool {
            visited[r][c] = true;
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                // Boundary and character match check
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == target) {
                    // If neighbor is visited and is NOT the parent, cycle detected
                    if (visited[nr][nc]) {
                        if (nr != pr || nc != pc) return true;
                    } else {
                        if (self(self, nr, nc, r, c, target)) return true;
                    }
                }
            }
            return false;
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    // Start DFS for each unvisited component
                    if (dfs(dfs, i, j, -1, -1, grid[i][j])) return true;
                }
            }
        }
        
        return false;
    }
};