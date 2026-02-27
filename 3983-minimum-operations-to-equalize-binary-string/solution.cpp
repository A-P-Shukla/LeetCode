#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int initial_zeros = 0;
        for (char c : s) {
            if (c == '0') initial_zeros++;
        }

        // Target reached immediately
        if (initial_zeros == 0) return 0;

        // BFS distance array: dist[i] is min ops to have i zeros
        vector<int> dist(n + 1, -1);
        // DSU to skip visited nodes. 
        // parent[i] points to the next unvisited node with the same parity as i.
        vector<int> parent(n + 3);
        for (int i = 0; i <= n + 2; ++i) {
            parent[i] = i;
        }

        // Standard iterative DSU find with path compression
        auto find = [&](auto self, int i) -> int {
            if (parent[i] == i) return i;
            return parent[i] = self(self, parent[i]);
        };

        queue<int> q;
        dist[initial_zeros] = 0;
        q.push(initial_zeros);
        
        // Mark initial state as visited in the DSU
        parent[initial_zeros] = find(find, initial_zeros + 2);

        while (!q.empty()) {
            int z = q.front();
            q.pop();

            // Range of reachable next counts of zeros
            int L = abs(z - k);
            int R = min(z + k, 2 * n - z - k);

            // Visit all unvisited states in range [L, R] with same parity as (z + k)
            // find(L) starts at the first unvisited index >= L with correct parity
            for (int i = find(find, L); i <= R; i = find(find, i)) {
                dist[i] = dist[z] + 1;
                
                // Found the target (0 zeros)
                if (i == 0) return dist[i];
                
                q.push(i);
                // Mark current index as visited by linking it to the next candidate
                parent[i] = find(find, i + 2);
            }
        }

        return dist[0];
    }
};
---CODE_END---