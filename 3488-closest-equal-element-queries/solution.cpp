#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> closestEqualElement(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        // Map each value to a list of indices where it appears
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; ++i) {
            groups[nums[i]].push_back(i);
        }

        // Pre-calculate minimum distance for every index
        vector<int> min_dists(n, -1);
        for (auto& [val, pos] : groups) {
            int k = pos.size();
            if (k < 2) continue; // Unique element has no equal counterpart

            // The circular distance between the first and last occurrence
            int wrap_dist = n - (pos[k - 1] - pos[0]);

            for (int i = 0; i < k; ++i) {
                int dist_prev, dist_next;

                // Distance to the neighbor on the left
                if (i == 0) dist_prev = wrap_dist;
                else dist_prev = pos[i] - pos[i - 1];

                // Distance to the neighbor on the right
                if (i == k - 1) dist_next = wrap_dist;
                else dist_next = pos[i + 1] - pos[i];

                min_dists[pos[i]] = min(dist_prev, dist_next);
            }
        }

        // Answer queries from pre-calculated data
        vector<int> results;
        results.reserve(queries.size());
        for (int q : queries) {
            results.push_back(min_dists[q]);
        }

        return results;
    }
};