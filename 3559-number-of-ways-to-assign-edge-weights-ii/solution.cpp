#include <vector>
#include <cmath>

using namespace std;

class Solution {
    int n;
    int LOG;
    vector<vector<int>> up;
    vector<int> depth;
    const int MOD = 1e9 + 7;

    void dfs(int u, int p, int d, const vector<vector<int>>& adj) {
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < LOG; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (int v : adj[u]) {
            if (v != p) dfs(v, u, d + 1, adj);
        }
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = LOG - 1; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) u = up[u][i];
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    vector<int> countWays(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        this->n = n;
        this->LOG = ceil(log2(n + 1));
        up.assign(n + 1, vector<int>(LOG, 1));
        depth.assign(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(1, 1, 0, adj);

        vector<int> results;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                results.push_back(0);
            } else {
                int lca = get_lca(u, v);
                int dist = depth[u] + depth[v] - 2 * depth[lca];
                results.push_back(power(2, dist - 1));
            }
        }
        return results;
    }
};