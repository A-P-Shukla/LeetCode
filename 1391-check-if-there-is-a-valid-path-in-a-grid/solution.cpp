#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
    // Mapping each street type to the directions it connects
    // Directions: {row_offset, col_offset}
    vector<vector<pair<int, int>>> directions = {
        {}, // Padding for 0-index
        {{0, -1}, {0, 1}},  // 1: left, right
        {{-1, 0}, {1, 0}},  // 2: upper, lower
        {{0, -1}, {1, 0}},  // 3: left, lower
        {{0, 1}, {1, 0}},   // 4: right, lower
        {{0, -1}, {-1, 0}}, // 5: left, upper
        {{0, 1}, {-1, 0}}   // 6: right, upper
    };

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == m - 1 && c == n - 1) return true;
            
            int streetType = grid[r][c];
            for (auto& dir : directions[streetType]) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                
                // Check bounds and if visited
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int nextStreetType = grid[nr][nc];
                    bool backConnect = false;
                    
                    // The neighbor must have a connection back to the current cell
                    // i.e., it must contain the direction (-dir.first, -dir.second)
                    for (auto& backDir : directions[nextStreetType]) {
                        if (backDir.first == -dir.first && backDir.second == -dir.second) {
                            backConnect = true;
                            break;
                        }
                    }
                    
                    if (backConnect) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        return false;
    }
};