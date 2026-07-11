#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);

                // Count vertices and edges in this component
                long long v_count = component.size();
                long long e_count = 0;
                for (int node : component) {
                    e_count += adj[node].size();
                }
                // Each edge is counted twice in adjacency list
                e_count /= 2;

                // A complete graph with V vertices has V * (V - 1) / 2 edges
                if (e_count == v_count * (v_count - 1) / 2) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }

private:
    void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
        visited[u] = true;
        component.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited, component);
            }
        }
    }
};