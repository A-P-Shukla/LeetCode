class Solution {
    static constexpr int MOD = 1'000'000'007;
    int m, n;
    vector<vector<int>> grid;
    vector<vector<array<pair<int,int>,2>>> memo;
    pair<int,int> resolve(int i, int j, int dir) {
        auto &res = memo[i][j][dir];
        if (res.first != -2) return res; 
        int ni = i + (dir==1);
        int nj = j + (dir==0);        
        if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
            res = {-1,-1};
            return res;
        }
        if (grid[ni][nj] == 0) {     
            res = {ni, nj};
            return res;
        }
        res = resolve(ni, nj, 1-dir);
        return res;
    }
public:
    int uniquePaths(vector<vector<int>>& grid_) {
        grid = grid_;
        m = grid.size();
        n = grid[0].size();
        memo.assign(m, vector<array<pair<int,int>,2>>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                for (int d = 0; d < 2; ++d)
                    memo[i][j][d] = {-2,-2}; 
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;

                auto r = resolve(i, j, 0);
                if (r.first != -1) {
                    long long val = dp[i][j];
                    dp[r.first][r.second] = (dp[r.first][r.second] + val) % MOD;
                }

                auto d = resolve(i, j, 1);
                if (d.first != -1) {
                    long long val = dp[i][j];
                    dp[d.first][d.second] = (dp[d.first][d.second] + val) % MOD;
                }
            }
        }
        return dp[m-1][n-1];
    }
};