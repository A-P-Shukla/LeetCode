#include <vector>
#include <deque>
#include <climits>

using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // min_lost[i][j] stores the minimum unsafe cells encountered to reach (i, j)
        vector<vector<int>> min_lost(m, vector<int>(n, INT_MAX));
        
        // Use deque for 0-1 BFS
        deque<pair<int, int>> dq;
        
        int start_cost = grid[0][0];
        if (start_cost >= health) return false;
        
        min_lost[0][0] = start_cost;
        dq.push_front({0, 0});
        
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int next_cost = min_lost[r][c] + grid[nr][nc];
                    
                    if (next_cost < health && next_cost < min_lost[nr][nc]) {
                        min_lost[nr][nc] = next_cost;
                        if (grid[nr][nc] == 0) {
                            dq.push_front({nr, nc});
                        } else {
                            dq.push_back({nr, nc});
                        }
                    }
                }
            }
        }
        
        return min_lost[m - 1][n - 1] < health;
    }
};