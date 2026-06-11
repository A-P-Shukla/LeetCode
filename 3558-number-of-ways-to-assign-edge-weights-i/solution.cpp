#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Modular exponentiation to calculate 2^(L-1) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        long long mod = 1e9 + 7;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    int countWays(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int max_depth = 0;
        // DFS to find the maximum depth of the tree
        auto dfs = [&](auto self, int u, int p, int d) -> void {
            max_depth = max(max_depth, d);
            for (int v : adj[u]) {
                if (v != p) {
                    self(self, v, u, d + 1);
                }
            }
        };

        dfs(dfs, 1, -1, 0);

        // The number of ways to get an odd sum with L edges is 2^(L-1)
        return (int)power(2, max_depth - 1);
    }
};