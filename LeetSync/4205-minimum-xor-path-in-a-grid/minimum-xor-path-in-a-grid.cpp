class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int MAXX = 1024;                     
        int m = grid.size(), n = grid[0].size();

        vector<vector<bitset<MAXX>>> dp(m, vector<bitset<MAXX>>(n));

        dp[0][0].set(grid[0][0]);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;    

                bitset<MAXX> cur;
                if (i > 0) {
                    const bitset<MAXX>& up = dp[i-1][j];
                    for (int v = 0; v < MAXX; ++v) {
                        if (up.test(v))
                            cur.set(v ^ grid[i][j]);
                    }
                }
                if (j > 0) {
                    const bitset<MAXX>& left = dp[i][j-1];
                    for (int v = 0; v < MAXX; ++v) {
                        if (left.test(v))
                            cur.set(v ^ grid[i][j]);
                    }
                }
                dp[i][j] = cur;
            }
        }

        const bitset<MAXX>& fin = dp[m-1][n-1];
        for (int v = 0; v < MAXX; ++v) {
            if (fin.test(v)) return v;              
        }
        return -1; 
    }
};