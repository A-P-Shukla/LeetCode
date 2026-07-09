#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> pathExistence(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // component_id[i] will store the ID of the connected component node i belongs to
        vector<int> component_id(n);
        int current_id = 0;
        
        component_id[0] = 0;
        for (int i = 1; i < n; ++i) {
            // If the difference exceeds maxDiff, we start a new component
            if (nums[i] - nums[i - 1] > maxDiff) {
                current_id++;
            }
            component_id[i] = current_id;
        }
        
        vector<bool> results;
        results.reserve(queries.size());
        
        // Two nodes are connected if they belong to the same component
        for (const auto& query : queries) {
            results.push_back(component_id[query[0]] == component_id[query[1]]);
        }
        
        return results;
    }
};