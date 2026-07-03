#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
    struct Edge {
        int to;
        long long cost;
    };

    bool canReach(int n, const vector<vector<Edge>>& adj, const vector<bool>& online, long long k, int min_threshold) {
        // shortest_path[i] stores the minimum cost to reach node i from 0
        vector<long long> dist(n, -1);
        dist[0] = 0;

        // Since it's a DAG, we can process nodes in topological order.
        // However, Dijkstra is more robust and fits well here.
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u] && dist[u] != -1) continue;
            if (u == n - 1) return d <= k;

            for (auto& edge : adj[u]) {
                if (edge.cost >= min_threshold && (edge.to == n - 1 || online[edge.to])) {
                    if (dist[edge.to] == -1 || dist[edge.to] > d + edge.cost) {
                        dist[edge.to] = d + edge.cost;
                        pq.push({dist[edge.to], edge.to});
                    }
                }
            }
        }
        return false;
    }

public:
    int solve(int n, vector<vector<int>>& edges, vector<bool>& online, long long k) {
        vector<vector<Edge>> adj(n);
        int max_val = 0;
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], (long long)e[2]});
            max_val = max(max_val, e[2]);
        }

        int low = 0, high = max_val, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canReach(n, adj, online, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};