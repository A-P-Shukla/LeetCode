#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> result(n, 0);
        unordered_map<int, vector<int>> groups;

        // Group indices by their values
        for (int i = 0; i < n; ++i) {
            groups[nums[i]].push_back(i);
        }

        // Process each group of indices
        for (auto const& [val, indices] : groups) {
            int k = indices.size();
            if (k <= 1) continue;

            // Calculate total sum of indices for suffix calculations
            long long total_sum = 0;
            for (int idx : indices) {
                total_sum += idx;
            }

            long long left_sum = 0;
            for (int m = 0; m < k; ++m) {
                long long current_idx = indices[m];
                
                // Indices to the left: m elements
                // Indices to the right: (k - 1 - m) elements
                long long right_sum = total_sum - left_sum - current_idx;
                
                long long left_part = (long long)m * current_idx - left_sum;
                long long right_part = right_sum - (long long)(k - 1 - m) * current_idx;
                
                result[current_idx] = left_part + right_part;
                
                left_sum += current_idx;
            }
        }

        return result;
    }
};