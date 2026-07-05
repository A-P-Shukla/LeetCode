#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        // dp[r][c] stores {max_sum, number_of_ways}
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        
        // Starting from bottom-right (S)
        dp[n - 1][n - 1] = {0, 1};
        
        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (board[r][c] == 'X' || (r == n - 1 && c == n - 1)) continue;
                
                int max_s = -1;
                int paths = 0;
                
                // Possible moves: Up (r-1, c), Left (r, c-1), Up-Left (r-1, c-1)
                // From current (r, c), check neighbors to move to (r+1, c), (r, c+1), (r+1, c+1)
                int dr[] = {0, 1, 1};
                int dc[] = {1, 0, 1};
                
                for (int i = 0; i < 3; ++i) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (nr < n && nc < n && dp[nr][nc].first != -1) {
                        if (dp[nr][nc].first > max_s) {
                            max_s = dp[nr][nc].first;
                            paths = dp[nr][nc].second;
                        } else if (dp[nr][nc].first == max_s) {
                            paths = (paths + dp[nr][nc].second) % MOD;
                        }
                    }
                }
                
                if (max_s != -1) {
                    int val = (board[r][c] == 'E') ? 0 : (board[r][c] - '0');
                    dp[r][c] = {max_s + val, paths};
                }
            }
        }
        
        return dp[0][0].first == -1 ? vector<int>{0, 0} : vector<int>{dp[0][0].first, dp[0][0].second};
    }
};