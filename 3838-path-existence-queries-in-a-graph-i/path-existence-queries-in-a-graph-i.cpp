class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component_id(n);
        int current_id = 0;
        
        component_id[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                current_id++;
            }
            component_id[i] = current_id;
        }
        
        vector<bool> results;
        results.reserve(queries.size());
        
        for (const auto& query : queries) {
            results.push_back(component_id[query[0]] == component_id[query[1]]);
        }
        
        return results;
    }
};