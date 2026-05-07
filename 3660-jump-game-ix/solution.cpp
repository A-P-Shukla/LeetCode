#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxReachableValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        // Step 1: Precompute Prefix Maximums.
        // P[i] is the maximum value in nums[0...i].
        // Any index i can always reach P[i] by jumping to a larger element on its left.
        vector<int> P(n);
        P[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            P[i] = max(P[i - 1], nums[i]);
        }

        // Step 2: Use Coordinate Compression to handle values up to 10^9.
        vector<int> sorted_unique = nums;
        sort(sorted_unique.begin(), sorted_unique.end());
        sorted_unique.erase(unique(sorted_unique.begin(), sorted_unique.end()), sorted_unique.end());

        // Step 3: Find the rightmost occurrence of each unique value.
        int m = sorted_unique.size();
        vector<int> last_pos(m, -1);
        for (int i = 0; i < n; ++i) {
            int val_idx = lower_bound(sorted_unique.begin(), sorted_unique.end(), nums[i]) - sorted_unique.begin();
            last_pos[val_idx] = i;
        }

        // Step 4: Compute a prefix maximum of the rightmost indices.
        // running_max_idx[k] = max(last_pos[0...k]).
        // This gives the rightmost index of any value <= sorted_unique[k].
        vector<int> running_max_idx(m);
        running_max_idx[0] = last_pos[0];
        for (int i = 1; i < m; ++i) {
            running_max_idx[i] = max(running_max_idx[i - 1], last_pos[i]);
        }

        // Step 5: For each index, find the rightmost reachable index and return its prefix max.
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            // Find the largest value strictly smaller than nums[i].
            auto it = lower_bound(sorted_unique.begin(), sorted_unique.end(), nums[i]);
            int j_max = -1;
            if (it != sorted_unique.begin()) {
                int smaller_val_idx = distance(sorted_unique.begin(), it) - 1;
                j_max = running_max_idx[smaller_val_idx];
            }
            
            // The maximum value reachable is the prefix max at the furthest reachable point.
            // If j_max > i, we can reach P[j_max]. Otherwise, we reach P[i].
            ans[i] = P[max(i, j_max)];
        }

        return ans;
    }
};