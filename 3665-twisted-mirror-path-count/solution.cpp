#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr int MOD = 1'000'000'007;
    int m, n;
    vector<vector<int>> grid;
    // memo[i][j][dir] = pair<ni,nj> or {-1,-1} if invalid, dir:0=right,1=down
    vector<vector<array<pair<int,int>,2>>> memo;
    pair<int,int> resolve(int i, int j, int dir) {
        auto &res = memo[i][j][dir];
        if (res.first != -2) return res; // already computed
        // attempt one step in current direction
        int ni = i + (dir==1);        // down adds 1 to row
        int nj = j + (dir==0);        // right adds 1 to col
        if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
            res = {-1,-1};
            return res;
        }
        if (grid[ni][nj] == 0) {     // empty cell -> landing here
            res = {ni, nj};
            return res;
        }
        // mirror encountered: reflect direction and continue from that mirror cell
        res = resolve(ni, nj, 1-dir);
        return res;
    }
public:
    int twistedMirrorPathCount(vector<vector<int>>& grid_) {
        grid = grid_;
        m = grid.size();
        n = grid[0].size();
        memo.assign(m, vector<array<pair<int,int>,2>>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                for (int d = 0; d < 2; ++d)
                    memo[i][j][d] = {-2,-2}; // sentinel for "uncomputed"
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;
                // move right
                auto r = resolve(i, j, 0);
                if (r.first != -1) {
                    long long val = dp[i][j];
                    dp[r.first][r.second] = (dp[r.first][r.second] + val) % MOD;
                }
                // move down
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