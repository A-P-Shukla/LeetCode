class Solution {
    struct State {
        int r, c;
        int mask;
        int e;
        int steps;
    };

public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int start_r = -1, start_c = -1;
        vector<pair<int, int>> litters;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    start_r = r;
                    start_c = c;
                } else if (classroom[r][c] == 'L') {
                    litters.push_back({r, c});
                }
            }
        }

        int num_litter = litters.size();
        if (num_litter == 0) return 0;

        int target_mask = (1 << num_litter) - 1;

        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        for (int i = 0; i < num_litter; ++i) {
            litter_id[litters[i].first][litters[i].second] = i;
        }

        vector<vector<vector<int>>> max_energy(
            m, vector<vector<int>>(n, vector<int>(1 << num_litter, -1))
        );

        queue<State> q;
        q.push({start_r, start_c, 0, energy, 0});
        max_energy[start_r][start_c][0] = energy;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            State curr = q.front();
            q.pop();

            if (curr.e == 0) continue;

            for (auto& d : dirs) {
                int nr = curr.r + d[0];
                int nc = curr.c + d[1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    char cell = classroom[nr][nc];
                    if (cell == 'X') continue;

                    int ne = curr.e - 1;
                    if (cell == 'R') {
                        ne = energy; 
                    }

                    int nmask = curr.mask;
                    if (cell == 'L') {
                        nmask |= (1 << litter_id[nr][nc]);
                    }

                    if (nmask == target_mask) {
                        return curr.steps + 1;
                    }

                    if (ne > 0 && ne > max_energy[nr][nc][nmask]) {
                        max_energy[nr][nc][nmask] = ne;
                        q.push({nr, nc, nmask, ne, curr.steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};