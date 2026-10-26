#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<char> visited(m * n, 0);
        auto idx = [n](int r, int c) { return r * n + c; };
        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};

        int answer = 0;
        queue<pair<int,int>> q;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0 || visited[idx(r,c)]) continue;

                long long sum = 0;
                q.emplace(r, c);
                visited[idx(r,c)] = 1;

                while (!q.empty()) {
                    auto [cr, cc] = q.front(); q.pop();
                    sum += grid[cr][cc];

                    for (int d = 0; d < 4; ++d) {
                        int nr = cr + dr[d];
                        int nc = cc + dc[d];
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                        if (grid[nr][nc] == 0) continue;
                        int id = idx(nr, nc);
                        if (visited[id]) continue;
                        visited[id] = 1;
                        q.emplace(nr, nc);
                    }
                }

                if (sum % k == 0) ++answer;
            }
        }
        return answer;
    }
};