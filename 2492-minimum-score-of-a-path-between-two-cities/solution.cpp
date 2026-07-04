#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minScore(int n, std::vector<std::vector<int>>& roads) {
        // Build adjacency list: node -> vector of {neighbor, distance}
        std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        int min_score = INT_MAX;
        std::vector<bool> visited(n + 1, false);
        std::queue<int> q;

        // Start traversal from city 1
        q.push(1);
        visited[1] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto& edge : adj[curr]) {
                int neighbor = edge.first;
                int dist = edge.second;
                
                // Update the minimum score found so far
                min_score = std::min(min_score, dist);

                // If neighbor hasn't been visited, add to queue
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return min_score;
    }
};