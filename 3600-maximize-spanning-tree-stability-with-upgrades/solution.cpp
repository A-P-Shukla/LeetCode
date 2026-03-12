#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, s;
};

class Solution {
private:
    struct DSU {
        vector<int> parent;
        vector<int> rank;
        int comps;
        DSU(int n) : parent(n), rank(n, 0), comps(n) {
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int i) {
            while (parent[i] != i) {
                parent[i] = parent[parent[i]]; // Path halving
                i = parent[i];
            }
            return i;
        }
        bool unite(int i, int j) {
            int r_i = find(i), r_j = find(j);
            if (r_i != r_j) {
                if (rank[r_i] < rank[r_j]) swap(r_i, r_j);
                parent[r_j] = r_i;
                if (rank[r_i] == rank[r_j]) rank[r_i]++;
                comps--;
                return true;
            }
            return false;
        }
    };

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<Edge> mustEdges, optEdges;
        for (const auto& e : edges) {
            if (e[3] == 1) {
                mustEdges.push_back({e[0], e[1], e[2]});
            } else {
                optEdges.push_back({e[0], e[1], e[2]});
            }
        }

        // Pre-check: Mandatory edges must not form a cycle
        DSU base_dsu(n);
        for (const auto& e : mustEdges) {
            if (!base_dsu.unite(e.u, e.v)) return -1;
        }

        auto check = [&](int X) {
            // Check if all mandatory edges meet the threshold
            for (const auto& e : mustEdges) {
                if (e.s < X) return false;
            }
            
            // Start from the state defined by mandatory edges
            DSU dsu = base_dsu;
            int upgradesUsed = 0;

            // Greedily use optional edges that don't need upgrades (Type A)
            for (const auto& e : optEdges) {
                if (e.s >= X) {
                    dsu.unite(e.u, e.v);
                }
            }

            // Greedily use optional edges that DO need upgrades (Type B)
            for (const auto& e : optEdges) {
                if (e.s < X && 2 * e.s >= X) {
                    if (dsu.unite(e.u, e.v)) {
                        upgradesUsed++;
                    }
                }
            }

            // Threshold is achievable if graph is connected and upgrades are within budget
            return dsu.comps == 1 && upgradesUsed <= k;
        };

        int low = 1, high = 200000, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
