#include <vector>
#include <queue>
#include <numeric>

class Solution {
public:
    std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) {
        // Step 1: Build the directed graph
        std::vector<std::vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }
        
        // Step 2: BFS to mark all suspicious methods reachable from 'k'
        std::vector<bool> is_suspicious(n, false);
        std::queue<int> q;
        
        q.push(k);
        is_suspicious[k] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (!is_suspicious[v]) {
                    is_suspicious[v] = true;
                    q.push(v);
                }
            }
        }
        
        // Step 3: Check if any non-suspicious method invokes a suspicious method
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            if (!is_suspicious[u] && is_suspicious[v]) {
                // Removal is impossible; return all methods
                std::vector<int> all_methods(n);
                std::iota(all_methods.begin(), all_methods.end(), 0);
                return all_methods;
            }
        }
        
        // Step 4: Collect all non-suspicious methods
        std::vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!is_suspicious[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};