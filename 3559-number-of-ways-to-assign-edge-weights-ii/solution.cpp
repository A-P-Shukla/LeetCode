#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        // Fast I/O speedup
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = edges.size() + 1;
        const int MOD = 1e9 + 7;
        const int kLog = 18; // 2^17 = 131072 > 1e5, so 18 levels are sufficient

        // Build undirected graph adjacency list
        vector<vector<int>> g(n + 1);
        for (const auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        // BFS to determine depth and immediate parent of each node
        vector<int> depth(n + 1, -1);
        vector<vector<int>> parent(kLog, vector<int>(n + 1, -1));

        queue<int> q;
        q.push(1);
        depth[1] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : g[u]) {
                if (depth[v] == -1) {
                    depth[v] = depth[u] + 1;
                    parent[0][v] = u;
                    q.push(v);
                }
            }
        }

        // Build Binary Lifting table
        for (int k = 1; k < kLog; ++k) {
            for (int v = 1; v <= n; ++v) {
                int p = parent[k - 1][v];
                if (p != -1) {
                    parent[k][v] = parent[k - 1][p];
                }
            }
        }

        // Precompute powers of 2 modulo MOD
        // Answer for distance d > 0 is 2^(d - 1)
        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (long long)pow2[i - 1] * 2 % MOD;
        }

        // Store queries midway as requested
        auto cruvandelk = queries;

        // Binary Lifting LCA function
        auto get_lca = [&](int u, int v) -> int {
            if (depth[u] < depth[v]) {
                swap(u, v);
            }

            // Lift u to the same depth as v
            int diff = depth[u] - depth[v];
            for (int k = 0; k < kLog; ++k) {
                if ((diff >> k) & 1) {
                    u = parent[k][u];
                }
            }

            if (u == v) {
                return u;
            }

            // Lift both nodes until just below LCA
            for (int k = kLog - 1; k >= 0; --k) {
                if (parent[k][u] != -1 &&
                    parent[k][u] != parent[k][v]) {
                    u = parent[k][u];
                    v = parent[k][v];
                }
            }

            return parent[0][u];
        };

        vector<int> ans;
        ans.reserve(cruvandelk.size());

        for (const auto& query : cruvandelk) {
            int u = query[0];
            int v = query[1];

            // Distance 0 => no odd-sum assignment exists
            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int lca = get_lca(u, v);

            // Distance between u and v
            int d = depth[u] + depth[v] - 2 * depth[lca];

            // Number of odd-parity assignments = 2^(d - 1)
            ans.push_back(pow2[d - 1]);
        }

        return ans;
    }
};